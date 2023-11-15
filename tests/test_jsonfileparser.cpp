#include "test_jsonfileparser.h"
#include "jsonconfigparser.h"
#include <QString>
TEST_F(test_jsonFileParser, checkCourseIndex) {
    ASSERT_FALSE(this->jsonParser.getCurrentCourseIndex() < 0);
}

TEST_F(test_jsonFileParser, checkCourseArray) {
    ASSERT_FALSE(this->jsonParser.coursesArray.isEmpty());
}

TEST_F(test_jsonFileParser, checkCourseName) {
        ASSERT_FALSE(this->jsonParser.getCurrentCourseName().isEmpty());
}


TEST_F(test_jsonFileParser, checkLessonsIndex) {
        ASSERT_FALSE(this->jsonParser.getCurrentLessonIndex() < 0);
}

TEST_F(test_jsonFileParser, checkExerciseIndex) {
        ASSERT_FALSE(this->jsonParser.getCurrentExercisIndex() < 0);
}
TEST_F(test_jsonFileParser, checkLessonsArray) {
        ASSERT_FALSE (this->jsonParser.lessonsArray.isEmpty());
}

TEST_F(test_jsonFileParser, checkExercisesArray) {
        ASSERT_FALSE (this->jsonParser.exercisesArray.isEmpty());
}

TEST_F(test_jsonFileParser, checkCurrengMainText) {
        ASSERT_FALSE (this->jsonParser.getCurrentMainText().isEmpty());
}


TEST_F(test_jsonFileParser, checkCurrenKeyboardLayout) {
        ASSERT_FALSE (this->jsonParser.getCurrentKeyboardLayout().keyboardSymbols.isEmpty());
        ASSERT_FALSE (this->jsonParser.getCurrentKeyboardLayout().shiftKeyboardSymbols.isEmpty());
}

TEST_F(test_jsonFileParser, moveToNextExercise) {
        this->fillExercisesArray();
        int lessonIndex = 0;
        for(int i = 0; i < exercisesArray.size(); i++){
            int exerciseIndex = i;
            jsonParser.moveToNextExercise(this->exercisesArray, exerciseIndex, lessonIndex);
            ASSERT_TRUE(jsonParser.getCurrentExercisIndex() == i + 1);
        }
        jsonParser.moveToNextExercise(exercisesArray, 14, 0);
            ASSERT_TRUE(jsonParser.getCurrentLessonIndex() == 1);
}

TEST_F(test_jsonFileParser, jsonTextParser) {
    for(int i = 0; i < textParser->getLuricsArray().size(); i++){
        this->textParser->updateFields(i);
        ASSERT_FALSE(textParser->getLanguage().isEmpty());
        ASSERT_FALSE(textParser->getTextsArray().isEmpty());
    }


}
