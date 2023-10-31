#ifndef VIRTUAL_KEYBOARD_H
#define VIRTUAL_KEYBOARD_H

#include <QObject>
#include <QMap>
#include <QVector>
#include <QPair>
#include <QString>
#include <QTimer>
#include <QPushButton>
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
public:
    explicit Virtual_Keyboard(MainWindow* mainWindow ,QWidget *parent = nullptr);
    void changeButtonColorByText(QSet<QChar> *uniqueLetters, QColor color);
    void changeBorderButton(const QChar &textButton, QString &QSS_Border);
    void flashButtonBackground(const QString &textButton, QColor background, int flashDurationMs);
    void revertButtonTextColorBack(QSet<QChar> *uniqueLetters);
    void deleteBorderButton(QString &QSS_Border);
    void changeShiftedCharacters(const QVector<ButtonCharPair>& vectorPair);
    const QVector<ButtonCharPair> &get_vectorShiftedPair() const {
        return buttonNewCharPair;
    }

    const QVector<ButtonCharPair> &get_vectorDefaultPair() const {
        return buttonCharPair;
    }
    void clearSyleSheetdPustButton()
    {
        pastButton->setStyleSheet("");
    }

private:
    MainWindow* mainWindow;
    QMap<QPushButton*, QPalette>* originalColors = new QMap<QPushButton*, QPalette>;
    QMap<QString, QPushButton*>* stringToButtonMap = new QMap<QString, QPushButton*>;
    void fillMapWhisPair(QMap<QString, QPushButton *> *map);
    void setColorTextButton(QPushButton *button, const QString &buttonTextColorBlack);
    void saveDefaultColor(QSet<QChar> *uniqueLetters);
    QPushButton* pastButton = new QPushButton;
    QColor* colorSelectTexts = new QColor;
    QVector<ButtonCharPair> buttonNewCharPair;
    QVector<ButtonCharPair> buttonCharPair;
    void FillVector_ButtonNewCharPair(QVector<ButtonCharPair> &vectorPair);
    void FillVector_ButtonCharPair(QVector<ButtonCharPair> &vectorPair);
};

#endif // VIRTUAL_KEYBOARD_H
