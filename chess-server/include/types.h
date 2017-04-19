#ifndef __CHESS_SERVER_TYPES_H__
#define __CHESS_SERVER_TYPES_H__

#if !defined(_WIN32)
typedef int SOCKET;

#define INVALID_SOCKET (-1)
#define closesocket(x) ::close(x)
#endif

#endif //__CHESS_SERVER_TYPES_H__
