#include "json_text_parser.h"

JsonTextParser::JsonTextParser(const QString& filePath, QObject *parent)
    : QObject{parent},
    _filePath{filePath}

{
    this->lyricsArray = extractArraysFromJson(this->_filePath, "lyrics");
}

void JsonTextParser::updateFields(int languageIndex)
{
    this->setExercisesArray(languageIndex);
}

const QJsonArray JsonTextParser::getLuricsArray()
{
    return this->lyricsArray;
}

const QString JsonTextParser::getLanguage()
{
    return this->language;
}

const QJsonArray JsonTextParser::getTextsArray()
{
    return this->textsArray;
}

void JsonTextParser::setExercisesArray(int lessonIndex)
{
    if(this->lyricsArray.isEmpty()) {
        throw std::invalid_argument("The lyricsArray array is empty.[]");
    }else {
        QJsonObject courseObject = lyricsArray[lessonIndex].toObject();
        this->textsArray = courseObject["lessons"].toArray();
        this->language = courseObject["name"].toString();
    }
}

QJsonArray JsonTextParser::extractArraysFromJson(const QString &filePath, const QString &keyName)
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
            auto rootObject = jsonDocument.object();
            return rootObject[keyName].toArray();
        }
    }
}
