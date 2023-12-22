#include "jsonconfigparser.h"

JsonConfigParser::JsonConfigParser(QObject *parent)
    : QObject{parent}
{
    //this->settings = new QSettings("MySoft", "Star Runner", this);
    this->coursesArray = this->extractArraysFromJson("course.json", "courses");;
    this->setLessonsArray(courseIndex);
    this->setExercisesArray(lessonIndex);
}

JsonConfigParser::~JsonConfigParser()
{
    qDebug()<<"save indexes";
}

JsonConfigParser::keyboardLayout JsonConfigParser::getCurrentKeyboardLayout()
{
    int index = this->courseIndex;
    if(this->coursesArray.isEmpty()) {
        throw std::invalid_argument("The coursesArray is empty.[getCurrentKeyboardLayout]");
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
    int index = this->courseIndex;
    if(this->coursesArray.isEmpty()) {
        throw std::invalid_argument("The coursesArray is empty.[getCurrentCourseName]");
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

int JsonConfigParser::getCurrentCourseIndex()
{
    return this->courseIndex;
}

int JsonConfigParser::getCurrentLessonIndex()
{
    return this->lessonIndex;
}

int JsonConfigParser::getCurrentExercisIndex()
{
    return this->exerciseIndex;
}


void JsonConfigParser::setCourseIndex(int courseIndex)
{
    if(courseIndex < 0){
        throw std::invalid_argument("The value must be integral.[setCourseIndex]");
    }else{
        this->courseIndex = courseIndex;
        qDebug()<<"Course Index changing to "<<courseIndex;
    }
}

void JsonConfigParser::setLessonIndex(int lessonIndex)
{
    if (lessonIndex < 0) {
        throw std::invalid_argument("The value must be integral.[setLessonIndex]");
    }else {
        this->lessonIndex = lessonIndex;
        qDebug()<<"lesson index changing to "<<lessonIndex;
    }
}

void JsonConfigParser::setExerciseIndex(int exerciseIndex)
{
    if (exerciseIndex < 0) {
        throw std::invalid_argument("The value must be integral.[setExerciseIndex]");
    }else {
        this->exerciseIndex = exerciseIndex;
        qDebug()<<"Exercise index changing to "<<exerciseIndex;
    }

}

void JsonConfigParser::moveToNextExercise(QJsonArray &exercisesArray, int exercisesIndex, int lessonsIndex)
{
    if(exercisesIndex + 1 < exercisesArray.size()) {
        this->setExerciseIndex(exercisesIndex + 1);
        if(this->exerciseIndex > this->maxExerciseIndex) this->maxExerciseIndex = this->exerciseIndex;
        emit this->reFillExercisesCommbobox(this->maxExerciseIndex);
    }else {
        this->setLessonIndex(lessonsIndex + 1);
        if(this->lessonIndex > this->maxLessonIndex) this->maxLessonIndex = this->lessonIndex; this->maxExerciseIndex = 0;

        emit this->reFillLessonsCommbobox(this->maxLessonIndex);
        emit this->reFillExercisesCommbobox(this->maxExerciseIndex);
    }
}

int JsonConfigParser::getMaxExerciseIndex() const
{
    return maxExerciseIndex;
}

int JsonConfigParser::determinateMaxExerciseIndex()
{
    if(this->lessonIndex < this->maxLessonIndex)
    {
        return exercisesArray.size() - 1;
    }
    return this->maxExerciseIndex;
}

int JsonConfigParser::getMaxLessonIndex() const
{
    return maxLessonIndex;
}

QJsonArray JsonConfigParser::extractArraysFromJson(const QString &filePath, const QString& keyName)
{
    if(filePath.isEmpty()){
        throw std::invalid_argument("The path to the JSON file is empty.");
    }else {
        QFile jsonFile(filePath);
        if (!jsonFile.open(QIODevice::ReadOnly)){
            throw std::runtime_error("Error opening JSON file: " + jsonFile.errorString().toStdString());
        }else {
            QByteArray jsonData = jsonFile.readAll();
            jsonFile.close();
            QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData);
            this->rootObject = jsonDocument.object();
            this->courseIndex = rootObject["currentCourseIndex"].toInt();
            qDebug() << courseIndex;
            return rootObject[keyName].toArray();
        }
    }
}



void JsonConfigParser::setLessonsArray(int courseIndex)
{
    if(this->coursesArray.isEmpty()) {
        throw std::invalid_argument("The coursesArray array is empty.[setLessonsArray]");
    }else {
        QJsonObject selectedCourseObject = this->coursesArray[courseIndex].toObject();
        this->lessonsArray = selectedCourseObject["lessons"].toArray();
        this->lessonIndex = selectedCourseObject["currentLessonIndex"].toInt();
        this->maxLessonIndex = selectedCourseObject["maxLessonIndex"].toInt();
        qDebug() << this->lessonIndex << this->maxLessonIndex;
    }
}

void JsonConfigParser::setExercisesArray(int lessonIndex)
{
    if(this->lessonsArray.isEmpty()) {
        throw std::invalid_argument("The lessonsArray array is empty.");
    }else {
        QJsonObject selectedLessonObject = this->lessonsArray[lessonIndex].toObject();
        this->exercisesArray = selectedLessonObject["exercises"].toArray();
        this->exerciseIndex = selectedLessonObject["currentExerciseIndex"].toInt();
        this->maxExerciseIndex = selectedLessonObject["maxExerciseIndex"].toInt();
        qDebug() << this->exerciseIndex << this->maxExerciseIndex;
    }
}

QPair<QJsonArray, QString> JsonConfigParser::extractValuesFromJsonArray(QJsonArray& lyricsArray, int index)
{
    if(lyricsArray.isEmpty()) {
        throw std::invalid_argument("The lyricsArray array is empty.[extractValuesFromJsonArray]");
    }else {
        QJsonObject courseObject = lyricsArray[index].toObject();
        QJsonArray lessonsArray = courseObject["lessons"].toArray();
        QString courseName = courseObject["course"].toString();

        return QPair<QJsonArray, QString>(lessonsArray, courseName);
    }
    return QPair<QJsonArray, QString>();
}

void JsonConfigParser::saveIndexes()
{

    this->rootObject["currentCourseIndex"] = this->courseIndex;

    QJsonObject courseObject = rootObject["courses"].toArray()[this->courseIndex].toObject();
    courseObject["currentLessonIndex"] = this->lessonIndex;
    courseObject["maxLessonIndex"] = this->maxLessonIndex;


    QJsonObject lessonObject = courseObject["lessons"].toArray()[this->lessonIndex].toObject();

    lessonObject["currentExerciseIndex"] = this->exerciseIndex;
    lessonObject["maxExerciseIndex"] = this->maxExerciseIndex;

    QJsonArray lessonsArray = courseObject["lessons"].toArray();
    lessonsArray[this->lessonIndex] = lessonObject;

    courseObject["lessons"] = lessonsArray;

    QJsonArray coursesArray = rootObject["courses"].toArray();
    coursesArray[this->courseIndex] = courseObject;

    rootObject["courses"] = coursesArray;

    QFile writeFile("course.json");
    if (!writeFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open JSON file for writing.";
        return;
    }

    QJsonDocument updatedJsonDoc(this->rootObject);
    writeFile.write(updatedJsonDoc.toJson());
    writeFile.close();
}

JsonTextParser::JsonTextParser(const QString& filePath) : filePath(filePath)
{
    this->lyricsArray = extractArraysFromJson(this->filePath, "lyrics");
}
