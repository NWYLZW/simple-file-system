#include "gtest/gtest.h"

#include "core/cryptor.h"

namespace {
    class TestClass:public testing::Test{
    public:
        Cryptor testCryptor;
    };
}

TEST_F(TestClass,Test_ReturnZeroMethod){
    ASSERT_EQ(testCryptor.zero(), 0);
}

TEST_F(TestClass,Test_ReturnZeroMethod_1){
    ASSERT_EQ(testCryptor.zero(), 1);
}