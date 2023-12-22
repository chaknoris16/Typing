#ifndef KEYBOARDLAYOUTLANGUAGECONTROLLER_H
#define KEYBOARDLAYOUTLANGUAGECONTROLLER_H

#include <QWidget>
#include <QLocale>
#include <QGuiApplication>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include "incorrectkeyboardlayout.h"
class KeyboardLayoutLanguageController : public QWidget
{
    Q_OBJECT
public:
    explicit KeyboardLayoutLanguageController(QWidget *parent = nullptr);
    bool checkLanguageMatch(QLocale& defLocale);
    QLocale determineLocale(const QString &courseName);
    void setIncorectKeyboardLauoutMessage(QLocale& requiredLocale);
signals:
private:
    QLocale currentLocale;
};

#endif // KEYBOARDLAYOUTLANGUAGECONTROLLER_H
