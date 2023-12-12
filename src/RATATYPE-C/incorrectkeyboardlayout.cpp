#include "incorrectkeyboardlayout.h"
#include "ui_incorrectkeyboardlayout.h"
#include <QString>
IncorrectKeyboardLayout::IncorrectKeyboardLayout(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IncorrectKeyboardLayout)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &IncorrectKeyboardLayout::close);
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(4);
    shadowEffect->setColor(QColor(0, 0, 0, 63));
    shadowEffect->setOffset(2, 4);
    ui->pushButton->setGraphicsEffect(shadowEffect);
    ui->label_2->setGraphicsEffect(shadowEffect);
}

IncorrectKeyboardLayout::~IncorrectKeyboardLayout()
{
    delete ui;
}

void IncorrectKeyboardLayout::setMessge(QLocale &requiredLocale)
{
    ui->label_2->setText(QString("Please change the keyboard layout to %1 Layout").arg(QLocale::languageToString(requiredLocale.language())));

}
