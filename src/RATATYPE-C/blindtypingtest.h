#ifndef BLINDTYPINGTEST_H
#define BLINDTYPINGTEST_H

#include <QObject>
#include <QInputMethod>
#include <QTime>
#include <QTimer>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlError>
#include <QTextCursor>
#include <jsonconfigparser.h>
#include <QRandomGenerator>
#include <QList>
#include <QSettings>
#include <QJsonArray>
class MainWindow;
class blindTypingTest : public QObject
{
    Q_OBJECT 
public:
    explicit blindTypingTest(MainWindow* mainWindow, QObject *parent = nullptr);
    void keyEvent(QKeyEvent *event);
    QTime startTime;
    QString mainText;
    JsonTextParser* textParser = new JsonTextParser("lyrics.json");
private:
    MainWindow* mainWindow;
    QTimer* timer = new QTimer(this);
    QSettings* setting;


    struct TestingState{
    private:
        int typingSpeed = 0;
        int errorCounter = 0;
        int accuracy = 100;

    public:
        int get_accuracy() const
        {
            return accuracy;
        }

        int get_errorCounter() const
        {
            return errorCounter;
        }

        int get_typingSpeed() const
        {
            return typingSpeed;
        }

        void set_errorCounter(int value)
        {
            errorCounter = value;
        }

        void set_typingSpeed(int value)
        {
            typingSpeed = value;
        }
        void set_accuracy(int value_accuracy)
        {
            accuracy = value_accuracy;
        }
        void incrementErrorCounter() {
            errorCounter++;
        }
    };
    TestingState Result;
    bool isFirstSenbool = true;
public:
    QTextCursor cursor;
    QTextCharFormat format;
    QString selectedText;
    int Pos = 0;
    int correctElements = 0;
    void signalsAndSlots();
    void validCharacterHandler(const QString& textForTyping);
    void colorizeCurrentCharacter(QTextCursor& cursor, QColor color);
    void colorizeIncorrectCharacter(QTextCursor &cursor, QColor color);
    inline int accuracyСalculation(int errorCounter, QString &text);
    int calculationTypingSpeed(QTime& startTime);
    inline void incorrectkeyboardlayout();
    void callResultWindow();
    void storageResultsInDatabase(QSqlDatabase &db, TestingState &Values, const QString queryName);

    class RandomElementPicker {
    public:
        RandomElementPicker() {}
        RandomElementPicker(const QJsonArray& array) : array_(array) {}

        QJsonValue pickRandomElement()
        {
            if(array_.isEmpty()) {
                qDebug() << "Array is empty.";
                return QJsonValue();
            }
            int randomIndex = QRandomGenerator::global()->bounded(array_.size());
            QJsonValue randomElement = array_.at(randomIndex);
            array_.removeAt(randomIndex);

            return randomElement;
        }
        void setArray(const QJsonArray& array) {
            array_ = array;
        }
    private:
        QJsonArray array_;
    };
private:
    QString getTextForTypingTest(QJsonArray array, RandomElementPicker& randElementPick);
    RandomElementPicker randElementPick;
public slots:
    void setupTestingTable(const QString &databaseName);
    void languageChange(int index);
};

#endif // BLINDTYPINGTEST_H
