#ifndef IRANDOMTEXTPROVIDER_H
#define IRANDOMTEXTPROVIDER_H
#include <QString>
class IRandomTextProvider
{
public:
    virtual ~IRandomTextProvider() = default;
    virtual void setArray(const QJsonArray& array) = 0;
    virtual QString pickRandomElement() = 0;
};

#endif // IRANDOMTEXTPROVIDER_H
