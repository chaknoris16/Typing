#ifndef JSONCONFIGPARSER_H
#define JSONCONFIGPARSER_H

#include <QObject>
#include <stdexcept>
#include <QSettings>
#include <QString>
#include <QFile>
#include <QPair>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include "IJsonTextParser.h"
class JsonConfigParser : public QObject
{
    Q_OBJECT
private:
    struct keyboardLayout
    {
        QString keyboardSymbols;
        QString shiftKeyboardSymbols;
    };
public:
    explicit JsonConfigParser(QObject *parent = nullptr);
    QJsonArray coursesArray;
    QJsonArray lessonsArray;
    QJsonArray exercisesArray;
    keyboardLayout getCurrentKeyboardLayout();
    const QString getCurrentMainText();
    QString getCurrentCourseName();
    ~JsonConfigParser();
    QJsonArray extractArraysFromJson(const QString& filePath, const QString &keyName);
    QPair<QJsonArray, QString> extractValuesFromJsonArray(QJsonArray &lyricsArray, int index);
    void setLessonsArray(int courseIndex);
    virtual void setExercisesArray(int lessonIndex);

    void resetMaxCounters();
    void saveMaxIndexes();
    int getMaxLessonIndex() const;
    void setMaxLessonIndex(int newMaxLessonIndex);

    int getMaxExerciseIndex() const;
    void setMaxExerciseIndex(int newMaxExerciseIndex);

public slots:
    void setCourseIndex(int courseIndex);
    void setLessonIndex(int lessonIndex);
    void setExerciseIndex(int exerciseIndex);
    int getCurrentCourseIndex();
    int getCurrentLessonIndex();
    int getCurrentExercisIndex();
    void moveToNextExercise(QJsonArray& exercisesArray, int exercisesIndex, int lessonsIndex);
private:
    int courseIndex;
    int lessonIndex;
    int exerciseIndex;
    int maxLessonIndex{};
    int maxExerciseIndex{};
    QSettings *settings;

signals:
    void reFillLessonsCommbobox(int index);
    void reFillExercisesCommbobox(int index);
};

class JsonTextParser : public JsonConfigParser, public IJsonTextParser
{
    Q_OBJECT
private:
     QString filePath;
public slots:
    void updateFields(int languageIndex) override
    {
        this->setExercisesArray(languageIndex);
    }
public:
    JsonTextParser(const QString& filePath);

    const QJsonArray getLuricsArray() override
    {
        return this->lyricsArray;
    }

    const QString getLanguage() override
    {
        return this->language;
    }

    const QJsonArray getTextsArray() override
    {
        return this->textsArray;
    }

private:
    QString language;
    QJsonArray lyricsArray;
    QJsonArray textsArray;
    void setExercisesArray(int lessonIndex) override
    {
        if(this->lyricsArray.isEmpty()) {
            throw std::invalid_argument("The lyricsArray array is empty.[]");
        }else {
            QJsonObject courseObject = lyricsArray[lessonIndex].toObject();
            this->textsArray = courseObject["lessons"].toArray();
            this->language = courseObject["name"].toString();
        }
    }
};
#endif // JSONCONFIGPARSER_H
