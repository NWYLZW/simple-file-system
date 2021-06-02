#include "iostream"
using namespace std;

#include "gtest/gtest.h"

#include "core/cryptor.h"

namespace {
    class TestClass:public testing::Test{
    };
}

TEST_F(TestClass, Test_ReturnZeroMethod){
    string plainText  = "some text";
    string cipherText = Cryptor::simple(
        plainText, "123456"
    );
    GTEST_ASSERT_EQ(
        (string) Cryptor::simple(
            cipherText, "123456"
        ), plainText
    );
}
