#ifndef INCORRECTKEYBOARDLAYOUT_H
#define INCORRECTKEYBOARDLAYOUT_H

#include <QDialog>
#include <QGraphicsDropShadowEffect>
namespace Ui {
class IncorrectKeyboardLayout;
}

class IncorrectKeyboardLayout : public QDialog
{
    Q_OBJECT

public:
    explicit IncorrectKeyboardLayout(QWidget *parent = nullptr);
    ~IncorrectKeyboardLayout();
    void setMessge(QLocale& requiredLocale);
private:
    Ui::IncorrectKeyboardLayout *ui;
};

#endif // INCORRECTKEYBOARDLAYOUT_H
