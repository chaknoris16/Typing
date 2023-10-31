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
    int getCurrentLessonIndex(QString courseName);
    int getCurrentExercisIndex(QString courseName);
private slots:
    void changeCourseIndex(int index);
    void saveLessonIndexInSettings(QString& courseName, int value);
    void saveExercisIndexInSettings(QString& courseName, int value);
private:

    QSettings *settings;
    void extractArraysFromJson(const QString& filePath);
    inline void setLessonsArray(int courseIndex);
    inline void setExercisesArray(int lessonIndex);

signals:

};

#endif // JSONCONFIGPARSER_H
