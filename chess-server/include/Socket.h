#ifndef __CHESS_ONLINE_SOCKET_H__
#define __CHESS_ONLINE_SOCKET_H__

#include <stdint.h>
#include "types.h"
#if defined (_WIN32)
#include <winsock2.h>
#else
#include <sys/socket.h>
#endif

class Socket {
public:
    Socket();
    Socket(Socket&& socket);
    Socket(SOCKET sockfd);
    ~Socket();

    void bind(uint16_t port);
    void listen(int backlog = SOMAXCONN);
    Socket accept();

    int write(const std::string& buffer);
    std::string read(int maxSize = -1);

    Socket& operator=(Socket&& other);

    bool isValid() const;
    void close();
private:
    SOCKET sockfd;
};

#endif //__CHESS_ONLINE_SOCKET_H__
