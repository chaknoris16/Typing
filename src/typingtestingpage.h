#ifndef TYPINGTESTINGPAGE_H
#define TYPINGTESTINGPAGE_H

#include <QObject>
#include <QTextEdit>
#include <QTextCursor>
#include <QTableWidget>
#include "IDBManager.h"
#include "DBTestingQuery.h"
#include "tableoutput.h"

#include "jsonconfigparser.h"
#include "IJsonTextParser.h"
#include "json_text_parser.h"
#include "RandomElementPicker.h"
#include "IRandomTextProvider.h"
#include "IColorizeCharacter.h"
#include "CharacterColorist.h"
#include "ITypingSpeedCalculator.h"
#include "TypingSpeedCalculator.h"
#include "keyboardlayoutlanguagecontroller.h"
#include "ComboBoxManager.h"
#include <QTimer>
#include <QSettings>
#include <QString>
#include <QComboBox>
class TypingTestingPage : public QObject
{
    Q_OBJECT
public:
    TypingTestingPage(QTextEdit* textEdit = nullptr, QObject *parent = nullptr, CustomComboBox* comboBox = nullptr);
    ~TypingTestingPage();

    void fillLanguageComboBox(CustomComboBox *comboBox, const QJsonArray &lessonArray);

    const QJsonArray getLyricsArray() const
    {
       return textParser->getLuricsArray();
    }
    QSqlQuery getQuery();
signals:
    void setAcyracyCounter(const QString& procentCount);
    void setSpeedCounter(const QString& typingSpeedCount);
public slots:
    void changeLanguage(int languageIndex);
    void keyEvent(QKeyEvent *event);
    void setMainText();
private:
    QLocale defLocale;
    QString mainText;
    QTextEdit* _textEdit;
    QComboBox* _comboBox;
    KeyboardLayoutLanguageController* keyboardLayoutController = new KeyboardLayoutLanguageController(_textEdit);
    IDBManager* db = new DBTestingQuery("typing_result", "testingResult");
    TableOutPut* table = new TableOutPut();
    IJsonTextParser* textParser = new JsonTextParser(":/fails/lyrics.json");
    IRandomTextProvider* randomText = new RandomElementPicker(textParser->getTextsArray());
    IColorizeCharacter* characterColorist = new CharacterColorist();
    ITypingSpeedCalculator* typingSpeedCalculator = new TypingSpeedCalculator();
    QSettings* settings;
    inline int accuracyСalculation(int errorCounter, const QString &text);
    void validCharacterHandler(const QString& textForTyping);
    QTime startTime;
    QTimer* timer = new QTimer(this);
    QTextCursor cursor = _textEdit->textCursor();
    void callResultWindow();
    int typingSpeed = 0;
    int accuracy = 100;
    int correctElements = 0;
    int errorCounter = 0;
    void counterReset();
};

#endif // TYPINGTESTINGPAGE_H
