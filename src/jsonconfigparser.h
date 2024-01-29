#ifndef JSONCONFIGPARSER_H
#define JSONCONFIGPARSER_H

#include <QObject>
#include <stdexcept>
#include <QSettings>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QPair>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include "IJsonTextParser.h"
class JsonConfigParser : public QObject
{
    Q_OBJECT
private:
    const QString& _filePath;
    struct keyboardLayout
    {
        QString keyboardSymbols;
        QString shiftKeyboardSymbols;
    };
public:
    explicit JsonConfigParser(const QString& filePath, QObject *parent = nullptr);
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

    void saveIndexes();
    int getMaxLessonIndex() const;
    int getMaxExerciseIndex() const;
    int determinateMaxExerciseIndex();
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
    QJsonObject rootObject;

signals:
    void reFillLessonsCommbobox(int index);
    void reFillExercisesCommbobox(int index);
};

#endif // JSONCONFIGPARSER_H
