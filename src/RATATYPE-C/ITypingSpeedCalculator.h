#ifndef ITYPINGSPEEDCALCULATOR_H
#define ITYPINGSPEEDCALCULATOR_H
class ITypingSpeedCalculator
{
public:
    virtual ~ITypingSpeedCalculator() = default;
    virtual calculationTypingSpeed(QTime& startTime, int correctElements) = 0;
};

#endif // ITYPINGSPEEDCALCULATOR_H
