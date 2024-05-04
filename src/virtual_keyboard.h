#ifndef VIRTUAL_KEYBOARD_H
#define VIRTUAL_KEYBOARD_H

#include <QObject>
#include <QMap>
#include <QVector>
#include <QPair>
#include <QString>
#include <QTimer>
#include <QPushButton>
#include "ui_mainwindow.h"
#include <stdexcept>
#include "jsonconfigparser.h"

class MainWindow;
class Virtual_Keyboard : public QWidget
{
    Q_OBJECT

private:
    struct ButtonCharPair
    {
        QPushButton* button;
        QChar character;
    };
public slots:
    void setMapKeyboardLauout(const QString& keyboardSymbols, const QString& shiftKeyboardSymbols);
public:
    explicit Virtual_Keyboard(MainWindow* mainWindow ,QWidget *parent = nullptr);
    void changeButtonColorByText(QSet<QChar> *uniqueLetters, QColor color);
    void changeBorderButton(const QChar &textButton, QString &QSS_Border);
    void flashButtonBackground(const QString &textButton, QColor background, int flashDurationMs);
    void revertButtonTextColorBack(QSet<QChar> *uniqueLetters);
    void deleteBorderButton(QString &QSS_Border);
    void setKeyboardCharacters(const QMap<QString, QPushButton *> &symbolAndButton);
    QPushButton* getButton(const QChar& symbol);
    const QMap<QString, QPushButton*>& getMapShiftedPair() const {
        return this->shift_MapSymbolKeyboardButton;
    }

    const QMap<QString, QPushButton*>& getMapDefaultPair() const {
        return this->def_MapSymbolKeyboardButton;
    }


private:
    MainWindow* mainWindow;
    JsonConfigParser* jsonParser;
    QVector<QPushButton*> keyboardButtons;
    void fillVectorKeyboardButtons(Ui::MainWindow *ui);
    QMap<QPushButton*, QPalette>* originalColors = new QMap<QPushButton*, QPalette>;
    QMap<QString, QPushButton*> def_MapSymbolKeyboardButton;
    QMap<QString, QPushButton*> shift_MapSymbolKeyboardButton;
    void fillMapWhisPair(QMap<QString, QPushButton *>& map, QString def_keyboardLayout, QVector<QPushButton*>& keyboardButtons);
    void setColorTextButton(QPushButton *button, const QString &buttonTextColorBlack);
    QPushButton* pastButton = new QPushButton;
    QColor* colorSelectTexts = new QColor;
    QVector<ButtonCharPair> buttonNewCharPair;
    QVector<ButtonCharPair> buttonCharPair;
    void FillVector_ButtonNewCharPair(QVector<ButtonCharPair> &vectorPair);
    void FillVector_ButtonCharPair(QVector<ButtonCharPair> &vectorPair);
};

#endif // VIRTUAL_KEYBOARD_H
