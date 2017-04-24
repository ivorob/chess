#include "MemoryStream.h"

MemoryStream::MemoryStream()
{
}

const std::string&
MemoryStream::constData() const
{
    return this->data;
}

void
MemoryStream::write(uint32_t value)
{
    this->data.append((const char *)&value, sizeof(value));
}

void
MemoryStream::write(const std::string& data)
{
    write(static_cast<uint32_t>(data.size()));
    this->data.append(data);
}
