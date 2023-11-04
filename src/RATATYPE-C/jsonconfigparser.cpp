#include "jsonconfigparser.h"

JsonConfigParser::JsonConfigParser(QObject *parent)
    : QObject{parent}
{
    this->settings = new QSettings("MySoft", "Star Runner");
    this->extractArraysFromJson("course.json");
    this->setLessonsArray(getCurrentCourseIndex());
    this->setExercisesArray(this->getCurrentLessonIndex());
}

JsonConfigParser::keyboardLayout JsonConfigParser::getCurrentKeyboardLayout()
{
    int index = this->getCurrentCourseIndex();
    if(this->coursesArray.isEmpty()) {
        throw std::invalid_argument("The coursesArray is empty.");
    }else {
        if(this->coursesArray.size() < index){
            throw std::runtime_error("Error out of bounds of array of courses: " + std::to_string(index));
        }else {
            QJsonObject selectedСourse = this->coursesArray[index].toObject();
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

const QString JsonConfigParser::getCurrentMainText()
{
    int exercisesIndex = this->getCurrentExercisIndex();
    if(this->exercisesArray.isEmpty()) {
        throw std::invalid_argument("The exercise array is empty");
    }else {
        return this->exercisesArray[exercisesIndex].toString();
    }
    return "";
}

QString JsonConfigParser::getCurrentCourseName()
{
    int index = this->getCurrentCourseIndex();
    if(this->coursesArray.isEmpty()) {
        throw std::invalid_argument("The coursesArray is empty.");
    }else {
        if(this->coursesArray.size() < index){
            throw std::runtime_error("Error out of bounds of array of courses: " + std::to_string(index));
        }else {
            QJsonObject selectedСourse = this->coursesArray[index].toObject();
            return selectedСourse["course"].toString().replace(" ", "_");
        }
    }
    return "";
}

bool JsonConfigParser::get_MainText(){
    return true;
}

int JsonConfigParser::getCurrentCourseIndex()
{
    qDebug()<<"Course Index :"<<this->settings->value("selectedCourseIndex", 0).toInt();
    return this->settings->value("selectedCourseIndex", 0).toInt();
}

int JsonConfigParser::getCurrentLessonIndex()
{
    QString courseName = this->getCurrentCourseName();
    return this->settings->value(courseName + "LessonIndex", 0).toInt();
}

int JsonConfigParser::getCurrentExercisIndex()
{
    QString courseName = this->getCurrentCourseName();
    return this->settings->value(courseName + "ExerciseIndex", 0).toInt();
}


void JsonConfigParser::changeCourseIndex(int index)
{
    if(index < 0){
        throw std::invalid_argument("The value must be integral.");
    }else{
        this->settings->setValue("selectedCourseIndex", index);
    }
}

void JsonConfigParser::saveLessonIndexInSettings(int value)
{
    QString courseName = this->getCurrentCourseName();
    if(courseName.isEmpty()){
        throw std::invalid_argument("Problem with course name");
    }else if (value < 0) {
        throw std::invalid_argument("saveLessonIndexInSettings The value must be integral.");
    }else {
        this->settings->setValue(courseName + "LessonIndex", value);
    }
}

void JsonConfigParser::saveExercisIndexInSettings(int value)
{
    QString courseName = this->getCurrentCourseName();
    if(courseName.isEmpty()){
        throw std::invalid_argument("Problem with course name");
    }else if (value < 0) {
        throw std::invalid_argument("saveExercisIndexInSettings The value must be integral.");
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

void JsonConfigParser::setLessonsArray(int courseIndex)
{
    if(this->coursesArray.isEmpty()) {
        throw std::invalid_argument("The coursesArray array is empty.");
    }else {
        QJsonObject selectedCourseObject = this->coursesArray[courseIndex].toObject();
        this->lessonsArray = selectedCourseObject["lessons"].toArray();
    }
}

void JsonConfigParser::setExercisesArray(int lessonIndex)
{
    if(this->lessonsArray.isEmpty()) {
        throw std::invalid_argument("The lessonsArray array is empty.");
    }else {
        QJsonObject selectedLessonObject = this->lessonsArray[lessonIndex].toObject();
        this->exercisesArray = selectedLessonObject["exercises"].toArray();
    }
}
