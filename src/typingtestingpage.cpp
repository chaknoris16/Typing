#include "typingtestingpage.h"
#include "mainwindow.h"
#include "resultwindow.h"
TypingTestingPage::TypingTestingPage(QTextEdit *textEdit, QObject *parent, CustomComboBox *comboBox)
    : QObject{parent},
    _textEdit{textEdit},
    _comboBox{comboBox}
{
    this->settings = new QSettings("MySoft", "Star Runner");

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
    delete typingSpeedCalculator;
}

void TypingTestingPage::fillLanguageComboBox(CustomComboBox *comboBox, const QJsonArray& lessonArray)
{
    ComboBoxManager comboBoxManager;
    comboBox->blockSignals(true);
    comboBoxManager.fillLessonsComboBox(comboBox, lessonArray, lessonArray.size());
    comboBox->setCurrentIndex(this->settings->value("languageIndex").toInt());
    comboBox->blockSignals(false);
    this->defLocale = this->keyboardLayoutController->determineLocale(this->textParser->getLanguage());
}

void TypingTestingPage::setMainText()
{
    qDebug()<<"setMainText";
    this->counterReset();
    this->randomText->setArray(this->textParser->getTextsArray());
    this->mainText = randomText->pickRandomElement();
    this->_textEdit->clear();
    this->_textEdit->setPlainText(this->mainText);
    this->_textEdit->setReadOnly(true);
    this->_textEdit->setTextInteractionFlags(Qt::TextSelectableByMouse);
    this->cursor.movePosition(QTextCursor::Start);
    this->characterColorist->setIsFirstSymbol(true);
    this->characterColorist->setPos(0);
    this->characterColorist->colorizeCorrectCharacter(cursor, QColor(0, 255, 0));
}

QSqlQuery TypingTestingPage::getQuery()
{
    return this->db->getQuery();
}

void TypingTestingPage::changeLanguage(int languageIndex)
{
    this->settings->setValue("languageIndex", languageIndex);
    this->textParser->updateFields(languageIndex);
    this->setMainText();
    this->defLocale = this->keyboardLayoutController->determineLocale(this->textParser->getLanguage());
}

void TypingTestingPage::keyEvent(QKeyEvent *event)
{
    if (!event->text().isEmpty())
    {
        if(this->keyboardLayoutController->checkLanguageMatch(this->defLocale))
        {
            if(event->text().at(0) == this->mainText.at(correctElements))
            {
                this->validCharacterHandler(this->mainText);
            }else
            {
                this->characterColorist->colorizeIncorrectCharacter(cursor, QColor(255, 0, 0));
                this->errorCounter++;
                this->accuracy = accuracyСalculation(this->errorCounter, this->mainText);
                emit this->setAcyracyCounter(QString::number(this->accuracy));
            }
        }else this->keyboardLayoutController->setIncorectKeyboardLauoutMessage(this->defLocale);
    }else qDebug()<<event->text()<<"Error";
}

inline int TypingTestingPage::accuracyСalculation(int errorCounter, const QString &text)
{
    int correctCharacters = text.size() - errorCounter;
    int accuracy = (static_cast<double>(correctCharacters) / text.size()) * 100.0;
    return accuracy;
}

void TypingTestingPage::validCharacterHandler(const QString &textForTyping)
{
    if(!this->correctElements)
    {
        this->startTime = QTime::currentTime();

        connect(timer, &QTimer::timeout, this, [=](){
            this->typingSpeed = this->typingSpeedCalculator->calculationTypingSpeed(this->startTime, this->correctElements);
            emit this->setSpeedCounter(QString::number(this->typingSpeed));
        });
        timer->start(2000);
    }
    this->characterColorist->colorizeCorrectCharacter(cursor, QColor(0, 255, 0));
    ++correctElements;
    if(this->correctElements >= textForTyping.size())
    {
        this->timer->stop();
        this->errorCounter = 0;
        this->callResultWindow();
        QVariantList result;
        result <<this->textParser->getLanguage()<< this->typingSpeed << this->accuracy;
        this->db->saveResult(result);
        qDebug()<<"Label is empty";
    }
}

void TypingTestingPage::callResultWindow()
{
    resultwindow* resultWindow = new resultwindow();
    connect(resultWindow, &resultwindow::againSignal, this, &TypingTestingPage::setMainText);
    resultWindow->setCounterTypingSpeed(this->typingSpeed);
    resultWindow->setAccyracyСounter(this->accuracy);
    resultWindow->offOrOnNextButton(false);
    resultWindow->exec();

    resultWindow->deleteLater();
}

void TypingTestingPage::counterReset()
{
    this->typingSpeed = 0;
    this->accuracy = 100;
    this->correctElements = 0;
    this->errorCounter = 0;
    emit this->setSpeedCounter(QString::number(0));
    emit this->setAcyracyCounter(QString::number(100));
}
