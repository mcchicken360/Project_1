#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QString num;
    num = QString::number(dayCount);
    ui->setupUi(this);
    ui->textBrowser->setTextColor(Qt::yellow);

    ui->textBrowser->insertPlainText("Empty warehouse.\n");
    ui->lcdNumber->setDigitCount(1);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
//    ui->textBrowser_2->insertPlainText(num);
   // ui->textBrowser->setTextBackgroundColor(Qt::blue);
    //set(hObject, 'BackgroundColor', [63, 246,244]);
    ui->textBrowser->setStyleSheet("background-color: rgb(12,133,87);");
    //QMainWindow::QWidget { "background-color: rgb(0, 0, 0);"};
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
    //ui->textBrowser_2->insertPlainText(num);
    ui->lcdNumber->display(num);

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


void MainWindow::on_pushButton_3_clicked() // set warehouse
{
    if(doOnce == 0){
        calledTheWareHouse = true;
        warehouse1.setWareHouse();
        display(warehouse1);
        doOnce++;
    }
    else{
        display(warehouse1);
    }

}

void MainWindow::display(Containers<member>& ware){
    ui->textBrowser->clear();
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
    }
}

void MainWindow::printDaily(Containers<member>& reportList, string dateEnter){
        string date;
        QString Membershiptype;
        QString itemName;
        QString itemCost;
        QString stock;
        QString price;
        QString ID;
        QString qDate;
        QString tax;
        QString memberName;
        qDate = QString::fromStdString(dateEnter);


        ui->textBrowser->clear();
        ui->textBrowser->insertPlainText("***********************************\n");
        ui->textBrowser->insertPlainText("Todays Sales Report: " + qDate + "\n");
        ui->textBrowser->insertPlainText("***********************************\n");

        date = dateEnter;

        double total = 0;
        for (size_t i = 0; i < reportList.getVectorSize(); i++)
        {
            if (reportList.vectorIndex(i).getDate() == date) {

                    memberName = QString::fromStdString(reportList.getmember(reportList.vectorIndex(i).getID()));
                if(!checkName(memberName.toStdString())){
                    ui->textBrowser->insertPlainText("Member Name: " + memberName + "\n");

                    ID = QString::number(reportList.vectorIndex(i).getID());
                    ui->textBrowser->insertPlainText("Member ID:  " + ID + "    \n");

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
        }

        price = QString::number(total);
        ui->textBrowser->insertPlainText("***********************************\n");
        ui->textBrowser->insertPlainText("Subtotal              " + price + "\n");
        double salesTax;
        salesTax = total*0.0875;
        tax = QString::number(QString::number(salesTax, 'f', 2).toDouble(), 'g', 10);
        ui->textBrowser->insertPlainText("TAX 8.75%            " + tax + "\n");
        ui->textBrowser->insertPlainText("***********************************\n");
        total += salesTax;
        price = QString::number(QString::number(total, 'f', 2).toDouble(), 'g', 10);
        ui->textBrowser->insertPlainText("Total revenue of the day:   " + price + "\n");

        yearRevnue += total;
}

void MainWindow::printMemberReport(Containers<member>& temp, int input){
      int num;
      QString item;
      QString price;
      QString EXP;
      QString IdNum;
      QString stock;
      QString member;
      ui->textBrowser->clear();
      double total;
      QString tax;
      double salesTax;

      num = input;
      if (num != 1) {
        int ID;
        QString input = ui->lineEdit->text();
        ID = input.toInt();

        member = QString::fromStdString(warehouse1.getmember(ID));
        if(checkName(member.toStdString())){
            ui->textBrowser->clear();
            ui->textBrowser->insertPlainText("Cant print reciept....\n");
            ui->textBrowser->insertPlainText(member + " no longer a member.");
            return;
        }
        ui->textBrowser->insertPlainText("***************************\n");
        ui->textBrowser->insertPlainText("Member Receipt: " + member + "\n");
        ui->textBrowser->insertPlainText("***************************\n");
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
                  total += temp.vectorIndex(i).getCost()*temp.vectorIndex(i).getQuantity();
            }
        }
        price = QString::number(total);
        ui->textBrowser->insertPlainText("***********************************\n");
        ui->textBrowser->insertPlainText("Subtotal                          " + price + "\n");
        salesTax = total*0.0875;
        tax = QString::number(QString::number(salesTax, 'f', 2).toDouble(), 'g', 10);
        ui->textBrowser->insertPlainText("TAX 8.75%                      " + tax + "\n");
        ui->textBrowser->insertPlainText("***********************************\n");
        total += salesTax;
        price = QString::number(QString::number(total, 'f', 2).toDouble(), 'g', 10);
        ui->textBrowser->insertPlainText("Total revenue of the day:   " + price + "\n");
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
        member = QString::fromStdString(name);
        if(checkName(member.toStdString())){
            ui->textBrowser->clear();
            ui->textBrowser->insertPlainText("Cant print reciept....\n");
            ui->textBrowser->insertPlainText(member + " no longer a member.");
            return;
        }
        ui->textBrowser->insertPlainText("***************************\n");
        ui->textBrowser->insertPlainText("Member Receipt: " + member + "\n");
        ui->textBrowser->insertPlainText("***************************\n");
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
                total += temp.vectorIndex(i).getCost()*temp.vectorIndex(i).getQuantity();
            }
        }
        price = QString::number(total);
        ui->textBrowser->insertPlainText("***********************************\n");
        ui->textBrowser->insertPlainText("Subtotal                          " + price + "\n");
        salesTax = total*0.0875;
        tax = QString::number(QString::number(salesTax, 'f', 2).toDouble(), 'g', 10);
        ui->textBrowser->insertPlainText("TAX 8.75%                      " + tax + "\n");
        ui->textBrowser->insertPlainText("***********************************\n");
        total += salesTax;
        price = QString::number(QString::number(total, 'f', 2).toDouble(), 'g', 10);
        ui->textBrowser->insertPlainText("Total revenue of the day:   " + price + "\n");
      }
}
void MainWindow::on_singleDayPurchase_clicked() //input a member and display there receipt
{
    if(dayCount == 0){
        ui->textBrowser->clear();
        ui->textBrowser->insertPlainText("No days to check.");
        return;
    }
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    int num;
    if(ui->radioButton->isChecked()){
        QString input = ui->lineEdit->text();
        num = input.toInt();

        printMemberReport(warehouse1, num);
    }
    else if(ui->radioButton_2->isCheckable()){
        num = 1;
        printMemberReport(warehouse1, num);
    }
}


void MainWindow::on_exitBut_clicked() //exit and save program
{
    saveFile();
    MainWindow::close();
}


void MainWindow::on_memberReport_clicked()
{
}


void MainWindow::on_bestSelling_clicked() //find best selling item
{
    ui->textBrowser->clear();
    if(warehouse1.getVectorSize() == 0){
        ui->textBrowser->insertPlainText("NO DAYS TO CHECK!\n");
    }
    else{
        bestSellingReport(warehouse1);
    }
}

void MainWindow::bestSellingReport(Containers<member>& temp){
    int num;
    string itemName;
    QString qNames;
    QString qStock;
    QString price;
//    num = temp.vectorIndex(0).getQuantity();
//    itemName = temp.vectorIndex(0).getItem();
//    for(int i = 0; i < temp.getVectorSize(); i++){
//        if(num < temp.vectorIndex(i).getQuantity()){
//            num = temp.vectorIndex(i).getQuantity();
//            itemName = temp.vectorIndex(i).getItem();
//        }
//    }
    int index;
    int max = 0;
    for (int i = 0; i< (warehouse1.itemCount.size() - 1); i++) {
      if(warehouse1.itemCount[i]>max)
        max = warehouse1.itemCount[i];
    }
    for (int i = 0; i<warehouse1.itemCount.size(); i++) {
      if(warehouse1.itemCount[i]==max)
        index =i;
    }
    qNames = QString::fromStdString(warehouse1.itemName[index]);
    qStock = QString::number(warehouse1.itemCount[index]);
    price = QString::number(warehouse1.itemCost[index]);

    ui->textBrowser->insertPlainText("************************\n");
    ui->textBrowser->insertPlainText("****BEST SELLING****!\n");
    ui->textBrowser->insertPlainText("Items:    " + qNames + "\n");
    ui->textBrowser->insertPlainText("Quantity: " + qStock + "\n");
    ui->textBrowser->insertPlainText("Quantity: " + qStock + "\n");
    ui->textBrowser->insertPlainText("************************\n");

}

void MainWindow::setItemContainter(){
    for(int i =0; i< warehouse1.getVectorSize();i++){
        items.pushin(warehouse1.vectorIndex(i));
    }

}

void MainWindow::displayItem(){
    QString item;
    QString price;
    QString EXP;
    QString IdNum;
    QString stock;
    QString memberName;
    ui->textBrowser->clear();
    for (int i = 0; i < (items.getCurrent()-1); i++)
    {

            memberName = QString::fromStdString(warehouse1.getmember(items[i].getID()));
            ui->textBrowser->insertPlainText("Member Name: " + memberName + "\n");

            IdNum = QString::number(items[i].getID());
            ui->textBrowser->insertPlainText("Member ID: " + IdNum + "\n");

            EXP = QString::fromStdString(items[i].getDate());
            ui->textBrowser->insertPlainText("Date: " + EXP + "\n");

            item = QString::fromStdString(items[i].getItem());
            ui->textBrowser->insertPlainText("Item: " + item + "\n");

            price = QString::number(items[i].getCost());
            ui->textBrowser->insertPlainText("price: " + price + "\n");

            stock = QString::number(items[i].getQuantity());
            ui->textBrowser->insertPlainText("Quantities: " + stock + "\n\n");

    }
}
void MainWindow::on_testBut_clicked() // display entire item list
{
    if(!calledTheWareHouse)
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
    else{
        setItemContainter();
        displayItem();
    }
}

void MainWindow::findItem(string s) {
  double price;
  QString itemName;
  QString priceItem;
  QString stock;

  int quantities = 0;
  bool flag = false;
    for(unsigned long i = 0; i <warehouse1.getVectorSize();i++)
    {
      if(warehouse1.vectorIndex(i).getItem() == s) {
        price = warehouse1.vectorIndex(i).getCost();
        quantities+= warehouse1.vectorIndex(i).getQuantity();
        flag = true;
      }
    }
  if(flag) {
    itemName = QString::fromStdString(s);
    ui->textBrowser->insertPlainText("Check Inventory\n");
    ui->textBrowser->insertPlainText("************************\n");
    ui->textBrowser->insertPlainText(itemName + "\n");

    priceItem = QString::number(price);
    ui->textBrowser->insertPlainText("price: " + priceItem + ", ");

    stock = QString::number(quantities);
    ui->textBrowser->insertPlainText("Quantities: " + stock + "\n");

  }
  else{
      ui->textBrowser->insertPlainText("heck Inventory\n");
      ui->textBrowser->insertPlainText("************************\n");
      ui->textBrowser->insertPlainText("No such item exists.\nOr yet sold.");
  }
}

void MainWindow::on_checkInventory_clicked() //Find item
{
    ui->textBrowser->clear();
    if(dayCount == 0){
        ui->textBrowser->insertPlainText("NO DAY TO REPORT.");
    }
    else{
        QString input = ui->lineEdit->text();
        string item;
        item = input.toStdString();
        findItem(item);
    }
}


void MainWindow::on_salesDaily_clicked() //display daily report
{
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    string date = "03/05/2013";
    ui->textBrowser->clear();
    if(dayCount == 0){
        ui->textBrowser->insertPlainText("NO DAY TO REPORT.");
    }
    else{
        int saver;
        saver = dayCount;
        bool flag = true;
        if(ui->checkDate->isChecked()){
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
        else{
            ui->textBrowser->insertPlainText("Invalid date!\n");
        }
        if(!flag){
        printDaily(warehouse1, date);
        dayCount = saver;
        }
    }
}


void MainWindow::on_salesYearly_clicked() //Display yearly sale  report
{
    QString totalRevenue;
    ui->textBrowser->clear();
    if(dayCount == 0){
        ui->textBrowser->insertPlainText("NO DAY TO REPORT.");
    }
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    else{
        setItemContainter();
        displayItem();
        ui->textBrowser->insertPlainText("***********************************\n");
        totalRevenue = QString::number(QString::number(yearRevnue, 'f', 2).toDouble(), 'g', 10);
        ui->textBrowser->insertPlainText("Total revenue of the Year:   " + totalRevenue + "\n");
    }
}

void MainWindow::saveFile(){  //save file
    if(deleteName.getCurrent() == 0){
        return;
    }
    QFile fileName("/Users/davidmei/Project1_super_warehouse_3_3_22/warehouseShoppers.txt");
    if(!fileName.open(QIODevice::WriteOnly)){
        qCritical() << fileName.errorString();
        return;
    }
    QTextStream stream(&fileName);
    for(int i = 0; i < (warehouse1.getCurrent() - 1); i++){
            if(!checkName(warehouse1[i].getName())){
            stream << QString::fromStdString(warehouse1[i].getName()) << Qt::endl;
            stream << QString::number(warehouse1[i].getID()) << Qt::endl;
            stream << QString::fromStdString(warehouse1[i].getMembershiptype()) << Qt::endl;
            stream << QString::fromStdString(warehouse1[i].getEXP()) << Qt::endl;
        }
    }



//        qInfo() << "Writing file...";
//    fileName.write(QByteArray("hello world"));
//    fileName.flush();

//    qInfo() <<  "Reading file....";
//    fileName.seek(0);
//    qInfo() << fileName.readAll();
    fileName.close();
}


bool MainWindow::checkName(string temp){
    for(int i = 0; i < (deleteName.getCurrent()); i++){
        if(temp == deleteName[i]){
            return true;
        }
    }
    return false;
}

void MainWindow::on_removeMem_clicked()
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    QString input = ui->lineEdit->text();
    string name;
    name = input.toStdString();
    deleteName.pushin(name);
    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText("Member remove.... \n" + input);
}


void MainWindow::on_expireMonth_clicked() //find expired membership
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    QString input = ui->lineEdit->text();
    string name;
    name = input.toStdString();
    findExpireExp(name);
}

void MainWindow::findExpireExp(string month){
    bool flag = false;
    for(int i = 0; i < (warehouse1.getCurrent() - 1); i++){
        if (month[0] == warehouse1[i].getEXP()[0] && month[1] == warehouse1[i].getEXP()[1]) {
          ui->textBrowser->clear();
          ui->textBrowser->insertPlainText("Enter a month to see member who exp is the month(2 digit): " + QString::fromStdString(month));
          ui->textBrowser->insertPlainText("\n***********************************\n");
          ui->textBrowser->insertPlainText("EXP:\n");
          QString name;
          QString ID;
          QString Membershiptype;
          QString EXP;

          name = QString::fromStdString(warehouse1[i].getName());
          ID = QString::number(warehouse1[i].getID());
          Membershiptype = QString::fromStdString(warehouse1[i].getMembershiptype());
          EXP = QString::fromStdString(warehouse1[i].getEXP());
          ui->textBrowser->insertPlainText("Member: " + name + "\nID: " + ID + "\nType " + Membershiptype + "\nMonth " + EXP + "\n");

          if (warehouse1[i].getMembershiptype().compare("Preferred") == 0){
               ui->textBrowser->insertPlainText("\nPreferred member...\n");
               ui->textBrowser->insertPlainText("Due amount: $75.\n");
          }
          else{
               ui->textBrowser->insertPlainText("\nBasic member...\n");
               ui->textBrowser->insertPlainText("Due amount: $60.\n");
          }

          flag = true;
        }
    }
    if(!flag){
      ui->textBrowser->clear();
      ui->textBrowser->insertPlainText("No EXP on the month. " + QString::fromStdString(month) +"\n");
      ui->textBrowser->insertPlainText("\n***********************************\n");
      ui->textBrowser->insertPlainText("Enter a month to see member who exp is the month(2 digit): ");
    }
}
