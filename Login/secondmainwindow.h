#ifndef SECONDMAINWINDOW_H
#define SECONDMAINWINDOW_H

#include <QMainWindow>
#include <qinputdialog.h>

namespace Ui {
class SecondMainWindow;
}

class SecondMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondMainWindow(QWidget *parent = nullptr);
    ~SecondMainWindow();

private slots:
    void on_actionAdd_Task_triggered();

    void on_actionEdit_Task_triggered();

    void on_actionCompleted_Task_triggered();

    void on_actionDelete_Pending_Task_triggered();

    void on_actionDeleted_Completed_Task_triggered();

    void on_actionQuit_triggered();

    void on_pushButton_clicked();

    void on_listWidgetCompleted_currentRowChanged(int currentRow);

    void on_listWidgetPending_currentRowChanged(int currentRow);

private:
    Ui::SecondMainWindow *ui;

    int pending_row_count = -1;
    int completed_row_count = -1;
};

#endif // SECONDMAINWINDOW_H
