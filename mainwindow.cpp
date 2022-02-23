#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QString num;
    num = QString::number(dayCount);
    ui->setupUi(this);
    ui->textBrowser->insertPlainText("Empty warehouse.\n");
    ui->textBrowser_2->insertPlainText(num);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() //add days
{
    string fileName;
    ui->textBrowser_2->clear();
    if(dayCount < 5)
    dayCount++;
    QString num;
    num = QString::number(dayCount);
    ui->textBrowser_2->insertPlainText(num);

    switch (dayCount) {
        case 1: fileName = "/Users/davidmei/Project1_super_warehouse_3_3_22/day1.txt";
                break;
        case 2: fileName = "/Users/davidmei/Project1_super_warehouse_3_3_22/day2.txt";
                break;
        case 3: fileName = "/Users/davidmei/Project1_super_warehouse_3_3_22/day3.txt";
                break;
        case 4: fileName = "/Users/davidmei/Project1_super_warehouse_3_3_22/day4.txt";
                break;
        case 5: fileName = "/Users/davidmei/Project1_super_warehouse_3_3_22/day5.txt";
                break;

    }
    warehouse1.addDay(fileName);
    //warehouse1.printMemberReport();
}


void MainWindow::on_pushButton_3_clicked()
{
    warehouse1.setWareHouse();
    display(warehouse1);

}

void MainWindow::display(Containers& ware){
    for(int i = 0; i < 10; i++){
        QString num;
        QString name;
        QString ID;
        QString Membershiptype;
        QString EXP;

        num = QString::number(i + 1);
        ui->textBrowser->insertPlainText("Customer " + num + ": ");

        name = QString::fromStdString(ware[i].getName());
        ID = QString::number(ware[i].getID());
        Membershiptype = QString::fromStdString(ware[i].getMembershiptype());
        EXP = QString::fromStdString(ware[i].getEXP());

        ui->textBrowser->insertPlainText(name + " " + ID + " " + Membershiptype + " " + EXP + "\n");
        //cout << left << setw(21) <<this->name <<" " << left << setw(7) <<this->ID<<" "<< setw(10)  << left <<this->Membershiptype<<" "<< left << setw(11)<<this->EXP<<endl;

    }
}

void MainWindow::printDaily(Containers& reportList, string dateEnter){
        string date;
        QString Membershiptype;
        QString itemName;
        QString itemCost;
        QString stock;
        QString price;
        QString ID;
        QString qDate;
        qDate = QString::fromStdString(dateEnter);


        ui->textBrowser->clear();
        ui->textBrowser->insertPlainText("Todays Date: " + qDate + "\n");

        date = dateEnter;

        double total = 0;
        for (size_t i = 0; i < reportList.getVectorSize(); i++)
        {
            if (reportList.vectorIndex(i).getDate() == date) {
                ID = QString::number(reportList.vectorIndex(i).getID());
                ui->textBrowser->insertPlainText("Member ID:  " + ID + "    ");

                for(int j = 0; j < reportList.getCurrent(); j++) {
                  if(reportList.vectorIndex(i).getID()== reportList[j].getID()){
                      Membershiptype = QString::fromStdString(reportList[j].getMembershiptype());
                      ui->textBrowser->insertPlainText("MemberType: " + Membershiptype + "\n");
                  }
                }
                  itemName = QString::fromStdString(reportList.vectorIndex(i).getItem());
                  ui->textBrowser->insertPlainText("Item: " + itemName + "\n");

                  itemCost = QString::number(reportList.vectorIndex(i).getCost());
                  ui->textBrowser->insertPlainText("price: " + itemCost + "    ");

                  stock = QString::number(reportList.vectorIndex(i).getQuantity());
                  ui->textBrowser->insertPlainText("Quantities: " + stock + "\n\n");
                total += reportList.vectorIndex(i).getCost()*reportList.vectorIndex(i).getQuantity();
            }
        }
        price = QString::number(total);
        ui->textBrowser->insertPlainText("Total revenue of the day:   " + price + "\n");
}

void MainWindow::printMemberReport(Containers& temp, int input){
      int num;
      QString item;
      QString price;
      QString EXP;
      QString IdNum;
      QString stock;
      ui->textBrowser->clear();

      num = input;
      if (num != 1) {
        int ID;
        QString input = ui->lineEdit->text();
        ID = input.toInt();

        for (size_t i = 0; i < (temp.getVectorSize() - 1); i++)
        {
            if (temp.vectorIndex(i).getID() == ID) {
                  IdNum = QString::number(ID);
                  ui->textBrowser->insertPlainText("Member ID: " + IdNum + "\n");

                  EXP = QString::fromStdString(temp.vectorIndex(i).getDate());
                  ui->textBrowser->insertPlainText("Date: " + EXP + "\n");

                  item = QString::fromStdString(temp.vectorIndex(i).getItem());
                  ui->textBrowser->insertPlainText("Item: " + item + "\n");

                  price = QString::number(temp.vectorIndex(i).getCost());
                  ui->textBrowser->insertPlainText("price: " + price + "\n");

                  stock = QString::number(temp.vectorIndex(i).getQuantity());
                  ui->textBrowser->insertPlainText("Quantities: " + stock + "\n\n");
            }
        }
      }
      else {
        string name;
        int ID = 0;

        QString input = ui->lineEdit->text();
        name = input.toStdString();
        for(int i = 0; i < (temp.getCurrent() - 1); i++){
            if (name == temp[i].getName()) {
              ID = temp[i].getID();
            }
        }
        for (size_t i = 0; i < (temp.getVectorSize() - 1); i++)
        {
            if (temp.vectorIndex(i).getID() == ID) {
                IdNum = QString::number(temp.vectorIndex(i).getID());
                ui->textBrowser->insertPlainText("Member ID: " + IdNum + "\n");

                EXP = QString::fromStdString(temp.vectorIndex(i).getDate());
                ui->textBrowser->insertPlainText("Date: " + EXP + "\n");

                item = QString::fromStdString(temp.vectorIndex(i).getItem());
                ui->textBrowser->insertPlainText("Item: " + item + "\n");

                price = QString::number(temp.vectorIndex(i).getCost());
                ui->textBrowser->insertPlainText("price: " + price + "\n");

                stock = QString::number(temp.vectorIndex(i).getQuantity());
                ui->textBrowser->insertPlainText("Quantities: " + stock + "\n\n");
            }
        }
      }
}
void MainWindow::on_singleDayPurchase_clicked()
{
    string date = "03/05/2013";
    ui->textBrowser->clear();
    if(dayCount == 0){
        ui->textBrowser->insertPlainText("NO DAY TO REPORT.");
    }
    else{
        int saver;
        saver = dayCount;
        bool flag = true;
        if(ui->radioButton_2->isChecked()){
                QString input = ui->lineEdit->text();
                date = input.toStdString();
              if (dayCount >= 1 && date == "03/05/2013") {
                flag = false;
              }
              else if (dayCount >= 2 && date == "03/06/2013") {
                flag = false;
              }
              else if (dayCount >= 3 && date == "03/07/2013") {
                flag = false;
              }
              else if (dayCount >= 4 && date == "03/13/2013") {
                flag = false;
              }
              else if (dayCount >= 5 && date == "03/09/2013") {
                flag = false;
              }
              else {
                ui->textBrowser->clear();
                ui->textBrowser->insertPlainText("Invalid date!\n");
                return;
              }
        }
        if(!flag){
        printDaily(warehouse1, date);
        dayCount = saver;
        }
    }
}


void MainWindow::on_exitBut_clicked()
{
    MainWindow::close();
}


void MainWindow::on_memberReport_clicked()
{
    //      do {
    //        printf("Please enter 0 or 1, 0 for entry ID to get report, 1 for entry member name to get the reprot:");
    //        scanf("%d", &num);
    //        if (num == 0 || num == 1) {
    //          flag = false;
    //        }
    //        else {
    //          flag = true;
    //          printf("Invaid input!\n");
    //        }
    //        cin.ignore();
    //      } while (flag);
    int num;
    if(ui->radioButton->isChecked() && ui->radioButton_3->isChecked()){
        QString input = ui->lineEdit->text();
        num = input.toInt();

        printMemberReport(warehouse1, num);
//        else {
//          ui->textBrowser->clear();
//          ui->textBrowser->insertPlainText("Invalid Input!\n");
//        }
    }
    else if(ui->radioButton_2->isCheckable() && ui->radioButton_4->isChecked()){
        num = 1;
        printMemberReport(warehouse1, num);
    }
}

