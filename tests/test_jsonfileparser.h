#ifndef TEST_JSONFILEPARSER_H
#define TEST_JSONFILEPARSER_H
#include <gtest/gtest.h>
#include "jsonconfigparser.h"
class test_jsonFileParser : public ::testing::Test
{

protected:
    void SetUp() override {
    }
public:
    JsonConfigParser jsonParser;
};

#endif // TEST_JSONFILEPARSER_H
