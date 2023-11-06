#ifndef TEST_VIRTUALKEYBOARD_H
#define TEST_VIRTUALKEYBOARD_H
#include<gtest/gtest.h>
#include<virtual_keyboard.h>
class test_virtualKeyboard : public ::testing::Test
{
protected:
    void SetUp() override {
    }
public:
    Virtual_Keyboard virtualKeyboard;
    //test_virtualKeyboard();
};

#endif // TEST_VIRTUALKEYBOARD_H
