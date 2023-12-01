#include "typingtestingpage.h"
#include "mainwindow.h"
#include "resultwindow.h"
TypingTestingPage::TypingTestingPage(QTextEdit *textEdit, QObject *parent,QComboBox *comboBox)
    : QObject{parent},
    _textEdit{textEdit},
    _comboBox{comboBox}
{
    this->settings = new QSettings("MySoft", "Star Runner");

    this->textParser->updateFields(this->settings->value("languageIndex").toInt());

}
TypingTestingPage::TypingTestingPage() {}
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
    qDebug()<<"setMainText";
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
}

void TypingTestingPage::keyEvent(QKeyEvent *event)
{
    if (!event->text().isEmpty())
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
        result << this->typingSpeed << this->accuracy;
        this->db->saveResult(result);
        qDebug()<<"Label is empty";
    }
}

void TypingTestingPage::callResultWindow()
{
    resultwindow* result_window = new resultwindow();
    connect(result_window, &resultwindow::againSignal, this, &TypingTestingPage::setMainText);
    result_window->setCounterTypingSpeed(this->typingSpeed);
    result_window->setAccyracyСounter(this->accuracy);
    result_window->offOrOnNextButton(false);
    result_window->exec();

    result_window->deleteLater();
}
