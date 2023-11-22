#ifndef ICOLORIZECHARACTER_H
#define ICOLORIZECHARACTER_H
#include <QTextCursor>
#include <QColor>
class IColorizeCharacter
{
public:
    virtual ~IColorizeCharacter() = default;
    virtual void colorizeCorrectCharacter(QTextCursor& cursor, QColor color) = 0;
    virtual void colorizeIncorrectCharacter(QTextCursor& cursor, QColor color) = 0;
    virtual void setPos(int newPos) = 0;
};

#endif // ICOLORIZECHARACTER_H
