#ifndef RANDOMELEMENTPICKER_H
#define RANDOMELEMENTPICKER_H
#include <QJsonArray>
#include "IRandomTextProvider.h"
class RandomElementPicker :public IRandomTextProvider
{
public:
    RandomElementPicker() {}
    RandomElementPicker(const QJsonArray& array) : array_(array) {}

    QString pickRandomElement() override
    {
        if(array_.isEmpty()) {
            qDebug() << "Array is empty.";
            return QString();
        }
        int randomIndex = QRandomGenerator::global()->bounded(array_.size());
        QJsonValue randomElement = array_.at(randomIndex);
        array_.removeAt(randomIndex);

        return randomElement.toString();
    }
    void setArray(const QJsonArray& array) override
    {
        array_ = array;
    }
private:
    QJsonArray array_;
};
#endif // RANDOMELEMENTPICKER_H
