#include "Login.h"


Login::Login(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

Login::~Login()
{}

void Login::on_loginButton_clicked()
{
    QString username = ui.lineEditpassword->text();
    QString password = ui.lineEditpassword->text();
    if (username == "Pass" && password == "Pass")
    {
        QMessageBox::information(this, "Login", "Username and Password is correct");
        hide();
        Todo = new SecondMainWindow(this);
        Todo->show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username and Password is not correct");
    }
}

