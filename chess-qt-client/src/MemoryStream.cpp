#include <QString>
#include "MemoryStream.h"

MemoryStream::MemoryStream()
{
}

const QByteArray&
MemoryStream::data() const
{
    return this->rawData;
}

void
MemoryStream::write(uint32_t value)
{
    this->rawData.append((const char *)&value, sizeof(value));
}

void
MemoryStream::write(const QString& data)
{
    write(static_cast<uint32_t>(data.size()));
    this->rawData.append(data);
}
