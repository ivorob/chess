#ifndef __CHESS_ONLINE_MEMORY_STREAM_H__
#define __CHESS_ONLINE_MEMORY_STREAM_H__

#include <QByteArray>

class MemoryStream {
public:
    MemoryStream();

    void write(uint32_t value);
    void write(const QString& data);

    const QByteArray& data() const;
private:
    QByteArray rawData;
};

#endif //__CHESS_ONLINE_MEMORY_STREAM_H__
