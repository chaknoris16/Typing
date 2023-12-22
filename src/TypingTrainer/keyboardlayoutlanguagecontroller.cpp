#include "keyboardlayoutlanguagecontroller.h"
#include <QLineEdit>
KeyboardLayoutLanguageController::KeyboardLayoutLanguageController(QWidget *parent)
    : QWidget{parent}
{

}


bool KeyboardLayoutLanguageController::checkLanguageMatch(QLocale& defLocale)
{
    if(QGuiApplication::inputMethod()->locale() == defLocale)
    {
        return true;
    }
    return false;
}

QLocale KeyboardLayoutLanguageController::determineLocale(const QString &courseName)
{
    QString lowerCourseName = courseName.toLower();

    if (lowerCourseName.startsWith("english")) {
        return QLocale::English;
    } else if (lowerCourseName.startsWith("ukrainian")) {
        return QLocale::Ukrainian;
    } else {
        return QLocale::system();
    }
}

void KeyboardLayoutLanguageController::setIncorectKeyboardLauoutMessage(QLocale &requiredLocale)
{
    IncorrectKeyboardLayout* incorrectKeyboardLayout = new IncorrectKeyboardLayout(this);

    incorrectKeyboardLayout->setMessge(requiredLocale);
    incorrectKeyboardLayout->exec();
}
