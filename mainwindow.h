#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "containers.h"
#include <QFile>

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
    void display(Containers<member>&);
    void printDaily(Containers<member>&, string);
    void printMemberReport(Containers<member>&, int);
    void displayItem();
    void on_pushButton_3_clicked();
    void saveFile();

    bool checkName(string);





    void on_singleDayPurchase_clicked();

    void on_exitBut_clicked();

    void on_memberReport_clicked();

    void on_bestSelling_clicked();
    void bestSellingReport(Containers<member>&);
    void setItemContainter();
    void findExpireExp(string);

    void on_testBut_clicked();

    void on_checkInventory_clicked();

    void on_salesDaily_clicked();

    void on_salesYearly_clicked();
    void findItem(string s);

    void on_removeMem_clicked();

    void on_expireMonth_clicked();

private:
    Ui::MainWindow *ui;
    int dayCount = 0;
    int yearRevnue = 0;
    int doOnce = 0;
    Containers<member> warehouse1;
    Containers<Item> items;
    Containers<string> deleteName;
    bool calledTheWareHouse = false;
};
#endif // MAINWINDOW_H
