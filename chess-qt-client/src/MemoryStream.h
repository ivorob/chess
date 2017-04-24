#ifndef __CHESS_ONLINE_MEMORY_STREAM_H__
#define __CHESS_ONLINE_MEMORY_STREAM_H__

#include <string>

class MemoryStream {
public:
    MemoryStream();

    void write(uint32_t value);
    void write(const std::string& data);

    const std::string& str() const;
private:
    std::string data;
};

#endif //__CHESS_ONLINE_MEMORY_STREAM_H__
