#ifndef IJSONTEXTPARSER_H
#define IJSONTEXTPARSER_H
#include <QJsonArray>

class IJsonTextParser
{
public:
    virtual ~IJsonTextParser() = default;
    virtual const QJsonArray getLuricsArray() = 0;
    virtual const QString getLanguage() = 0;
    virtual const QJsonArray getTextsArray() = 0;
public slots:
    virtual void updateFields(int languageIndex) = 0;
};

#endif // IJSONTEXTPARSER_H
