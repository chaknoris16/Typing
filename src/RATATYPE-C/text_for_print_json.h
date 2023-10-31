#ifndef TEXT_FOR_PRINT_JSON_H
#define TEXT_FOR_PRINT_JSON_H


#include <QObject>
#include <QCoreApplication>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

class text_for_print_json : public QObject
{
    Q_OBJECT
public:
    explicit text_for_print_json(QObject *parent = nullptr);
    void setJsonFile();
private:
    QJsonArray exercises_ms_Tiny_wordsArray;
    QJsonArray exercises_ms_Tiny_words2Array;
    QJsonArray exercises_ms_Small_wordsArray;
    QJsonArray exercises_ms_Small_words2Array;
    QJsonArray exercises_ms_Small_words3Array;
    QJsonArray exercises_ms_Middle_wordsArray;
    QJsonArray exercises_ms_Middle_words2Array;
    QJsonArray exercises_ms_Middle_words3Array;
    QJsonArray exercises_ms_Big_wordsArray;
    QJsonArray exercises_ms_Big_words2Array;
    QJsonArray exercises_ms_Big_words3Array;
    QJsonArray exercises_ms_Large_wordsArray;
    QJsonArray exercises_ms_Large_words2Array;
    QJsonArray exercises_ms_Large_words3Array;

private:
    QJsonObject lesson_ms_tiny_Object;
    QJsonObject lesson_ms_tiny2_Object;
    QJsonObject lesson_ms_small_Object;
    QJsonObject lesson_ms_small2_Object;
    QJsonObject lesson_ms_small3_Object;
    QJsonObject lesson_ms_middle_Object;
    QJsonObject lesson_ms_middle2_Object;
    QJsonObject lesson_ms_middle3_Object;
    QJsonObject lesson_ms_big_Object;
    QJsonObject lesson_ms_big2_Object;
    QJsonObject lesson_ms_big3_Object;
    QJsonObject lesson_ms_large_Object;
    QJsonObject lesson_ms_large2_Object;
    QJsonObject lesson_ms_large3_Object;
private:
    QJsonArray lessons_ms_Array;

private:
    QJsonObject courseObject;

    QJsonObject newCourseObject;
    QJsonObject coursesObject;
};

#endif // TEXT_FOR_PRINT_JSON_H
