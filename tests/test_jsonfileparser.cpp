#include "test_jsonfileparser.h"
#include "jsonconfigparser.h"
#include "mainwindow.h"
TEST_F(test_jsonFileParser, Test1) {
    // Ваш код для першого тесту.
    ASSERT_EQ(1, 1);
}

TEST_F(test_jsonFileParser, Test2) {
    // Ваш код для другого тесту.
    ASSERT_TRUE(true);
}

TEST_F(test_jsonFileParser, Test3) {
    JsonConfigParser jsonConFParser;
        ASSERT_TRUE(jsonConFParser.get_MainText());
}
TEST_F(test_jsonFileParser, Test4) {
        MainWindow mainwindow;
        ASSERT_TRUE(mainwindow.get_echo());
}
