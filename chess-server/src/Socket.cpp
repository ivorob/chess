#include <stdexcept>
#include <iostream>
#if !defined(_WIN32)
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#endif
#include "Socket.h"

Socket::Socket()
    : sockfd(INVALID_SOCKET)
{
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    //TODO: test to INVALID_SOCKET
}

Socket::Socket(Socket&& socket)
    : sockfd(socket.sockfd)
{
    socket.sockfd = INVALID_SOCKET;
}

Socket::Socket(SOCKET sockfd)
    : sockfd(sockfd)
{
}

Socket::~Socket()
{
    close();
}

void
Socket::close()
{
    if (this->sockfd != INVALID_SOCKET) {
        closesocket(this->sockfd);
    }
}

void
Socket::bind(uint16_t port)
{
    if (port <= 1024) {
        throw std::invalid_argument("Use port wich greater than 1024");
    }

    struct sockaddr_in service;
    memset(&service, 0, sizeof(service));
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = INADDR_ANY;
    service.sin_port = htons(port);
    ::bind(this->sockfd, (struct sockaddr *)&service, sizeof(service)); 
    //TODO: check bind error
}

Socket
Socket::accept()
{
    SOCKET newSocket = ::accept(this->sockfd, nullptr, 0);
    if (newSocket == INVALID_SOCKET) {
        throw std::runtime_error("Can not accept socket");
    }

    return Socket(newSocket);
}

void
Socket::listen(int backlog)
{
    ::listen(this->sockfd, backlog);
}

int
Socket::write(const std::string& buffer)
{
    int result = send(this->sockfd, buffer.c_str(), static_cast<int>(buffer.size()), 0);
    return result;
}

std::string
Socket::read(int maxSize)
{
    std::string result;
    do {
        char byteToRead = 0;
        int bytesRead = recv(this->sockfd, &byteToRead, sizeof(byteToRead), 0);
        if (bytesRead > 0) {
            result.push_back(byteToRead);
        } else if (bytesRead < 0) {
            throw std::runtime_error("Error during reading from socket!");
        } else if (bytesRead == 0) {
            break;
        }
    } while (maxSize == -1 || result.size() < maxSize);

    return result;
}

Socket&
Socket::operator=(Socket&& other)
{
    this->sockfd = other.sockfd;
    other.sockfd = INVALID_SOCKET;
    return *this;
}

bool
Socket::isValid() const
{
    return this->sockfd != INVALID_SOCKET;
}
