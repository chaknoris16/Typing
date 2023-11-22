#include "typingtestingpage.h"
#include "mainwindow.h"
TypingTestingPage::TypingTestingPage(QTextEdit *textEdit, QObject *parent, QTableWidget *tableWidget, QComboBox *comboBox)
    : QObject{parent},
    _textEdit{textEdit},
    _outPutTable{tableWidget},
    _comboBox{comboBox}
{
    this->settings = new QSettings("MySoft", "Star Runner");
    this->_textEdit->setReadOnly(true);
    this->_textEdit->setTextInteractionFlags(Qt::TextSelectableByMouse);
    this->textParser->updateFields(this->settings->value("languageIndex").toInt());
}
TypingTestingPage::~TypingTestingPage()
{
    delete db;
    delete table;
    delete textParser;
    delete randomText;
    delete settings;
    delete characterColorist;
}

QString TypingTestingPage::getMainText()
{
    return mainText;
}

void TypingTestingPage::fillLanguageComboBox(QComboBox *comboBox, const QJsonArray& lessonArray)
{
    MainWindow* mainWindow;
    comboBox->blockSignals(true);
    mainWindow->fillLessonsComboBox(comboBox, lessonArray);
    comboBox->setCurrentIndex(this->settings->value("languageIndex").toInt());
    comboBox->blockSignals(false);
}

void TypingTestingPage::setMainText()
{
    this->randomText->setArray(this->textParser->getTextsArray());
    this->mainText = randomText->pickRandomElement();
    this->_textEdit->setPlainText(this->mainText);
}

void TypingTestingPage::changeLanguage(int languageIndex)
{
    this->settings->setValue("languageIndex", languageIndex);
    this->textParser->updateFields(languageIndex);
    this->setMainText();
}
