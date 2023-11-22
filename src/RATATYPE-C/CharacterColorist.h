#ifndef CHARACTERCOLORIST_H
#define CHARACTERCOLORIST_H
#include "IColorizeCharacter.h"
class CharacterColorist : public IColorizeCharacter
{
public:
    //~CharacterColorist() override;

    void colorizeCorrectCharacter(QTextCursor &cursor, QColor color) override
    {
        if(this->isFirstSenbool){
            cursor.setPosition(this->Pos);
            this->isFirstSenbool = false;
        } else {

            this->format.setBackground(QBrush(QColor(255, 255, 255)));
            this->format.setForeground(QBrush(QColor(0, 255, 0)));
            cursor.setCharFormat(this->format);
            ++Pos;
            cursor.setPosition(this->Pos);
        }
        cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor);
        selectedText = cursor.selectedText();
        if (!selectedText.isEmpty())
        {
            this->colorizeCorrectCharacter(cursor, color);
        }
    }

    void colorizeIncorrectCharacter(QTextCursor &cursor, QColor color) override
    {
        this->colorizeCorrectCharacter(cursor, color);
    }

    void setPos(int newPos)  override
    {
        this->Pos = newPos;
    }
private:
    bool isFirstSenbool = true;
    QTextCharFormat format;
    QString selectedText;
    int Pos = 0;
    void colorizeCurrentCharacter(QTextCursor &cursor, QColor color)
    {
        this->format.setBackground(QBrush(color));
        this->format.setForeground(QBrush(QColor(255, 255, 255)));
        cursor.setCharFormat(format);
    }
};

#endif // CHARACTERCOLORIST_H
