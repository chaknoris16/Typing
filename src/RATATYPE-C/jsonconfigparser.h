#ifndef JSONCONFIGPARSER_H
#define JSONCONFIGPARSER_H

#include <QObject>
#include <stdexcept>
#include <QSettings>
#include <QString>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
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
    bool get_MainText();
    ~JsonConfigParser();
    void extractArraysFromJson(const QString& filePath);
    void setLessonsArray(int courseIndex);
    void setExercisesArray(int lessonIndex);
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
    int exerciseIdex;
    QSettings *settings;

signals:

};

#endif // JSONCONFIGPARSER_H
