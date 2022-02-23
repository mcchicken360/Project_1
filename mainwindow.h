#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "containers.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void display(Containers&);
    void printDaily(Containers&, string);
    void printMemberReport(Containers&, int);
    void on_pushButton_3_clicked();



    void on_singleDayPurchase_clicked();

    void on_exitBut_clicked();

    void on_memberReport_clicked();

private:
    Ui::MainWindow *ui;
    int dayCount = 0;
    Containers warehouse1;
};
#endif // MAINWINDOW_H
