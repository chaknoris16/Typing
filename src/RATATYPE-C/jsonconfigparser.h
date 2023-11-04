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
    int getCurrentCourseIndex();
    int getCurrentLessonIndex();
    int getCurrentExercisIndex();
    void extractArraysFromJson(const QString& filePath);
    void setLessonsArray(int courseIndex);
    void setExercisesArray(int lessonIndex);

public slots:
    void changeCourseIndex(int index);
    void saveLessonIndexInSettings(int value);
    void saveExercisIndexInSettings(int value);
private:

    QSettings *settings;

signals:

};

#endif // JSONCONFIGPARSER_H
