#include <gtest/gtest.h>
#include "MemoryStream.h"

TEST(MemoryStreamTest, write)
{
    MemoryStream stream;

    stream.write(0x17);
    stream.write(static_cast<uint8_t>(0x8));

    QByteArray buffer("\x17\x00\x00\x00\x08\x00\x00\x00", 8);
    ASSERT_EQ(buffer, stream.data());
}
