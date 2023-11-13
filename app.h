#ifndef APP_H
#define APP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class app : public QMainWindow
{
    Q_OBJECT

public:
    app(QWidget *parent = nullptr);
    ~app();

private slots:

    void numberButtonClicked();
    void mathButtonClicked();
    void on_Equal_clicked();
    void on_AC_clicked();
    void on_ChangeSign_clicked();
    void on_Comma_clicked();

private:
    Ui::Calculator *ui;

    QString userInput;
    QString displayValue = NULL;

    double first_num;
    double second_num;
    double solution;

    bool mathPressed;

    bool negSet;
    bool sum;
    bool subtraction;
    bool division;
    bool multiplication;
    bool squareRoot;
    bool commaSet;
    bool powerTo;
};
#endif // APP_H
