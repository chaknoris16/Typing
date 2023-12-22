#ifndef TYPINGSPEEDCALCULATOR_H
#define TYPINGSPEEDCALCULATOR_H
#include "ITypingSpeedCalculator.h"
#include "QTime"
class TypingSpeedCalculator : public ITypingSpeedCalculator
{
public:
    calculationTypingSpeed(QTime &startTime, int correctElements) override
    {
        QTime currentTime = QTime::currentTime();
        int timeElapsed = startTime.msecsTo(currentTime);
        double minutesElapsed = timeElapsed / 60000.0;

        unsigned int typingSpeed = correctElements / minutesElapsed;
        qDebug()<<"typingSpeed"<< typingSpeed;
        return typingSpeed;
    }
};

#endif // TYPINGSPEEDCALCULATOR_H
