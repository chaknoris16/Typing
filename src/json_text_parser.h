#ifndef JSONTEXTPARSER_H
#define JSONTEXTPARSER_H
#include "jsonconfigparser.h"
#include "IJsonTextParser.h"
#include <QObject>
class JsonTextParser : public QObject, public IJsonTextParser
{
    Q_OBJECT
private:
    const QString& _filePath;
public slots:
    void updateFields(int languageIndex) override;
public:
    JsonTextParser(const QString& filePath, QObject *parent = nullptr);

    const QJsonArray getLuricsArray() override;

    const QString getLanguage() override;

    const QJsonArray getTextsArray() override;

private:
    QString language;
    QJsonArray lyricsArray;
    QJsonArray textsArray;
    void setExercisesArray(int lessonIndex);
    QJsonArray extractArraysFromJson(const QString& filePath, const QString &keyName);
};

#endif // JSONTEXTPARSER_H
