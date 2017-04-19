#if defined (_WIN32)
#include <winsock2.h>
#endif
#include <gtest/gtest.h>

namespace {

class Environment : public ::testing::Environment {
public:
    void SetUp() override {
#if defined (_WIN32)
        WSAData data;
        WSAStartup(MAKEWORD(2, 2), &data);
#endif
    }
};

}

int
main(int argc, char *argv[])
{
    ::testing::AddGlobalTestEnvironment(new Environment);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
