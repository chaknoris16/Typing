#ifndef TYPINGTESTINGPAGE_H
#define TYPINGTESTINGPAGE_H

#include <QObject>
#include <QTextEdit>
#include <QTextCursor>
#include <QTableWidget>
#include "IDBManager.h"
#include "DBTestingQuery.h"
#include "tableoutput.h"
#include "mainwindow.h"
#include "jsonconfigparser.h"
#include "IJsonTextParser.h"
#include "RandomElementPicker.h"
#include "IRandomTextProvider.h"
#include "IColorizeCharacter.h"
#include "CharacterColorist.h"
#include <QSettings>
#include <QString>
#include <QComboBox>
class TypingTestingPage : public QObject
{
    Q_OBJECT
public:
    explicit TypingTestingPage(QTextEdit* textEdit = nullptr, QObject *parent = nullptr, QTableWidget* tableWidget = nullptr, QComboBox* comboBox = nullptr);
    ~TypingTestingPage();
    QString getMainText();
    void fillLanguageComboBox(QComboBox* comboBox, const QJsonArray &lessonArray);
    void setMainText();
    const QJsonArray getLyricsArray() const
    {
       return textParser->getLuricsArray();
    }
signals:
    void setAcyracyCounter(const QString& procentCount);
    void setSpeedCounter(const QString& typingSpeedCount);
public slots:
    void changeLanguage(int languageIndex);
private:
    QString mainText;
    QTextEdit* _textEdit;
    QTableWidget* _outPutTable;
    QComboBox* _comboBox;
    IDBManager* db = new DBTestingQuery("typing_result", "testingResult");
    TableOutPut* table = new TableOutPut(_outPutTable);
    IJsonTextParser* textParser = new JsonTextParser("lyrics.json");
    IRandomTextProvider* randomText = new RandomElementPicker(textParser->getTextsArray());
    IColorizeCharacter* characterColorist = new CharacterColorist();
    QSettings* settings;
    //QTextCursor* textCursor = new QTextCursor(textEdit->textCursor());
};

#endif // TYPINGTESTINGPAGE_H
