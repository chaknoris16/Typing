#include "virtual_keyboard.h"

#include <QString>
#include <iterator>
#include "mainwindow.h"
class MainWindow;

Virtual_Keyboard::Virtual_Keyboard(MainWindow* mainWindow, QWidget *parent):
    QWidget(parent),
    mainWindow(mainWindow)
{
    this->fillVectorKeyboardButtons(mainWindow->ui);
    this->fillMapWhisPair(this->def_MapSymbolKeyboardButton, this->jsonParser->getCurrentKeyboardLayout().keyboardSymbols, this->keyboardButtons);
    this->fillMapWhisPair(this->shift_MapSymbolKeyboardButton, this->jsonParser->getCurrentKeyboardLayout().shiftKeyboardSymbols, this->keyboardButtons);
}

void Virtual_Keyboard::setMapKeyboardLauout(const QString& keyboardSymbols, const QString& shiftKeyboardSymbols)
{
    qDebug()<<"set keyboard lauout Map";
    this->fillMapWhisPair(this->def_MapSymbolKeyboardButton, keyboardSymbols, this->keyboardButtons);
    this->fillMapWhisPair(this->shift_MapSymbolKeyboardButton, shiftKeyboardSymbols, this->keyboardButtons);
    this->setKeyboardCharacters(this->def_MapSymbolKeyboardButton);
}

void Virtual_Keyboard::fillMapWhisPair(QMap<QString, QPushButton *> &map, QString def_keyboardLayout, QVector<QPushButton *> &keyboardButtons)
{
    if(!def_keyboardLayout.size() == keyboardButtons.size()) throw std::invalid_argument("The dimensions of the containers do not match.");
    map.clear();
    int buttonIndex = 0;
    for (const QString& symbol: def_keyboardLayout) {
        if (buttonIndex < keyboardButtons.size()) {
            map.insert(symbol, keyboardButtons[buttonIndex]);
            ++buttonIndex;
        } else {
            map.insert(symbol, nullptr);
        }
    }
}

void Virtual_Keyboard::changeButtonColorByText(QSet<QChar> *uniqueLetters, QColor color)
{
    *colorSelectTexts = color;
    for (const QChar& c : *uniqueLetters)
    {
       QPushButton* button = this->getButton(c);
       button->setStyleSheet(button->styleSheet() +("color:" + color.name()+ ";"));
    }
}

void Virtual_Keyboard::revertButtonTextColorBack(QSet<QChar> *uniqueLetters)
{
    for (const QChar& c : *uniqueLetters)
    {
        QPushButton* button = this->getButton(c);
        button->setStyleSheet(button->styleSheet().remove(("color:" + colorSelectTexts->name()+";")));
    }
}

void Virtual_Keyboard::changeBorderButton(const QChar& textButton, QString& QSS_Border)
{
    deleteBorderButton(QSS_Border);

    QPushButton* button = this->getButton(textButton);
    button->setStyleSheet(button->styleSheet() + QSS_Border);
    pastButton = button;
}

void Virtual_Keyboard::flashButtonBackground(const QString& textButton, QColor background, int flashDurationMs)
{
    QPushButton* button = this->getButton(textButton[0]);
    QString style = button->styleSheet();

    button->setStyleSheet(style + "background-color:" + background.name() + ";");

    QTimer::singleShot(flashDurationMs, [=]() {
        button->setStyleSheet(style);
    });
}

void Virtual_Keyboard::deleteBorderButton(QString& QSS_Border)
{
    if(!pastButton->styleSheet().isEmpty())
    {
        pastButton->setStyleSheet(pastButton->styleSheet().remove(QSS_Border));
    }
}

void Virtual_Keyboard::setKeyboardCharacters(const QMap<QString, QPushButton*>& symbolAndButton) {
    QMap<QString, QPushButton*>::const_iterator it;
    for (it = symbolAndButton.constBegin(); it != symbolAndButton.constEnd(); ++it) {
        it.value()->setText(it.key());
    }
}

void Virtual_Keyboard::fillVectorKeyboardButtons(Ui::MainWindow *ui)
{
    this->keyboardButtons.push_back(ui->apostropheButton_2);
    this->keyboardButtons.push_back(ui->oneButton_2);
    this->keyboardButtons.push_back(ui->twoButton_2);
    this->keyboardButtons.push_back(ui->threeButton_2);
    this->keyboardButtons.push_back(ui->fourButton_2);
    this->keyboardButtons.push_back(ui->fiveButton_2);
    this->keyboardButtons.push_back(ui->sixButton_2);
    this->keyboardButtons.push_back(ui->sevenButton_2);
    this->keyboardButtons.push_back(ui->eightButton_2);
    this->keyboardButtons.push_back(ui->nineButton_2);
    this->keyboardButtons.push_back(ui->zeroButton_2);
    this->keyboardButtons.push_back(ui->minus_underlineButton_2);
    this->keyboardButtons.push_back(ui->equal_plusButton_2);
    this->keyboardButtons.push_back(ui->Q_Button_2);
    this->keyboardButtons.push_back(ui->W_Button_2);
    this->keyboardButtons.push_back(ui->E_Button_2);
    this->keyboardButtons.push_back(ui->R_Button_2);
    this->keyboardButtons.push_back(ui->T_Button_2);
    this->keyboardButtons.push_back(ui->Y_Button_2);
    this->keyboardButtons.push_back(ui->U_Button_2);
    this->keyboardButtons.push_back(ui->I_Button_2);
    this->keyboardButtons.push_back(ui->O_Button_2);
    this->keyboardButtons.push_back(ui->P_Button_2);
    this->keyboardButtons.push_back(ui->square_bracketButton_2);
    this->keyboardButtons.push_back(ui->square_bracket1Button_2);
    this->keyboardButtons.push_back(ui->backslashButton_2);
    this->keyboardButtons.push_back(ui->A_Button_2);
    this->keyboardButtons.push_back(ui->S_Button_2);
    this->keyboardButtons.push_back(ui->D_Button_2);
    this->keyboardButtons.push_back(ui->F_Button_2);
    this->keyboardButtons.push_back(ui->G_Button_2);
    this->keyboardButtons.push_back(ui->H_Button_2);
    this->keyboardButtons.push_back(ui->J_Button_2);
    this->keyboardButtons.push_back(ui->K_Button_2);
    this->keyboardButtons.push_back(ui->L_Button_2);
    this->keyboardButtons.push_back(ui->semicolonButton_2);
    this->keyboardButtons.push_back(ui->quotation_marksButton_2);
    this->keyboardButtons.push_back(ui->Z_Button_2);
    this->keyboardButtons.push_back(ui->X_Button_2);
    this->keyboardButtons.push_back(ui->C_Button_2);
    this->keyboardButtons.push_back(ui->V_Button_2);
    this->keyboardButtons.push_back(ui->B_Button_2);
    this->keyboardButtons.push_back(ui->N_Button_2);
    this->keyboardButtons.push_back(ui->M_Button_2);
    this->keyboardButtons.push_back(ui->comaButton_2);
    this->keyboardButtons.push_back(ui->pointButton_2);
    this->keyboardButtons.push_back(ui->slashButton_2);
    this->keyboardButtons.push_back(ui->spaceButton_2);
}

QPushButton *Virtual_Keyboard::getButton(const QChar &symbol)
{
    QString smbl = QString(symbol);
    if(this->def_MapSymbolKeyboardButton.contains(smbl))
    {
        return this->def_MapSymbolKeyboardButton[smbl];
    }else if (this->shift_MapSymbolKeyboardButton.contains(smbl)) {
        return this->shift_MapSymbolKeyboardButton[smbl];
    }
    return nullptr;
}

