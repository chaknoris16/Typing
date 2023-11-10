
#include "blindtypingtest.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "vector_of_exercises.h"
#include "resultwindow.h"
class MainWindow;
blindTypingTest::blindTypingTest(MainWindow* mainWindow, QObject *parent) :
    QObject(parent),
    mainWindow(mainWindow)
{

}

void blindTypingTest::colorizeCurrentCharacter(QTextCursor& cursor, QColor color)
{
    if(isFirstSenbool){
        cursor.setPosition(Pos);
        isFirstSenbool = false;
    } else {

        format.setBackground(QBrush(QColor(255, 255, 255)));
        format.setForeground(QBrush(QColor(0, 255, 0)));
        cursor.setCharFormat(format);
        ++Pos;
        cursor.setPosition(Pos);
    }
    cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor);
    selectedText = cursor.selectedText();
    if (!selectedText.isEmpty()) {
        format.setBackground(QBrush(color));
        format.setForeground(QBrush(QColor(255, 255, 255)));

        cursor.setCharFormat(format);
    }
}

void blindTypingTest::colorizeIncorrectCharacter(QTextCursor& cursor, QColor color) {
    format.setBackground(QBrush(color));
    format.setForeground(QBrush(QColor(255, 255, 255)));
    cursor.setCharFormat(format);
}

void blindTypingTest::keyEvent(QKeyEvent *event)
{
    if (!event->text().isEmpty())
    {
        if(mainWindow->inputMethod->locale() == QLocale::English)
        {
            if(event->text().at(0) == tempTextForTesting.at(correctElements))
            {
                this->validCharacterHandler(tempTextForTesting, 2000);
            }else
            {
                this->colorizeIncorrectCharacter(mainWindow->cursor,QColor(255, 0, 0));
                this->Result.incrementErrorCounter();
                Result.set_accuracy(accuracyСalculation(Result.get_errorCounter(), tempTextForTesting));
                mainWindow->ui->procentLabel->setText(QString::number(Result.get_accuracy()));
            }
        }else
        {
            this->incorrectkeyboardlayout();
        }
    }else qDebug()<<event->text()<<"Error";
}

void blindTypingTest::validCharacterHandler(const QString &textForTyping, int flashDurationMs)
{
    if(!this->correctElements)
    {
        this->startTime = QTime::currentTime();

        connect(timer, &QTimer::timeout, this, [=](){
            Result.set_typingSpeed(mainWindow->calculationTypingSpeed(this->startTime, this->correctElements));
            mainWindow->ui->speedCounterLabel_tg->setText(QString::number(Result.get_typingSpeed()));
        });
        timer->start(2000);
    }
    colorizeCurrentCharacter(mainWindow->cursor, QColor(0, 255, 0));
    ++correctElements;
    if(this->correctElements >= textForTyping.size())
    {
        this->timer->stop();
        Result.set_errorCounter(0);
        this->callResultWindow();
        //qDebug()<<mainWindow->getTestingQueryName();
        this->storageResultsInDatabase(mainWindow->getDatabase(), this->Result, "testing_results");
        qDebug()<<"Label is empty";
    }
}

inline int blindTypingTest::accuracyСalculation(int errorCounter, QString &text)
{
    int correctCharacters = text.size() - errorCounter;
    int accuracy = (static_cast<double>(correctCharacters) / text.size()) * 100.0;
    return accuracy;
}

inline void blindTypingTest::incorrectkeyboardlayout()
{
    QMessageBox incorrectkeyboardlayoutMsg;
    incorrectkeyboardlayoutMsg.setText("Incorrect keyboard layout");
    incorrectkeyboardlayoutMsg.setInformativeText("Please change the keyboard layout to English layout.");
    incorrectkeyboardlayoutMsg.exec();
}
void blindTypingTest::callResultWindow()
{
    resultwindow* result_window = new resultwindow(mainWindow);
    result_window->setCounterTypingSpeed(Result.get_typingSpeed());
    result_window->setAccyracyСounter(Result.get_accuracy());
    result_window->offOrOnNextButton(false);
        qDebug()<<Result.get_typingSpeed();
    result_window->exec();
}

void blindTypingTest::storageResultsInDatabase(QSqlDatabase& db, TestingState& Values, const QString queryName)
{
    if(!db.open()){
        qDebug()<<"Database connection error";
    }else {
        QSqlQuery query;
        query.prepare("INSERT INTO " + queryName + " (typing_speed, accuracy, datetime) "
                      "VALUES (:typing_speed, :accuracy, :datetime)");

        query.bindValue(":typing_speed", Values.get_typingSpeed() );
        //qDebug()<<Values.get_typingSpeed();
        query.bindValue(":accuracy", Values.get_accuracy() );
        //qDebug()<<Values.get_accuracy();
        query.bindValue(":datetime", QDateTime::currentDateTime().toString(Qt::ISODate));
        //qDebug()<< QDateTime::currentDateTime().toString(Qt::ISODate);
        if (query.exec()) {
            qDebug() << "Data inserted successfully!";
        } else {
            qDebug() << "Error inserting data:" << query.lastError().text();
        }

        QSqlDatabase::database().close();
    }
}

void blindTypingTest::setupTestingTable(const QString &databaseName)
{
    qDebug()<<"setUPTable";
    QSqlTableModel *modelTesting = new QSqlTableModel(this);
    modelTesting->setTable(databaseName);
    modelTesting->select();
    mainWindow->ui->tableView_Testing->setModel(modelTesting);
    mainWindow->ui->tableView_Testing->hideColumn(modelTesting->fieldIndex("id"));
    mainWindow->ui->tableView_Testing->verticalHeader()->setVisible(false);
    int columnCount_Testing = modelTesting->columnCount();
    for (int col = 0; col < columnCount_Testing; ++col) {
        mainWindow->ui->tableView_Testing->horizontalHeader()->setSectionResizeMode(col, QHeaderView::Stretch);

    }
}

