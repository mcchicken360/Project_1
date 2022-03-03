/***********************************************************************************
 * Authors      : David Mei, Matthew Mirbasoo, You Lyu, Ruitau He
 * Project #1   : Super Warehouse
 * Class        : CS008
 * Due Date     : 03/03/2022
***********************************************************************************/
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
    /***************
    * MUTATORS *
    **************/
    void addRemoveNames();
    void setItemContainter();
    void saveRemoveNames();
    void saveFile();
    void saveItem();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_removeMem_clicked();
    void on_setNewEXP_clicked();
    void on_setNewId_clicked();
    void on_setNewType_clicked();


    void on_setQuan_clicked();
    void on_setName_clicked();
    void on_setDate_clicked();
    void on_setPrice_clicked();
    void on_setId_clicked();
    void on_addNewM_clicked();
    void on_addItem_clicked();

    /****************
    * ACCESSORS *
    ****************/
    void display(Containers<member>&);
    void printDaily(Containers<member>&, string);
    void printMemberReport(Containers<member>&, int);
    void printSaleReportYearly();
    void worstSellingReport();
    void bestSellingReport();
    void findItem(string s);
    void printSaleRep();
    bool checkName(string);
    void findExpireExp(string);
    void determineBasic();
    void determinePref();
    void printAll();


    void on_singleDayPurchase_clicked();
    void on_exitBut_clicked();
    void on_bestSelling_clicked();
    void on_testBut_clicked();
    void on_checkInventory_clicked();
    void on_salesDaily_clicked();
    void on_salesYearly_clicked();
    void on_expireMonth_clicked();
    void on_worstSelling_clicked();
    void on_memberReport_2_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();
    void on_printAll_clicked();

private:
    Ui::MainWindow *ui;
    int dayCount = 0;
    int yearRevnue = 0;
    int doOnce = 0;
    int counter = 0;
    int beforeCount = 0;

    string expDate = "03/05/2013";
    string membershipType = "Basic";
    int idNum = 11111;

    string itemName = "Taco";
    string dateExp = "03/05/2013";
    int stock = 0;
    double priceTag = 0;
    int itemId = 11111;

    Containers<member> warehouse1;
    Containers<Item> items;
    Containers<string> deleteName;
    Containers<member> addName;
    Containers<Item> newItems;
    Containers<int> countItems;
    bool calledTheWareHouse = false;
};

/****************************************************************
 * MainWindow Class
 * You are to write a program that services members of Wholesale
 * Club.  You must use a container class with at least one
 * overloaded operator.  You should also describe the growth rate
 * of your program for various operations/functions. At least
 * one class must contain a pointer (a copy constructor needs to
 * be written and tested).   Highlight the above.  Write at least
 * 15 agile stories (including description, tasks, test scenarios,
 * and story points) before you start to develop software.
 ***************************************************************/

/***************
 * MUTATORS *
 **************/

/*******************************************************************
 * void addRemoveNames();
 *
 *   Mutator;  This method reads the delete name txt file and store
 *   the previous deleted names into a delete member container.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *  void setItemContainter();
 *
 *   Mutator;  This method copys item from one container to another
 * continaer built inside the mainwindow.h
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *  void saveRemoveNames();
 *
 *   Mutator;  This method re-write into the delete names txt file.
 * This file is used to store names that have been removed
 * in the warehouse txt.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *  void saveFile();
 *
 *   Mutator;  This method function should add a new member into the
 * warehouse txt file. It must first re-write the file.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void saveItem();
 *
 *   Mutator;  This method is used to write into a day files. When a
 * new item is added it must rewrite the previous items before
 * adding the new item into the txt files. If the new item date
 * match the day file. Write into the file.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void on_pushButton_clicked();
 *
 *   Mutator;  This method is the add day button that adds a new day
 * into the item container. Calling the add day function
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void on_pushButton_3_clicked();
 *
 *   Mutator;  This GUI button called warehouse info should set and create
 * a warehouse container and store member types. The function
 * should also called the display function.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void on_removeMem_clicked();
 *
 *   Mutator;  This method deletes a member after the users calls the
 * delete member button. First it will check if a member exist
 * in the warehouse before add the member into a container to
 * be later deleted.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void on_setNewEXP_clicked();
 *
 *   Mutator;  This method sets the date for the membership to expire
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void on_setNewId_clicked();
 *
 *   Mutator;  This method sets the id of the new member/
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void on_setNewType_clicked();
 *
 *   Mutator;  This method set the membershipType while also checking
 * if the user input is a valid membership type
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void on_setQuan_clicked();
 *
 *   Mutator;  This method sets the stock varible whos value should be
 * the quanitity of a new item being added into the file.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void on_setName_clicked();
 *
 *   Mutator;  This method sets the item name that the user will add
 * into the file
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void on_setDate_clicked();
 *
 *   Mutator;  This method should get the input from the user and set
 * the dateExp varible for a date of an item
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void on_setPrice_clicked();
 *
 *   Mutator;  This method set the varible priceTag.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void on_setId_clicked();
 *
 *   Mutator;  This method should set the itemId given the user input
 * from the GUI menu.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void on_addNewM_clicked();
 *
 *   Mutator;  This method creates a new member varblie and push that
 * member into a container varible. Should display the
 * new member and store into a container
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void on_addItem_clicked();
 *
 *   Mutator;  This method should add a new item but more specific store
 * that item into a container. To be later added into the
 * file given the date. This function should create a item
 * and push into a container.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/


/***************
 ** ACCESSORS **
 ***************/

/*******************************************************************
 *  void display(Containers<member>&);
 *
 *   Accessor; This method display the warehouse txt file. Showing the
 * memebers information
 *------------------------------------------------------------------
 *   Parameter: - ware: A container for member types
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void printDaily(Containers<member>&, string);
 *
 *   Accessor; This method
 *------------------------------------------------------------------
 *   Parameter: - ware: A container for member types
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void printMemberReport(Containers<member>&, int);
 *
 *   Accessor; This sales report for any given day. It should include
 * a list of items and quantities sold on that day as well as
 * names of the members who shopped that day.  Report the
 * total revenue for the given day.  It should also include
 * the number of preferred members and basic members who
 * shopped during the given day
 *------------------------------------------------------------------
 *   Parameter: - reportList: a container for member types
 *              - dateEnter : a date
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void printSaleReportYearly();
 *
 *   Accessor; This method shows yearly sales report. It should include
 * a list of the items and quantities sold in the given year.
 * Report the total revenue for the given year.  The report
 * should highlight the best performing items as well as
 * the worst performing items for the year.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void worstSellingReport();
 *
 *   Accessor; This method should display the worst selling item from
 * the combine days txt files.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void bestSellingReport();
 *
 *   Accessor; This method display the best selling item in the item
 * container.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void findItem(string s);
 *
 *   Accessor; A user should be able to enter an item name and get the
 * quantity of that item sold as well as the total sales price.
 *------------------------------------------------------------------
 *   Parameter: - s: string for item name
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *  void printSaleRep();
 *
 *   Accessor; A report that prints out the quantity of each item sold
 * sorted by item name
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *  bool checkName(string);
 *
 *   Accessor; This method see if name is in the deleteName container
 *------------------------------------------------------------------
 *   Parameter: - temp: is the name of a member
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void findExpireExp(string);
 *
 *   Accessor; This method a user should be able to enter a month and
 * get a list of all members whose memberships expire that
 * month as well as their dues amount
 *------------------------------------------------------------------
 *   Parameter: - month: a month for a member type
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void determineBasic();
 *
 *   Accessor; This method determine if any preferred customer should
 * convert their membership to basic status.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void determinePref();
 *
 *   Accessor; This method determine if any basic customer should
 * convert their membership to preferred status.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void printAll();
 *
 *   Accessor; This method report that prints the total purchases by
 * all the members sorted by membership number.  It should also
 * include a grand total of the purchases.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *  void on_singleDayPurchase_clicked();
 *
 *   Accessor; A user should be able to enter a membership number or
 * name and get a list of the total purchases per that member.
 * The GUI has a button to call the print member report
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void on_exitBut_clicked();
 *
 *   Accessor; A button that exit the GUI. Before the program ends
 * add all the new members and item into the txt files.
 * This will save all the changes.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void on_bestSelling_clicked();
 *
 *   Accessor; This method is the button in the GUI that calls the
 * bes selling item function.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void on_testBut_clicked();
 *
 *   Accessor; This method should display all the items that are in
 * the item container.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void on_checkInventory_clicked();
 *
 *   Accessor; A user should be able to enter an item name and get the
 * quantity of that item sold as well as the total sales price.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void on_salesDaily_clicked();
 *
 *   Accessor; A sales report for any given day. It should include a
 * list of items and quantities sold on that day as well as
 * names of the members who shopped that day.  Report the
 * total revenue for the given day.  It should also include
 * the number of preferred members and basic members who
 * shopped during the given day
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/


/*******************************************************************
 *   void on_salesYearly_clicked();
 *
 *   Accessor; A yearly sales report.  It should include a list of the
 * items and quantities sold in the given year.  Report the
 * total revenue for the given year.  The report should
 * highlight the best performing items as well as the worst
 * performing items for the year.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void on_expireMonth_clicked();
 *
 *   Accessor; This method is the button that users input a month number
 * and search if member will expired and call the findExpire
 * function.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *  void on_worstSelling_clicked();
 *
 *   Accessor; This method calls the worst selling item function but
 * first needs to check if day has been called.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void on_memberReport_2_clicked();
 *
 *   Accessor; This method report showing the amount per year paid by
 * each member for the membership dues sorted by member
 * type (basic/preferred and then by member name.)
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void on_pushButton_5_clicked();
 *
 *   Accessor; This method calls the printSaleRep but before check if
 * the user had added a day and press the warehouse button.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void on_pushButton_4_clicked();
 *
 *   Accessor; This method calls the determineBasic which check if a
 * member should convert membership to basic status.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void on_pushButton_2_clicked();
 *
 *   Accessor; This method calls the determinePref which check if a
 * member should convert membership to preferred status.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 *   void on_printAll_clicked();
 *
 *   Accessor; This method report that prints the total purchases by
 * all the members sorted by membership number.  It should also
 * include a grand total of the purchases.
 *------------------------------------------------------------------
 *   Parameter: none
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/


#endif // MAINWINDOW_H
