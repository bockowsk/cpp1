#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actioncut_triggered()
{
    ui->textEdit->cut();
    ui->menuBar->colorCount();

}

void MainWindow::on_actioncopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionZapisz_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save the file");
    saveToFile(filePath);
}

void MainWindow::on_actionOtworz_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

        QFile file(fileName);
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "..", "File has not been opened");
            return;
        }

        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());

        file.close();
}
