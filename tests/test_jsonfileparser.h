#ifndef TEST_JSONFILEPARSER_H
#define TEST_JSONFILEPARSER_H
#include <gtest/gtest.h>
#include "../src/jsonconfigparser.h"
#include <QJsonArray>
class test_jsonFileParser : public ::testing::Test
{

protected:
    void SetUp() override {
    }
public:
    JsonConfigParser jsonParser;
    QJsonArray exercisesArray;
    void fillExercisesArray(){
        for(int i = 0; i < 14; i++){
            QJsonValue value("value");
            exercisesArray.append(value);
        }
    }
    JsonTextParser* textParser = new JsonTextParser("lyrics.json");
};

#endif // TEST_JSONFILEPARSER_H
