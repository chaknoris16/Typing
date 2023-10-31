#include "jsonconfigparser.h"

JsonConfigParser::JsonConfigParser(QObject *parent)
    : QObject{parent}
{
    this->settings = new QSettings("MySoft", "Star Runner");

}

JsonConfigParser::keyboardLayout JsonConfigParser::getCurrentKeyboardLayout(int index, QJsonArray& coursesArray)
{
    if(coursesArray.isEmpty()) {
        throw std::invalid_argument("The coursesArray is empty.");
    }else {
        if(coursesArray.size() < index){
            throw std::runtime_error("Error out of bounds of array of courses: " + std::to_string(index));
        }else {
            QJsonObject selectedСourse = coursesArray[index].toObject();
            if(selectedСourse["keyboardLayout"].toString().isEmpty() ||
               selectedСourse["shiftPressKeyboardLayout"].toString().isEmpty()){
                throw std::runtime_error("Read error, empty string");
            }else {
                keyboardLayout kl;
                kl.keyboardSymbols = selectedСourse["keyboardLayout"].toString();
                kl.shiftKeyboardSymbols = selectedСourse["shiftPressKeyboardLayout"].toString();
                return kl;
            }
        }
    }
}

const QString JsonConfigParser::getCurrentMainText(int index, QJsonArray& exercisesArray)
{
    if(exercisesArray.isEmpty()) {
        throw std::invalid_argument("The exercise array is empty");
    }else {
        return exercisesArray[index].toString();
    }
}

QString JsonConfigParser::getCurrentCourseName(int index, QJsonArray &coursesArray)
{
    if(coursesArray.isEmpty()) {
        throw std::invalid_argument("The coursesArray is empty.");
    }else {
        if(coursesArray.size() < index){
            throw std::runtime_error("Error out of bounds of array of courses: " + std::to_string(index));
        }else {
            QJsonObject selectedСourse = coursesArray[index].toObject();
            return selectedСourse["course"].toString();
        }
    }
}

bool JsonConfigParser::get_MainText(){
    return true;
}
void JsonConfigParser::changeCourseIndex(int index)
{
    if(index < 0){
        throw std::invalid_argument("The value must be integral.");
    }else{
        this->settings->setValue("selectedCourseIndex", index);
    }
}

void JsonConfigParser::saveLessonIndexInSettings(QString &courseName, int value)
{
    if(courseName.isEmpty()){
        throw std::invalid_argument("Problem with course name");
    }else if (value < 0) {
        throw std::invalid_argument("The value must be integral.");
    }else {
        this->settings->setValue(courseName + "LessonIndex", value);
    }
}

void JsonConfigParser::saveExercisIndexInSettings(QString &courseName, int value)
{
    if(courseName.isEmpty()){
        throw std::invalid_argument("Problem with course name");
    }else if (value < 0) {
        throw std::invalid_argument("The value must be integral.");
    }else {
        this->settings->setValue(courseName + "ExerciseIndex", value);
    }
}

void JsonConfigParser::extractArraysFromJson(const QString &filePath)
{
    if(filePath.isEmpty()) {
        throw std::invalid_argument("The path to the JSON file is empty.");
    }else {
        QFile jsonFile(filePath);
        if (!jsonFile.open(QIODevice::ReadOnly)){
            throw std::runtime_error("Error opening JSON file: " + jsonFile.errorString().toStdString());
        }else {
            QByteArray jsonData = jsonFile.readAll();
            jsonFile.close();
            QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData);
            QJsonObject rootObject = jsonDocument.object();
            this->coursesArray = rootObject["courses"].toArray();
        }
    }
}

inline void JsonConfigParser::setLessonsArray(int index)
{
    if(this->coursesArray.isEmpty()) {
        throw std::invalid_argument("The coursesArray array is empty.");
    }else {
        QJsonObject selectedCourseObject = this->coursesArray[index].toObject();
        this->lessonsArray = selectedCourseObject["lessons"].toArray();
    }
}

inline void JsonConfigParser::setExercisesArray(int index)
{
    if(this->lessonsArray.isEmpty()) {
        throw std::invalid_argument("The lessonsArray array is empty.");
    }else {
        QJsonObject selectedLessonObject = this->lessonsArray[index].toObject();
        this->exercisesArray = selectedLessonObject["exercises"].toArray();
    }
}
