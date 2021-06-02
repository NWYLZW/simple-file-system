#include "iostream"
using namespace std;

#include "gtest/gtest.h"

#include "core/cryptor.h"

namespace {
    class TestClass:public testing::Test{
    };
}

TEST_F(TestClass, Test_ReturnZeroMethod){
    string plainText  = (string) "some text";
    string cipherText = (string) Cryptor::simple(
        plainText.c_str(), "123456"
    );
    GTEST_ASSERT_EQ(
        (string) Cryptor::simple(
            cipherText.c_str(), "123456"
        ), plainText
    );
}
