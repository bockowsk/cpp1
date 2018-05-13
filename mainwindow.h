#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actioncut_triggered();

    void on_actioncopy_triggered();

    void on_actionZapisz_triggered();

    void on_actionOtworz_triggered();

private:
    Ui::MainWindow *ui;
    void saveToFile(QString filePath);
};

#endif // MAINWINDOW_H
