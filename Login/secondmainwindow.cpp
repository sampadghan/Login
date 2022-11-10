#include "secondmainwindow.h"
#include "ui_secondmainwindow.h"
#include "Login.h"

SecondMainWindow::SecondMainWindow(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::SecondMainWindow)
{
	ui->setupUi(this);
	QString name = "Todo";
	this->setWindowTitle(name);
}

SecondMainWindow::~SecondMainWindow()
{
	delete ui;
}

void SecondMainWindow::on_actionAdd_Task_triggered()
{
	bool ok;
	QString text = QInputDialog::getText(this, tr("Add Task"), tr("Task Name:"), QLineEdit::Normal, tr("Task n"), &ok);
	if (ok && !text.isEmpty())
	{
		ui->listWidgetPending->addItem(text);
	}
}

void SecondMainWindow::on_actionEdit_Task_triggered()
{
	bool ok;
	QListWidgetItem* item = ui->listWidgetPending->takeItem(pending_row_count);
	if (item != nullptr)
	{
		QString itemtext = item->text();
		QString text = QInputDialog::getText(this, tr("Edit Task"), tr("Task Name:"), QLineEdit::Normal, itemtext, &ok);
		if (ok && !text.isEmpty())
		{
			ui->listWidgetPending->addItem(text);
		}
		else
		{
			ui->listWidgetPending->addItem(itemtext);
		}
	}
	
}

void SecondMainWindow::on_actionCompleted_Task_triggered()
{
	bool ok;
	QListWidgetItem* item = ui->listWidgetPending->takeItem(pending_row_count);
	ui->listWidgetCompleted->addItem(item);
}

void SecondMainWindow::on_actionDelete_Pending_Task_triggered()
{
	QListWidgetItem* item = ui->listWidgetPending->takeItem(pending_row_count);
	delete item;
}

void SecondMainWindow::on_actionDeleted_Completed_Task_triggered()
{
	QListWidgetItem* c_item = ui->listWidgetCompleted->takeItem(completed_row_count);
	delete c_item;
}

void SecondMainWindow::on_actionQuit_triggered()
{
	this->close();
}

void SecondMainWindow::on_pushButton_clicked()
{
	Login* W = new Login();
	hide();
	W->show();
}

void SecondMainWindow::on_listWidgetCompleted_currentRowChanged(int currentRow)
{
	completed_row_count = currentRow;
}

void SecondMainWindow::on_listWidgetPending_currentRowChanged(int currentRow)
{
	pending_row_count = currentRow;
}