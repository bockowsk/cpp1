#include "mainwindow.h"
#include <QApplication>

void saveToFile(QString filePath)
{
    QFile file(filePath);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        return;
    }

    QTextStream out(&file);
    //out << ui->textEdit->toPlainText();
    out << ui->textEdit->toHtml();
    file.flush();
    file.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
