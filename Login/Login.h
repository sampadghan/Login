#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Login.h"
#include <qmessagebox.h>
#include "secondmainwindow.h"

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_loginButton_clicked();

private:
    Ui::LoginClass ui;
    SecondMainWindow* Todo = nullptr;
};
