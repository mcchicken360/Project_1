#include "mainwindow.h"
#include "ui_mainwindow.h"

/***********************************************************
 *
 * Method MainWindow: Class MainWindow
 *_________________________________________________________
 * This method is automatically called with the program runs.
 * Here we have function to open the deleteName.txt file and
 * change background color for the GUI.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   set the GUI
***********************************************************/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QString num;
    num = QString::number(dayCount);
    addRemoveNames();
    ui->setupUi(this);
    ui->textBrowser->setTextColor(Qt::yellow);

    ui->textBrowser->insertPlainText("Empty warehouse.\n");
    ui->lcdNumber->setDigitCount(1);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);

    ui->textBrowser->setStyleSheet("background-color: rgb(12,133,87);");

}

/***********************************************************
 *
 * Deconstrutor ~MainWindow: Class MainWindow
 *_________________________________________________________
 * Deconstuct the mainwindow class ui.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   de-initialize the mainWindow class
***********************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

/***********************************************************
 *
 * Method addRemoveNames: Class MainWindow
 *_________________________________________________________
 * This method reads the delete name txt file and store the
 * previous deleted names into a delete member container.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   open a file and store deleted member
***********************************************************/
void MainWindow::addRemoveNames(){
    string fileName = "/Users/davidmei/Project1_super_warehouse_3_3_22/deleteNames.txt";
    ifstream myFile(fileName);
    string name;
    if(myFile.fail()){
        exit(1);
    }
        getline(myFile, name, '\n');
    while (!myFile.eof()) {
        deleteName.pushin(name);
        getline(myFile, name, '\n');
    }
    myFile.close();
}

/***********************************************************
 *
 * Method on_pushButton_clicked: Class MainWindow
 *_________________________________________________________
 * This method is the add day button that adds a new day
 * into the item container. Calling the add day function
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   adds a new day
***********************************************************/
void MainWindow::on_pushButton_clicked() //add days
{
    if(dayCount == 5)
        return;
    string fileName;
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
    counter = warehouse1.getVectorSize();
    countItems.pushin((counter - beforeCount));
    beforeCount = counter;
    //warehouse1.printMemberReport();
}

/***********************************************************
 *
 * Method on_printAll_clicked: Class MainWindow
 *_________________________________________________________
 * The GUI button called warehouse info should set and create
 * a warehouse container and store member types. The function
 * should also called the display function.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   set and display the warehouse txt
***********************************************************/
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

/***********************************************************
 *
 * Method display: Class MainWindow
 *_________________________________________________________
 * This method display the warehouse txt file. Showing the
 * memebers information
 *_________________________________________________________
 * PRE-CONDITIONS
 *   ware: A container for member types
 *
 * POST-CONDITIONS
 *   prints the member info
***********************************************************/
void MainWindow::display(Containers<member>& ware){
    ui->textBrowser->clear();
    for(int i = 0; i < (ware.getCurrent() - 1); i++){

        QString num;
        QString name;
        QString ID;
        QString Membershiptype;
        QString EXP;

        name = QString::fromStdString(ware[i].getName());
        ID = QString::number(ware[i].getID());
        Membershiptype = QString::fromStdString(ware[i].getMembershiptype());
        EXP = QString::fromStdString(ware[i].getEXP());
        if(ui->radioButton_3->isChecked()){
            if(ware[i].getMembershiptype() == "Basic"){
                num = QString::number(i + 1);
                ui->textBrowser->insertPlainText("Customer " + num + ": ");

                ui->textBrowser->insertPlainText(name + " " + ID + " " + Membershiptype + " " + EXP + "\n");
            }
        }
        else if(ui->radioButton_4->isChecked()){
            if(ware[i].getMembershiptype() == "Preferred"){
                num = QString::number(i + 1);
                ui->textBrowser->insertPlainText("Customer " + num + ": ");
                ui->textBrowser->insertPlainText(name + " " + ID + " " + Membershiptype + " " + EXP + "\n");
            }
        }
        else{
            num = QString::number(i + 1);
            ui->textBrowser->insertPlainText("Customer " + num + ": ");
            ui->textBrowser->insertPlainText(name + " " + ID + " " + Membershiptype + " " + EXP + "\n");
        }

    }
}

/***********************************************************
 *
 * Method printDaily: Class MainWindow
 *_________________________________________________________
 * A sales report for any given day. It should include a
 * list of items and quantities sold on that day as well as
 * names of the members who shopped that day.  Report the
 * total revenue for the given day.  It should also include
 * the number of preferred members and basic members who
 * shopped during the given day
 *_________________________________________________________
 * PRE-CONDITIONS
 *   - reportList: a container for member types
 *   - dateEnter : a date
 *
 * POST-CONDITIONS
 *  prints the daily report
***********************************************************/
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

/***********************************************************
 *
 * Method printMemberReport: Class MainWindow
 *_________________________________________________________
 * A user should be able to enter a membership number or
 * name and get a list of the total purchases per that member.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   prints the member and display there receipt
***********************************************************/
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
      total = 0;
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

        for (size_t i = 0; i < (temp.getVectorSize()); i++)
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
                  total = total + temp.vectorIndex(i).getCost()*temp.vectorIndex(i).getQuantity();
            }
        }
        ui->textBrowser->insertPlainText("***********************************\n");
        ui->textBrowser->insertPlainText("Subtotal                          " + QString::number(total) + "\n");
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
        bool exist = true;

        QString input = ui->lineEdit->text();
        name = input.toStdString();

        for(int i = 0; i < (temp.getCurrent() - 1); i++){
            if (name == temp[i].getName()) {
              ID = temp[i].getID();
              exist = false;
              break;
            }
        }

        if(exist){
            ui->textBrowser->clear();
            ui->textBrowser->insertPlainText("Cant print reciept....\n");
            ui->textBrowser->insertPlainText("Invalid input.\n");
            return;
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
        for (size_t i = 0; i < (temp.getVectorSize()); i++)
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
                total = total + temp.vectorIndex(i).getCost()*temp.vectorIndex(i).getQuantity();
            }
        }
        //price = QString::number(total);
        ui->textBrowser->insertPlainText("***********************************\n");
        ui->textBrowser->insertPlainText("Subtotal                          " + QString::number(total) + "\n");
        salesTax = total*0.0875;
        tax = QString::number(QString::number(salesTax, 'f', 2).toDouble(), 'g', 10);
        ui->textBrowser->insertPlainText("TAX 8.75%                      " + tax + "\n");
        ui->textBrowser->insertPlainText("***********************************\n");
        total += salesTax;
        price = QString::number(QString::number(total, 'f', 2).toDouble(), 'g', 10);
        ui->textBrowser->insertPlainText("Total revenue of the day:   " + price + "\n");
      }
}

/***********************************************************
 *
 * Method on_singleDayPurchase_clicked: Class MainWindow
 *_________________________________________________________
 * A user should be able to enter a membership number or
 * name and get a list of the total purchases per that member.
 * The GUI has a button to call the print member report
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   calls the print member report function
***********************************************************/
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
        bool exist = true;
        for(size_t i = 0; i < (warehouse1.getVectorSize()); i++){
            if(num == warehouse1.vectorIndex(i).getID()){
                exist = false;
                break;
            }
        }
        if(exist){
            ui->textBrowser->clear();
            ui->textBrowser->insertPlainText("Cant print reciept....\n");
            ui->textBrowser->insertPlainText("Invalid input.\n");
            return;
        }

        printMemberReport(warehouse1, num);
    }
    else if(ui->radioButton_2->isCheckable()){
        num = 1;
        printMemberReport(warehouse1, num);
    }
}

/***********************************************************
 *
 * Method on_exitBut_clicked: Class MainWindow
 *_________________________________________________________
 * A button that exit the GUI. Before the program ends
 * add all the new members and item into the txt files.
 * This will save all the changes.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   save and exit the GUI
***********************************************************/
void MainWindow::on_exitBut_clicked() //exit and save program
{
    saveFile();
    saveItem();
    saveRemoveNames();

    MainWindow::close();
}

/***********************************************************
 *
 * Method on_bestSelling_clicked: Class MainWindow
 *_________________________________________________________
 * This method is the button in the GUI that calls the
 * bes selling item function.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   calls the best selling item
***********************************************************/
void MainWindow::on_bestSelling_clicked() //find best selling item
{
    ui->textBrowser->clear();
    if(warehouse1.getVectorSize() == 0){
        ui->textBrowser->insertPlainText("NO DAYS TO CHECK!\n");
    }
    else{
        bestSellingReport();
    }
}

/***********************************************************
 *
 * Method bestSellingReport: Class MainWindow
 *_________________________________________________________
 * This method display the best selling item in the item
 * container.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   prints the best selling item
***********************************************************/
void MainWindow::bestSellingReport(){
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
    for (unsigned long i = 0; i< (warehouse1.itemCount.size() - 1); i++) {
      if(warehouse1.itemCount[i]>max)
        max = warehouse1.itemCount[i];
    }
    for (unsigned long i = 0; i<warehouse1.itemCount.size(); i++) {
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
    ui->textBrowser->insertPlainText("************************\n");

}

/***********************************************************
 *
 * Method worstSellingReport: Class MainWindow
 *_________________________________________________________
 * This method should display the worst selling item from
 * the combine days txt files.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   show the worst selling item
***********************************************************/
void MainWindow::worstSellingReport(){
    int index;
    int min = 1000000;
    for (unsigned long i = 0; i< warehouse1.itemCount.size(); i++) {
      if(warehouse1.itemCount[i]<min)
        min = warehouse1.itemCount[i];
    }
    for (unsigned long i = 0; i< warehouse1.itemCount.size(); i++) {
      if(warehouse1.itemCount[i]==min)
        index =i;
    }

    ui->textBrowser->insertPlainText("************************\n");
    ui->textBrowser->insertPlainText("****Worst performing item****!\n");
    ui->textBrowser->insertPlainText("Items:    " + QString::fromStdString(warehouse1.itemName[index]) + "\n");
    ui->textBrowser->insertPlainText("Quantity: " + QString::number(warehouse1.itemCount[index]) + "\n");
    ui->textBrowser->insertPlainText("Quantity: " + QString::number(warehouse1.itemCost[index]) + "\n");
    ui->textBrowser->insertPlainText("************************\n");
}

/***********************************************************
 *
 * Method setItemContainter: Class MainWindow
 *_________________________________________________________
 * This method copys item from one container to another
 * continaer built inside the mainwindow.h
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   copys a item container
***********************************************************/
void MainWindow::setItemContainter(){
    for(unsigned long i =0; i < warehouse1.getVectorSize();i++){
        items.pushin(warehouse1.vectorIndex(i));
    }

}

/***********************************************************
 *
 * Method on_testBut_clicked: Class MainWindow
 *_________________________________________________________
 * This method should display all the items that are in
 * the item container.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   display the entire item list
***********************************************************/
void MainWindow::on_testBut_clicked() // display entire item list
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse)
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
    else{
        warehouse1.sortMemberbyID();
        warehouse1.setWTotal();
        ui->textBrowser->insertPlainText("Rebate: \n");
        for(int i = 0;i< (warehouse1.getCurrent()-1);i++) {
          if(warehouse1[i].getMembershiptype()=="Preferred")
          {
           ui->textBrowser->insertPlainText("ID: " + QString::number(warehouse1[i].getID()) + "\n");
           ui->textBrowser->insertPlainText(QString::fromStdString(warehouse1[i].getName()) + " has -- ");
           ui->textBrowser->insertPlainText(QString::number(warehouse1[i].getTotal() * 0.05)+ "\n");
          }
        }
    }
}

/***********************************************************
 *
 * Method findItem: Class MainWindow
 *_________________________________________________________
 * A user should be able to enter an item name and get the
 * quantity of that item sold as well as the total sales price.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   - s: string for item name
 *
 * POST-CONDITIONS
 *   prints the daily report
***********************************************************/
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
      ui->textBrowser->insertPlainText("Check Inventory\n");
      ui->textBrowser->insertPlainText("************************\n");
      ui->textBrowser->insertPlainText("No such item exists.\nOr yet sold.");
  }
}

/***********************************************************
 *
 * Method on_checkInventory_clicked: Class MainWindow
 *_________________________________________________________
 * A user should be able to enter an item name and get the
 * quantity of that item sold as well as the total sales price.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   calls the findItem function
***********************************************************/
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

/***********************************************************
 *
 * Method on_salesDaily_clicked: Class MainWindow
 *_________________________________________________________
 * A sales report for any given day. It should include a
 * list of items and quantities sold on that day as well as
 * names of the members who shopped that day.  Report the
 * total revenue for the given day.  It should also include
 * the number of preferred members and basic members who
 * shopped during the given day
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   call the print daily report
***********************************************************/
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

/***********************************************************
 *
 * Method on_salesYearly_clicked: Class MainWindow
 *_________________________________________________________
 * A yearly sales report.  It should include a list of the
 * items and quantities sold in the given year.  Report the
 * total revenue for the given year.  The report should
 * highlight the best performing items as well as the worst
 * performing items for the year.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   call the year sale function
***********************************************************/
void MainWindow::on_salesYearly_clicked() //Display yearly sale  report
{
    QString totalRevenue;
    ui->textBrowser->clear();
    if(dayCount == 0){
        ui->textBrowser->insertPlainText("NO DAY TO REPORT.");
        return;
    }
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    else{
        ui->textBrowser->insertPlainText("***********************************\n");
        printSaleReportYearly();
    }
}

/***********************************************************
 *
 * Method saveRemoveNames: Class MainWindow
 *_________________________________________________________
 * This method re-write into the delete names txt file.
 * This file is used to store names that have been removed
 * in the warehouse txt.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   re-write the delete names txt
***********************************************************/
void MainWindow::saveRemoveNames(){
    if(deleteName.getCurrent() == 0){
        return;
    }
    QFile fileName("/Users/davidmei/Project1_super_warehouse_3_3_22/deleteNames.txt");
    if(!fileName.open(QIODevice::WriteOnly)){
        qCritical() << fileName.errorString();
        return;
    }
    QTextStream stream(&fileName);
    for(int i = 0; i < (deleteName.getCurrent()); i++){
            stream << QString::fromStdString(deleteName[i]) << Qt::endl;
    }
}

/***********************************************************
 *
 * Method saveFile: Class MainWindow
 *_________________________________________________________
 * This method function should add a new member into the
 * warehouse txt file. It must first re-write the file.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   add a new member into the file
***********************************************************/
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
    if(addName.getCurrent() > 0){
        for(int y = 0; y < (addName.getCurrent()); y++){
            stream << QString::fromStdString(addName[y].getName()) << Qt::endl;
            stream << QString::number(addName[y].getID()) << Qt::endl;
            stream << QString::fromStdString(addName[y].getMembershiptype()) << Qt::endl;
            stream << QString::fromStdString(addName[y].getEXP()) << Qt::endl;
        }
    }
    fileName.close();
}

/***********************************************************
 *
 * Method saveItem: Class MainWindow
 *_________________________________________________________
 * This method is used to write into a day files. When a new
 * item is added it must rewrite the previous items before
 * adding the new item into the txt files. If the new item date
 * match the day file. Write into the file.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   re-write and add a new item into the day txt
***********************************************************/
void MainWindow::saveItem(){
    if(dayCount == 0){
        return;
    }

    string date = "03/05/2013";
    string fileName;

    for(int y = 1; y <= dayCount; y++){

        switch (y) {
            case 1: fileName = "/Users/davidmei/Project1_super_warehouse_3_3_22/day1.txt";
                    date = "03/05/2013";
                    break;
            case 2: fileName = "/Users/davidmei/Project1_super_warehouse_3_3_22/day2.txt";
                    date = "03/06/2013";
                    break;
            case 3: fileName = "/Users/davidmei/Project1_super_warehouse_3_3_22/day3.txt";
                    date = "03/07/2013";
                    break;
            case 4: fileName = "/Users/davidmei/Project1_super_warehouse_3_3_22/day4.txt";
                    date = "03/13/2013";
                    break;
            case 5: fileName = "/Users/davidmei/Project1_super_warehouse_3_3_22/day5.txt";
                    date = "03/09/2013";
                    break;

        }

        QFile fileName2(QString::fromStdString(fileName));

        if(!fileName2.open(QIODevice::WriteOnly)){
            qCritical() << fileName2.errorString();
            return;
        }
        QTextStream stream2(&fileName2);
        //cout << warehouse1.getVectorSize() << endl;
        for (size_t i = 0; i < warehouse1.getVectorSize(); i++)
        {
            if (warehouse1.vectorIndex(i).getDate() == date) {

                            stream2 << QString::fromStdString(warehouse1.vectorIndex(i).getDate()) << Qt::endl;
                            stream2 << QString::number(warehouse1.vectorIndex(i).getID()) << Qt::endl;
                            stream2 << QString::fromStdString(warehouse1.vectorIndex(i).getItem()) << Qt::endl;
                            stream2 << QString::number(warehouse1.vectorIndex(i).getCost()) << "	" << QString::number(warehouse1.vectorIndex(i).getQuantity()) << Qt::endl;

                }
            }
        if(newItems.getCurrent() > 0 ){
            for(int y = 0; y < (newItems.getCurrent()); y++){
                if(newItems[y].getDate() == date){
                    stream2 << QString::fromStdString(newItems[y].getDate()) << Qt::endl;
                    stream2 << QString::number(newItems[y].getID()) << Qt::endl;
                    stream2 << QString::fromStdString(newItems[y].getItem()) << Qt::endl;
                    stream2 << QString::number(newItems[y].getCost()) << "	" << QString::number(newItems[y].getQuantity()) << Qt::endl;
                }
            }
        }
    }
}

/***********************************************************
 *
 * Method checkName: Class MainWindow
 *_________________________________________________________
 * This method see if name is in the deleteName container
 *_________________________________________________________
 * PRE-CONDITIONS
 *   - temp: is the name of a member
 *
 * POST-CONDITIONS
 *   see if name is in the deleteName container
***********************************************************/
bool MainWindow::checkName(string temp){ //see if name is in the deleteName container
    for(int i = 0; i < (deleteName.getCurrent()); i++){
        if(temp == deleteName[i]){
            return true;
        }
    }
    return false;
}

/***********************************************************
 *
 * Method on_removeMem_clicked: Class MainWindow
 *_________________________________________________________
 * This method deletes a member after the users calls the
 * delete member button. First it will check if a member exist
 * in the warehouse before add the member into a container to
 * be later deleted.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   check and delete a member after the GUI ends
***********************************************************/
void MainWindow::on_removeMem_clicked() //delete a name
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    QString input = ui->lineEdit->text();
    string name;
    name = input.toStdString();
    bool doesExit;
    doesExit = false;
    int index;
    index = 0;

    for(int i = 0; i < (warehouse1.getCurrent() - 1); i++){
        if(name == warehouse1[i].getName()){
            doesExit = true;
            index++;
            break;
        }
    }
    if(doesExit){
        deleteName.pushin(name);
        ui->textBrowser->clear();
        ui->textBrowser->insertPlainText("Member remove.... \n" + input + "\n");
        ui->textBrowser->insertPlainText(QString::number(warehouse1[index].getID()) + "\n");
        ui->textBrowser->insertPlainText(QString::fromStdString(warehouse1[index].getMembershiptype()) + "\n");
        ui->textBrowser->insertPlainText(QString::fromStdString(warehouse1[index].getEXP()) + "\n");
    }
    else
        ui->textBrowser->insertPlainText("Does not exist\nPlease re-enter.");



}

/***********************************************************
 *
 * Method on_expireMonth_clicked: Class MainWindow
 *_________________________________________________________
 * This method is the button that users input a month number
 * and search if member will expired and call the findExpire
 * function.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   find expired membership
***********************************************************/
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

/***********************************************************
 *
 * Method findExpireExp: Class MainWindow
 *_________________________________________________________
 * This method a user should be able to enter a month and
 * get a list of all members whose memberships expire that
 * month as well as their dues amount
 *_________________________________________________________
 * PRE-CONDITIONS
 *   - month: a month for a member type
 *
 * POST-CONDITIONS
 *   find expired members
***********************************************************/
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
        if(!flag)
          ui->textBrowser->insertPlainText("No EXP on the month.\n");
    }
    if(!flag){
      ui->textBrowser->clear();
      ui->textBrowser->insertPlainText("No EXP on the month. " + QString::fromStdString(month) +"\n");
      ui->textBrowser->insertPlainText("\n***********************************\n");
      ui->textBrowser->insertPlainText("Enter a month to see member who exp is the month(2 digit): ");
    }
}

/***********************************************************
 *
 * Method on_addNewM_clicked: Class MainWindow
 *_________________________________________________________
 * This method creates a new member varblie and push that
 * member into a container varible. Should display the
 * new member and store into a container
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   add a new member into a container varible for later
***********************************************************/
void MainWindow::on_addNewM_clicked() //Add a new name into the warehouse
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    QString input = ui->lineEdit->text();
    string name;
    name = input.toStdString();
    member current;
    current.setName(name);
    current.setId(idNum);
    current.setType(membershipType);
    current.setDate(expDate);
    addName.pushin(current);
    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText("New member.... \n" + input + "\n");
    ui->textBrowser->insertPlainText(QString::number(idNum) + "\n");
    ui->textBrowser->insertPlainText(QString::fromStdString(membershipType) + "\n");
    ui->textBrowser->insertPlainText(QString::fromStdString(expDate) + "\n");
}

/***********************************************************
 *
 * Method on_setNewEXP_clicked: Class MainWindow
 *_________________________________________________________
 * This method sets the date for the membership to expire
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   sets a new date
***********************************************************/
void MainWindow::on_setNewEXP_clicked() //set expire date
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    QString input = ui->lineEdit->text();
    string date;
    date = input.toStdString();
    ui->textBrowser->insertPlainText("User inputed: " + input + "\n");
    expDate = date;
}

/***********************************************************
 *
 * Method on_setNewId_clicked: Class MainWindow
 *_________________________________________________________
 * This method sets the id of the new member/
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   sets the id
***********************************************************/
void MainWindow::on_setNewId_clicked() //set Id
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    QString input = ui->lineEdit->text();
    int vaule;
    vaule = input.toInt();
    ui->textBrowser->insertPlainText("User inputed: " + input + "\n");
    idNum = vaule;
}

/***********************************************************
 *
 * Method on_setNewType_clicked: Class MainWindow
 *_________________________________________________________
 * This method set the membershipType while also checking
 * if the user input is a valid membership type
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   set membershipType
***********************************************************/
void MainWindow::on_setNewType_clicked() //set membershipType
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    QString input = ui->lineEdit->text();
    string type;
    type = input.toStdString();
    if(type == "Basic" || type == "Preferred"){
        ui->textBrowser->insertPlainText("User inputed: " + input + "\n");
        membershipType = type;
    }
    else{
        if(type[0] == 'b' || type[0] == 'f')
            ui->textBrowser->insertPlainText("INVALID lowercase.\n");
        ui->textBrowser->insertPlainText("INVALID.\n");
    }
}

/***********************************************************
 *
 * Method on_setQuan_clicked: Class MainWindow
 *_________________________________________________________
 * This method sets the stock varible whos value should be
 * the quanitity of a new item being added into the file.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *
***********************************************************/
void MainWindow::on_setQuan_clicked()
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    QString input = ui->lineEdit->text();
    int vaule;
    vaule = input.toInt();
    ui->textBrowser->insertPlainText("User inputed: " + input + "\n");
    stock = vaule;
}

/***********************************************************
 *
 * Method on_setName_clicked: Class MainWindow
 *_________________________________________________________
 * This method sets the item name that the user will add into
 * the file
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   sets the itemName varible
***********************************************************/
void MainWindow::on_setName_clicked()
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    QString input = ui->lineEdit->text();
    string type;
    type = input.toStdString();
    ui->textBrowser->insertPlainText("User inputed: " + input + "\n");
    itemName = type;
}

/***********************************************************
 *
 * Method on_setDate_clicked: Class MainWindow
 *_________________________________________________________
 * This method should get the input from the user and set
 * the dateExp varible for a date of an item
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   set dateExp
***********************************************************/
void MainWindow::on_setDate_clicked()
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    QString input = ui->lineEdit->text();
    string type;
    type = input.toStdString();
    ui->textBrowser->insertPlainText("User inputed: " + input + "\n");
    dateExp = type;
}

/***********************************************************
 *
 * Method on_setPrice_clicked: Class MainWindow
 *_________________________________________________________
 * This method set the varible priceTag.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   set priceTag
***********************************************************/
void MainWindow::on_setPrice_clicked()
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    QString input = ui->lineEdit->text();
    double vaule;
    vaule = input.toDouble();
    ui->textBrowser->insertPlainText("User inputed: " + input + "\n");
    priceTag = vaule;
}

/***********************************************************
 *
 * Method on_setId_clicked: Class MainWindow
 *_________________________________________________________
 * The method should set the itemId given the user input from
 * the GUI menu.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   set the itemId
***********************************************************/
void MainWindow::on_setId_clicked()
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    QString input = ui->lineEdit->text();
    int vaule;
    vaule = input.toInt();
    ui->textBrowser->insertPlainText("User inputed: " + input + "\n");
    itemId = vaule;
}

/***********************************************************
 *
 * Method on_addItem_clicked: Class MainWindow
 *_________________________________________________________
 * This method should add a new item but more specific store
 * that item into a container. To be later added into the
 * file given the date. This function should create a item
 * and push into a container.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   add an Item type into a container
***********************************************************/
void MainWindow::on_addItem_clicked() // add a new item
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    QString input = ui->lineEdit->text();
    string name;
    name = input.toStdString();
    Item current;
    current.setCost(priceTag);
    current.setDate(dateExp);
    current.setID(itemId);
    current.setQuantity(stock);
    current.setItem(itemName);
    newItems.pushin(current);
    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText("New member.... \n" + QString::fromStdString(itemName));
}

/***********************************************************
 *
 * Method on_worstSelling_clicked: Class MainWindow
 *_________________________________________________________
 * This method calls the worst selling item function but
 * first needs to check if day has been called.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   call the worst selling function
***********************************************************/
void MainWindow::on_worstSelling_clicked()
{
    ui->textBrowser->clear();
    if(warehouse1.getVectorSize() == 0){
        ui->textBrowser->insertPlainText("NO DAYS TO CHECK!\n");
    }
    else{
        worstSellingReport();
    }
}

/***********************************************************
 *
 * Method printSaleRep: Class MainWindow
 *_________________________________________________________
 * A report that prints out the quantity of each item sold
 * sorted by item name
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   display each item and sorted
***********************************************************/
void MainWindow::printSaleRep(){
    warehouse1.sortItem();

    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    ui->textBrowser->insertPlainText("Prints out the quantity of each item sold sorted by item name.\n");
    ui->textBrowser->insertPlainText("***********************************\n");
    for(unsigned long i=0; i < warehouse1.itemName.size(); i++) {
      ui->textBrowser->insertPlainText("Items:    " + QString::fromStdString(warehouse1.itemName[i]) + "\n");
      ui->textBrowser->insertPlainText("Quantities:    " + QString::number(warehouse1.itemCount[i]) + "\n");
      ui->textBrowser->insertPlainText("Price:    " + QString::number(warehouse1.itemCost[i]) + "\n\n");
    }

}

/***********************************************************
 *
 * Method printSaleReportYearly: Class MainWindow
 *_________________________________________________________
 * This method shows yearly sales report. It should include
 * a list of the items and quantities sold in the given year.
 * Report the total revenue for the given year.  The report
 * should highlight the best performing items as well as
 * the worst performing items for the year.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *  display yearly report
***********************************************************/
void MainWindow::printSaleReportYearly(){
    double n;
    double tax;
    n = 0;
    tax = 0;
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    for(unsigned long i=0; i < warehouse1.itemName.size(); i++) {
      ui->textBrowser->insertPlainText("Items:    " + QString::fromStdString(warehouse1.itemName[i]) + "\n");
      ui->textBrowser->insertPlainText("Quantities:    " + QString::number(warehouse1.itemCount[i]) + "\n");
      ui->textBrowser->insertPlainText("Price:    " + QString::number(warehouse1.itemCost[i]) + "\n\n");
      tax += warehouse1.itemCount[i]*warehouse1.itemCost[i]*0.0875;
      n += warehouse1.itemCount[i]*warehouse1.itemCost[i];
    }
    ui->textBrowser->insertPlainText("SubTotal:     " + QString::number(n) + "\n");
    ui->textBrowser->insertPlainText("Tax 8.75%:    " + QString::number(tax) + "\n");
    ui->textBrowser->insertPlainText("Total:        " + QString::number(tax + n) + "\n");
    bestSellingReport();
    worstSellingReport();
}

/***********************************************************
 *
 * Method on_memberReport_2_clicked: Class MainWindow
 *_________________________________________________________
 * This method report showing the amount per year paid by
 * each member for the membership dues sorted by member
 * type (basic/preferred and then by member name.)
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   display the amount per year paid
***********************************************************/
void MainWindow::on_memberReport_2_clicked()
{
    ui->textBrowser->clear();
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
      warehouse1.sortMember();
      for(int i=0; i < (warehouse1.getCurrent()-1); i++) {
          ui->textBrowser->insertPlainText("Type: " + QString::fromStdString(warehouse1[i].getMembershiptype()) + "\n");
          ui->textBrowser->insertPlainText("ID: " + QString::number(warehouse1[i].getID()) + "\n");
          ui->textBrowser->insertPlainText("Name: " + QString::fromStdString(warehouse1[i].getName()) + "\n");
          ui->textBrowser->insertPlainText("***********************************\n");
        if (warehouse1[i].getMembershiptype() == "Preferred")
          ui->textBrowser->insertPlainText("due amount: $75\n\n");
        else
          ui->textBrowser->insertPlainText("due amount: $60\n\n");
      }
}

/***********************************************************
 *
 * Method on_pushButton_5_clicked: Class MainWindow
 *_________________________________________________________
 * This method calls the printSaleRep but before check if the
 * user had added a day and press the warehouse button
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   calls the printSalerep
***********************************************************/
void MainWindow::on_pushButton_5_clicked()
{
    ui->textBrowser->clear();
    if(dayCount == 0){
        ui->textBrowser->insertPlainText("NO DAY TO REPORT.");
        return;
    }
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    printSaleRep();
}

/***********************************************************
 *
 * Method determineBasic: Class MainWindow
 *_________________________________________________________
 * This method determine if any preferred customer should
 * convert their membership to basic status.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   determine if members need to convert
***********************************************************/
void MainWindow::determineBasic(){
    warehouse1.setWTotal();
    for(int i = 0;i<(warehouse1.getCurrent()-1);i++)
      {
        if(warehouse1[i].getMembershiptype()== "Preferred")
        {
        if(warehouse1[i].getTotal()<300)
        {
            ui->textBrowser->insertPlainText("\n");
            ui->textBrowser->insertPlainText("Member: " + QString::fromStdString(warehouse1[i].getName()) + "\nID: " + QString::number(warehouse1[i].getID()));
            ui->textBrowser->insertPlainText("\nType " + QString::fromStdString(warehouse1[i].getMembershiptype()) + "\nMonth " + QString::fromStdString(warehouse1[i].getEXP()) + "\n");

            ui->textBrowser->insertPlainText("Spend total: " + QString::number(warehouse1[i].getTotal()) + "\n");
            ui->textBrowser->insertPlainText("The rebate is:\n" + QString::number(warehouse1[i].getTotal() * 0.05) + "\n");
            ui->textBrowser->insertPlainText("\nThus should convert membership to basic status.\n");

          }
      }
        }
}

/***********************************************************
 *
 * Method determinePref: Class MainWindow
 *_________________________________________________________
 * This method determine if any basic customer should
 * convert their membership to preferred status.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   determine if members need to convert
***********************************************************/
void MainWindow::determinePref(){
    warehouse1.setWTotal();
    for(int i = 0;i<(warehouse1.getCurrent()-1);i++)
      {
        if(warehouse1[i].getMembershiptype() == "Basic")
        {
            if(warehouse1[i].getTotal()>=300)
              {
                    ui->textBrowser->insertPlainText("\n");
                    ui->textBrowser->insertPlainText("Member: " + QString::fromStdString(warehouse1[i].getName()) + "\nID: " + QString::number(warehouse1[i].getID()));
                    ui->textBrowser->insertPlainText("\nType " + QString::fromStdString(warehouse1[i].getMembershiptype()) + "\nMonth " + QString::fromStdString(warehouse1[i].getEXP()) + "\n");

                    ui->textBrowser->insertPlainText("Spend total: " + QString::number(warehouse1[i].getTotal()) + "\n");
                    ui->textBrowser->insertPlainText("The rebate is:\n" + QString::number(warehouse1[i].getTotal() * 0.05) + "\n");
                    ui->textBrowser->insertPlainText("\nThus should convert membership to preferred status.\n");

              }
        }
    }
}

/***********************************************************
 *
 * Method printAll: Class MainWindow
 *_________________________________________________________
 * This method report that prints the total purchases by all
 * the members sorted by membership number.  It should also
 * include a grand total of the purchases.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   prints the total purchase by all
***********************************************************/
void MainWindow::printAll(){
    warehouse1.setWTotal();
    warehouse1.sortMemberbyID();
    double grand = 0;
    for(int i=0; i < (warehouse1.getCurrent()-1); i++) {
        ui->textBrowser->insertPlainText("Type:  " + QString::fromStdString(warehouse1[i].getMembershiptype()) + "\n");
        ui->textBrowser->insertPlainText("ID:    " + QString::number(warehouse1[i].getID()) + "\n");
        ui->textBrowser->insertPlainText("Name:  " + QString::fromStdString(warehouse1[i].getName()) + "\n");
        ui->textBrowser->insertPlainText("Subtotal: " + QString::number(warehouse1[i].getTotal()) + "\n");
        ui->textBrowser->insertPlainText("Total: " + QString::number(warehouse1[i].getTotal()*1.0875) + "\n");
        ui->textBrowser->insertPlainText("***********************************\n");
        grand += warehouse1[i].getTotal();
    }
        ui->textBrowser->insertPlainText("Warehouse revenue: " + QString::number(grand/1.0875) + "\n");
        ui->textBrowser->insertPlainText("Grand total: " + QString::number(grand/1.0875*1.0875) + "\n");
        ui->textBrowser->insertPlainText("***********************************\n");

}

/***********************************************************
 *
 * Method on_pushButton_4_clicked: Class MainWindow
 *_________________________________________________________
 * This method calls the determineBasic which check if a
 * member should convert membership to basic status.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   calls the determineBasic();
***********************************************************/
void MainWindow::on_pushButton_4_clicked()
{
    ui->textBrowser->clear();
    if(dayCount == 0){
        ui->textBrowser->insertPlainText("NO DAY TO REPORT.");
        return;
    }
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    determineBasic();
}

/***********************************************************
 *
 * Method on_pushButton_2_clicked: Class MainWindow
 *_________________________________________________________
 * This method calls the determinePref which check if a
 * member should convert membership to preferred status.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   calls the determinePref();
***********************************************************/
void MainWindow::on_pushButton_2_clicked()
{
    ui->textBrowser->clear();
    if(dayCount == 0){
        ui->textBrowser->insertPlainText("NO DAY TO REPORT.");
        return;
    }
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    determinePref();
}

/***********************************************************
 *
 * Method on_printAll_clicked: Class MainWindow
 *_________________________________________________________
 * This method report that prints the total purchases by all
 * the members sorted by membership number.  It should also
 * include a grand total of the purchases.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   prints the total purchase by all
***********************************************************/
void MainWindow::on_printAll_clicked()
{
    ui->textBrowser->clear();
    if(dayCount == 0){
        ui->textBrowser->insertPlainText("NO DAY TO REPORT.");
        return;
    }
    if(!calledTheWareHouse){
        ui->textBrowser->insertPlainText("ERROR.\nNeed to press Warehouse info.\n");
        return;
    }
    ui->textBrowser->insertPlainText("All mmember spedning\n");
    ui->textBrowser->insertPlainText("***********************************\n");
    printAll();
}

