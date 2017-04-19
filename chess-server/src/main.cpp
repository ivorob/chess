#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
#include "Socket.h"

namespace {

void
usage(const std::string& appName)
{
    std::cerr << "usage:" << std::endl
              << "\t" << appName << " port" << std::endl;
}

std::thread waitingThread;
Socket socket2(INVALID_SOCKET);

void
GameWorker(Socket socket1)
{
    std::cout << "Start GameWorker" << std::endl;
    while (!socket2.isValid()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    socket1.write("Game started!");
    socket2.write("Game started!");

    socket2.close();
    std::cout << "End GameWorker" << std::endl;
}

std::string
readPacket(Socket& socket)
{
    std::string buffer = socket.read(4);
    std::stringstream inputStream(buffer);

    uint32_t size = 0;
    inputStream >> size;
    
    std::string result;
    if (size <= 10240) {
        result.append(buffer);

        buffer = socket.read(static_cast<int>(size));
        result.append(buffer);
    }

    return result;
}

bool
handshake(Socket& socket)
{
    std::string packet = readPacket(socket);
    return !packet.empty();
}

}

int
main(int argc, char *argv[])
{
    if (argc < 2) {
        usage(argv[0]);
        return -1;
    }

#if defined (_WIN32)
    WSAData data;
    WSAStartup(MAKEWORD(2, 2), &data);
#endif 

    std::cout << "Listening on " << argv[1] << "..." << std::endl;
    Socket socket;
    socket.bind(static_cast<uint16_t>(std::stol(argv[1])));
    socket.listen();
    while (1) {
        Socket clientSocket = socket.accept();
        if (handshake(clientSocket)) {
            if (waitingThread.get_id() != std::thread::id()) {
                socket2 = std::move(clientSocket);
                waitingThread.join();
            } else {
                std::thread thread(GameWorker, std::move(clientSocket));

                waitingThread = std::move(thread);
            }
        }
    }

    return 0;
}
