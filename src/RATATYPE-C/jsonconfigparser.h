#ifndef JSONCONFIGPARSER_H
#define JSONCONFIGPARSER_H

#include <QObject>
#include <stdexcept>
#include <QSettings>
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
    keyboardLayout getCurrentKeyboardLayout(int index, QJsonArray& coursesArray);
    const QString getCurrentMainText(int index,QJsonArray &exercisesArray);
    QString getCurrentCourseName(int index, QJsonArray& coursesArray);
    bool get_MainText();
private slots:
    void changeCourseIndex(int index);
    void saveLessonIndexInSettings(QString& courseName, int value);
    void saveExercisIndexInSettings(QString& courseName, int value);
private:

    QSettings *settings;
    void extractArraysFromJson(const QString& filePath);
    inline void setLessonsArray(int index);
    inline void setExercisesArray(int index);

signals:

};

#endif // JSONCONFIGPARSER_H
