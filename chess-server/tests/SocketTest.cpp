#include <gtest/gtest.h>
#include <thread>

#if defined (_WIN32)
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "types.h"
#endif

#include "Socket.h"


namespace {

void connectToServer(const std::string& server, uint16_t port, SOCKET& sockfd) {
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd != INVALID_SOCKET) {
        struct sockaddr_in address;
        memset(&address, 0, sizeof(address));
        address.sin_family = AF_INET;
        inet_pton(AF_INET, server.c_str(), &address.sin_addr.s_addr);
        address.sin_port = htons(port);
        if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
            FAIL() << "Can not connect to server";
        }
    }
}

}

TEST(SocketTest, bind)
{
    Socket socket;
    try {
        socket.bind(21);
        FAIL() << "Can not bind 21 port. Exception needed!";
    } catch (...) {
    }

    socket.bind(1111);
}

TEST(SocketTest, accept)
{
    Socket socket;
    try {
        socket.accept();
        FAIL() << "You need to bind socket to accept";
    } catch (...) {
    }

    socket.bind(1112);
    socket.listen();

    SOCKET newSocket = 0;
    std::thread thread(connectToServer, "127.0.0.1", 1112, std::ref(newSocket));
    socket.accept();
    thread.join();
    ASSERT_TRUE(newSocket != INVALID_SOCKET);
}

TEST(SocketTest, write)
{
    Socket socket;
    socket.bind(1113);
    socket.listen();

    SOCKET remoteSocket;
    std::thread thread(connectToServer, "127.0.0.1", 1113, std::ref(remoteSocket));
    Socket newSocket = socket.accept();
    int bytesWritten = newSocket.write("Hello");
    thread.join();
    closesocket(remoteSocket);
    ASSERT_EQ(5, bytesWritten);
}

TEST(SocketTest, read)
{
    Socket socket;
    socket.bind(1114);
    socket.listen();

    SOCKET remoteSocket;
    std::thread thread(connectToServer, "127.0.0.1", 1114, std::ref(remoteSocket));
    Socket newSocket = socket.accept();
    int bytesWritten = send(remoteSocket, "!Hello", 6, 0);
    thread.join();
    closesocket(remoteSocket);
    ASSERT_EQ(6, bytesWritten);
    std::string buffer = newSocket.read(1);
    ASSERT_EQ(1, buffer.size());
    ASSERT_EQ("!", buffer);
    buffer = newSocket.read();
    ASSERT_EQ(5, buffer.size());
    ASSERT_EQ("Hello", buffer);

    newSocket.close();
    try {
        newSocket.read();
        FAIL() << "We need read exception";
    } catch (...) {
    }
}
