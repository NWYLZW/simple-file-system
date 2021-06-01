#include "gtest/gtest.h"

#include "core/cryptor.h"

namespace {
    class TestClass:public testing::Test{
    public:
        Cryptor testCryptor;
    };
}

TEST_F(TestClass, Test_ReturnZeroMethod){
    char* plainText = "some text";
    char* ciphertext = testCryptor.virginia(plainText, "123456");
    ASSERT_EQ(
        testCryptor.virginia(
            ciphertext, "123456", true
        ), plainText
    );
}
