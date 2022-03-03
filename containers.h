/***********************************************************************************
 * Authors      : David Mei, Matthew Mirbasoo, You Lyu, Ruitau He
 * Project #1   : Super Warehouse
 * Class        : CS008
 * Due Date     : 03/03/2022
***********************************************************************************/
#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <iostream>
#include <string>
#include "members.h"
#include <fstream>

#include <vector>
#include "item.h"

using namespace std;
template<class E>
class Containers : public member
{
public:
    /*****************
    ** CONSTRUCTOR **
    ******************/
    Containers();
    ~Containers();

    /**************
    ** ACCESSORS **
    ***************/
    string getmember(int id);
    void getmember(string name);
    void display();
    void showAmountDue();
    void findItem(string s);
    void sortMemberbyID();
    void swapMember(member&, member&);
    void sortMember();
    void sortItem();
    void swapItem(string&, string&, int&, int&, double&, double&);
    void printRebate();
    void DetermineP();
    void DetermineB();
    void getTotal();

    E operator[](int index);
    Item vectorIndex(int index);
    unsigned long getVectorSize();
    int getCurrent();
    void printYearReport();
    void printSaleReport();
    void bestSelling();
    void worstSold();

  /***************
  * MUTATORS *
  **************/
   void operator=(Containers& obj);
   void pushin(E m);
   void setWareHouse();
   void addDay(string Date);

  //4/1
   void setWTotal();
   // friend class member;
   vector<string> itemName;
   vector<int> itemCount;
   vector<double> itemCost;

private:
    E* array = new E[20];
    vector<Item> list;
    int current = 0;

};

/**********************************************************
*
* Method Containers(): Class Containers
*_________________________________________________________
* This method is a default constructor
*_________________________________________________________
* PRE-CONDITIONS
*     No parameter
*
* POST-CONDITIONS
*     create a default object
***********************************************************/
template <class E>
Containers<E>::Containers(){}

/**********************************************************
*
* Method ~Containers(): Class Containers
*_________________________________________________________
* This method is a destructor
*_________________________________________________________
* PRE-CONDITIONS
*     No parameter
*
* POST-CONDITIONS
*     free the allocated memories
***********************************************************/
template <class E>
Containers<E>::~Containers()
{
  delete []array;
}

/**********************************************************
*
* Method operator=: Class Containers
*_________________________________________________________
* This method will overload operator=
*_________________________________________________________
* PRE-CONDITIONS
*     No parameter
*
* POST-CONDITIONS
*     overload operator=
***********************************************************/
template <class E>
void Containers<E>::operator=(Containers& obj)
{
for(int i = 0;i<obj.current-1;i++){
  this->array[i] = obj.array[i];
}

for(int i = 0;i<obj.list.size();i++){
  this->list.push_back(obj.list[i]);
}

for(int i = 0;i<obj.itemName.size();i++){
  this->itemName.push_back(obj.itemName[i]);
}

  for(int i = 0;i<obj.itemCost.size();i++)
  this->itemCost.push_back(obj.itemCost[i]);

  for(int i = 0;i<obj.itemCount.size();i++)
  this->itemCount.push_back(obj.itemCount[i]);

  this->current = obj.current;
}

/**********************************************************
*
* Method pushin: Class Containers
*_________________________________________________________
* This method will add a element in the array
*_________________________________________________________
* PRE-CONDITIONS
*     No parameter
*
* POST-CONDITIONS
*     add a element in the array
***********************************************************/
template<class E>
void Containers<E>::pushin(E m)
{
  array[current]=m;
  current++;
}

/**********************************************************
*
* Method getmember: Class Containers
*_________________________________________________________
* This method will find the array whether exit a member
* with the id
*_________________________________________________________
* PRE-CONDITIONS
*     int id
*
* POST-CONDITIONS
*     If found, output member info
***********************************************************/
template<class E>
string Containers<E>::getmember(int id)
{
  for(int i =0; i <current;i++)
  {
    if(array[i].getID() == id)
    {
      return array[i].getName();
    }
  }
}

/**********************************************************
*
* Method getmember: Class Containers
*_________________________________________________________
* This method will find the array whether exit a member
* with the name inputed
*_________________________________________________________
* PRE-CONDITIONS
*     string name
*
* POST-CONDITIONS
*     If found, output member info
***********************************************************/
template<class E>
void Containers<E>::getmember(string name)
{
  for(int i =0; i <current;i++)
  {
    if(array[i].getName() == name)
    {
      array[i].getinfo();
      return;
    }
  }
  cout<<"Not Found"<<endl;
}

/**********************************************************
*
* Method setWareHouse: Class Containers
*_________________________________________________________
* This method will read info from .txt file and write them
* into member array
*_________________________________________________________
* PRE-CONDITIONS
*     no parameter
*
* POST-CONDITIONS
*     record all the info in member array
***********************************************************/
template<class E>
void Containers<E>::setWareHouse(){
    ifstream myFile("/Users/davidmei/Project1_super_warehouse_3_3_22/warehouseShoppers.txt");
    string name;
    string date;
    string membershiptype;
    int ID;
    int i;
    i= 0;
    if(myFile.fail()){
        cout << "FAILED";
        return;
    }
    while (!myFile.eof()) {
        getline(myFile, name, '\n');
        myFile >> ID;
        myFile.get(); //get the '\n'
        getline(myFile, membershiptype, '\n');
        getline(myFile, date, '\n');

            member customer;
            customer.setName(name);
            customer.setId(ID);
            customer.setType(membershiptype);
            customer.setDate(date);

            array[i] = customer;
            i++;
            current++;

    }
}

/**********************************************************
*
* Method display: Class Containers
*_________________________________________________________
* This method will display the entire warehouse txt file.
*_________________________________________________________
* PRE-CONDITIONS
*     none
*
* POST-CONDITIONS
*    display the customer of the warehouse class
***********************************************************/
template<class E>
void Containers<E>::display(){
    for(int i = 0; i < (current - 1); i++){
        cout << "Customer " << i + 1 << ": ";
        array[i].getinfo();
    }
}

/**********************************************************
*
* Method operator[]: Class Containers
*_________________________________________________________
* A fuction that return the value inside the container at
* a given index.
*_________________________________________________________
* PRE-CONDITIONS
*     - index: the position in the array
*
* POST-CONDITIONS
*     return array[index];
***********************************************************/
template<class E>
E Containers<E>::operator[](int index){
    return array[index];
}

/**********************************************************
*
* Method vectorIndex: Class Containers
*_________________________________________________________
* A fuction that return the value inside the container at
* a given index.
*_________________________________________________________
* PRE-CONDITIONS
*     - index: the position in the array
*
* POST-CONDITIONS
*     return list[index];
***********************************************************/
template<class E>
Item Containers<E>::vectorIndex(int index){
    return list[index];
}

/**********************************************************
*
* Method vectorIndex: Class Containers
*_________________________________________________________
* This method return the size of the vector in the contianer
*_________________________________________________________
* PRE-CONDITIONS
*     none
*
* POST-CONDITIONS
*     return the size
***********************************************************/
template<class E>
unsigned long Containers<E>::getVectorSize(){
    return list.size();
}

/**********************************************************
*
* Method getCurrent: Class Containers
*_________________________________________________________
* This method return the current size of the container
*_________________________________________________________
* PRE-CONDITIONS
*     none
*
* POST-CONDITIONS
*     return the current
***********************************************************/
template<class E>
int Containers<E>::getCurrent(){
    return current;
}


/**********************************************************
*
* Method addDay: Class Containers
*_________________________________________________________
* This method will read info from .txt file and write day sale
* info in list and item name,count,cost
*_________________________________________________________
* PRE-CONDITIONS
*     string Date
*
* POST-CONDITIONS
*     put all the info in list, and item name,count,cost
***********************************************************/
template<class E>
void Containers<E>::Containers::addDay(string Date){
    ifstream myFile(Date);
    string name;
    string date;
    int ID,quantity;
    double cost;
    bool flag;
    if(myFile.fail())
        return;
    getline(myFile, date, '\n');
    myFile >> ID;
    myFile.get(); //get the '\n'
    getline(myFile, name, '\n');
    myFile >> cost;
    myFile >> quantity;

    while (!myFile.eof()) {
        Item item;
        item.setItem(name);
        item.setID(ID);
        item.setDate(date);
        item.setQuantity(quantity);
        item.setCost(cost);
        myFile.ignore(1000, '\n');

        list.push_back(item);


        flag = true;
        for (unsigned long i=0; i< itemName.size(); i++) {
          if (itemName[i] == name ) {
              flag = false;
              itemCount[i] += quantity;
              itemCost[i] = cost;
          }
        }
        if (flag) {
          itemName.push_back(name);
          itemCount.push_back(quantity);
          itemCost.push_back(cost);
        }

        getline(myFile, date, '\n');
        myFile >> ID;
        myFile.get(); //get the '\n'
        getline(myFile, name, '\n');
        myFile >> cost;
        myFile >> quantity;


    }
}

/**********************************************************
*
* Method printRebate: Class Containers
*_________________________________________________________
* This method will find item by enter its name, then
* output the info
*_________________________________________________________
* PRE-CONDITIONS
*     string s
*
* POST-CONDITIONS
* find item by enter its name, then output the info
***********************************************************/
/*A user should be able to enter an item name and get the quantity of that item sold as well as the total sales price.*/
template<class E>
void Containers<E>::findItem(string s) {
  double price;
  int quantities = 0;
  bool flag = false;
    for(int i =0; i <list.size();i++)
    {
      if(list[i].getItem() == s) {
        price = list[i].getCost();
        quantities+= list[i].getQuantity();
        flag = true;
      }
    }
  if(flag) {
    cout << s << endl;
    cout << "price: " << price << ", ";
    cout << "Quantities: " << quantities <<endl;
  }
  else
    cout << s << "NOT FOUND!\n";
}

/**********************************************************
*
* Method bestSelling: Class Containers
*_________________________________________________________
* This method will print out info of the bestselling
*_________________________________________________________
* PRE-CONDITIONS
*     no parameter
*
* POST-CONDITIONS
*   print out info of the bestselling
***********************************************************/
template<class E>
void Containers<E>::bestSelling() {
  int index;
  int max = 0;
  for (int i = 0; i<itemCount.size(); i++) {
    if(itemCount[i]>max)
      max = itemCount[i];
  }
  for (int i = 0; i<itemCount.size(); i++) {
    if(itemCount[i]==max)
      index =i;
  }
  cout << "Bestselling item: " << itemName[index] << endl;
  cout << "Quantities: " << itemCount[index];
  cout << ",   Price: " << itemCost[index] << endl << endl;
}

/**********************************************************
*
* Method worstSold: Class Containers
*_________________________________________________________
* This method will print out info of the item sold worst
*_________________________________________________________
* PRE-CONDITIONS
*     no parameter
*
* POST-CONDITIONS
*   print out info of the item sold worst
***********************************************************/
template<class E>
void Containers<E>::worstSold(){
    int index;
    int min = 1000000;
    for (int i = 0; i<itemCount.size(); i++) {
      if(itemCount[i]<min)
        min = itemCount[i];
    }
    for (int i = 0; i<itemCount.size(); i++) {
      if(itemCount[i]==min)
        index =i;
    }
    cout << "Worst performing item: " << itemName[index] << endl;
    cout << "Quantities: " << itemCount[index];
    cout << ",   Price: " << itemCost[index] << endl << endl;
}

/**********************************************************
*
* Method setWTotal: Class Containers
*_________________________________________________________
* This method will get the total price for items inside
* the container. Then set the total into the array.
*_________________________________________________________
* PRE-CONDITIONS
*     none
*
* POST-CONDITIONS
*     find the total price of all the item than set the total
***********************************************************/
template<class E>
void Containers<E>::setWTotal()
{
  for (int i =0; i< current-1; i++) {
    double total = 0;
    for (int j = 0; j< list.size(); j++) {
      if (array[i].getID() == list[j].getID())
        total += list[j].getQuantity() * list[j].getCost()* 1.0875;
    }
    array[i].setTotal(total);
  }
}

/**********************************************************
*
* Method getTotal: Class Containers
*_________________________________________________________
*  This method report that prints the total purchases by all
*  the members sorted by membership number. It should also
*  include a grand total of the purchases.
*_________________________________________________________
* PRE-CONDITIONS
*     none
*
* POST-CONDITIONS
*     find the total price of all the item than set the total
***********************************************************/
template<class E>
void Containers<E>::getTotal()
{
    this->setWTotal();
      this->sortMemberbyID();
      double grand = 0;
      for (int i =0; i< current-1; i++) {
        cout << "Type: " << array[i].getMembershiptype();
        cout << "  ID: " << array[i].getID();
        cout << "     Name: " << array[i].getName();

        cout <<"      Total: "<< array[i].getTotal() <<endl;
        grand += array[i].getTotal();
      }
      cout << "Grand total: " << grand/1.0875;
}

/**********************************************************
*
* Method sortMemberbyID: Class Containers
*_________________________________________________________
* This method will swap the members of the smallet with
* the bigest.
*_________________________________________________________
* PRE-CONDITIONS
*     none
*
* POST-CONDITIONS
*     swap or switch members
***********************************************************/
template<class E>
void Containers<E>::sortMemberbyID() {
    int minIndex;
    for (size_t i = 0; i < current-1 ; i++) {
      {
          minIndex = i;
          for (int j = i + 1; j < current-1; j++)
          {
              if (array[j].getID() < array[minIndex].getID())
                  minIndex = j;
          }
          swapMember(array[i], array[minIndex]);
      }
    }
}

/**********************************************************
*
* Method swapMember: Class Containers
*_________________________________________________________
* A fuction that swap the members.
*_________________________________________________________
* PRE-CONDITIONS
*     - m1: members
*     - m2: members
*
* POST-CONDITIONS
*     switch members
***********************************************************/
template<class E>
void Containers<E>::swapMember(member& m1, member& m2){
    member temp = m1;
     m1 = m2;
     m2 = temp;
}

/**********************************************************
*
* Method printYearReport: Class Containers
*_________________________________________________________
* This method shows yearly sales report. It should include
* a list of the items and quantities sold in the given year.
* Report the total revenue for the given year.  The report
* should highlight the best performing items as well as
* the worst performing items for the year.
*_________________________________________________________
* PRE-CONDITIONS
*     none
*
* POST-CONDITIONS
*     display yearly report
***********************************************************/
template<class E>
void Containers<E>::printYearReport() {
  double n;
  for(int i=0; i < itemName.size(); i++) {
    cout << "Item: " << itemName[i] << endl;
    cout << "Quantities: " << itemCount[i];
    cout << ",   Price: " << itemCost[i] << endl << endl;
    n += itemCount[i]*itemCost[i]*1.875;
  }
  cout << "Total revenue: " << n << endl;
  this->bestSelling();
  this->worstSold();
}

/**********************************************************
*
* Method showAmountDue: Class Containers
*_________________________________________________________
* This method a user should be able to enter a month and
* get a list of all members whose memberships expire that
* month as well as their dues amount
*_________________________________________________________
* PRE-CONDITIONS
*     none
*
* POST-CONDITIONS
*     display the members membership amount
***********************************************************/
template<class E>
void Containers<E>::showAmountDue() {
  this->sortMember();
  for(int i=0; i < current-1; i++) {
    cout << "Type: " << array[i].getMembershiptype();
    cout << "  ID: " << array[i].getID();
    cout << "     Name: " << array[i].getName();

    if (array[i].getMembershiptype() == "Preferred")
      cout <<"  due amount: $75\n"  <<endl;
    else
      cout << "  due amount: $60\n"  <<endl;
  }
}


/**********************************************************
*
* Method sortMemberbyID: Class Containers
*_________________________________________________________
* This method will sort member by ID#
*_________________________________________________________
* PRE-CONDITIONS
*     no parameter
*
* POST-CONDITIONS
*   sort member by ID#
***********************************************************/
template<class E>
void Containers<E>::sortMember() {
  vector<member> v1;
  vector<member> v2;

  for (size_t i = 0; i < this->current-1; i++) {
    if (array[i].getMembershiptype() == "Preferred")
      v1.push_back(array[i]);
    else
      v2.push_back(array[i]);
  }

  for (size_t i = 0; i < v1.size()-1; i++) {
    for (size_t j = 0; j < v1.size()-1-i; j++) {
      if (v1[j].getName().compare(v1[j+1].getName())>0)
        swapMember(v1[j], v1[j+1]);
    }
  }
//  for (size_t i = 0; i < v1.size(); i++) {
//    cout << "\nType: " << v1[i].getMembershiptype();
//    cout << " \n ID: " << v1[i].getID();
//    cout << " \n    Name: " << v1[i].getName();
//  }


  for (size_t i = 0; i < v2.size()-1; i++) {
    for (size_t j = 0; j < v2.size()-1-i; j++) {
      if (v2[j].getName().compare(v2[j+1].getName())>0)
        swapMember(v2[j], v2[j+1]);
    }
  }

  for (size_t i = 0; i < current-1; i++) {
    if (i<v1.size())
    {array[i] = v1[i];
      /*cout << i << array[i].getName() << endl;*/}
    else
      array[i] = v2[i-v1.size()];
  }
}

/**********************************************************
*
* Method printRebate: Class Containers
*_________________________________________________________
* A report that prints out the rebate of all the preferred
* members sorted by membership number.
*_________________________________________________________
* PRE-CONDITIONS
*     no parameter
*
* POST-CONDITIONS
*   display rebate report
***********************************************************/
template <class E>
void Containers<E>::printRebate()
{
  this->sortMemberbyID();
  cout << "Rebate: \n";
  for(int i = 0;i<current-1;i++) {
    if(array[i].getMembershiptype()=="Preferred")
    {
     cout << "ID: "<< left << setw(7) <<array[i].getID();
     cout <<array[i].getName()<<" has ";
     cout<< array[i].getTotal() * 0.05<<endl;
    }
  }
}

/**********************************************************
*
* Method printSaleReport: Class Containers
*_________________________________________________________
* A report that prints out the quantity of each item sold
 * sorted by item name
*_________________________________________________________
* PRE-CONDITIONS
*     no parameter
*
* POST-CONDITIONS
*   display each item and sorted
***********************************************************/
template <class E>
void Containers<E>::printSaleReport() {
  cout << "prints out the quantity of each item sold sorted by item name ";
  for (int i = 0; i<itemName.size(); i++) {
    cout << "Item: " << itemName[i] << endl;
    cout << "Quantities: " << itemCount[i];
    cout << ",   Price: " << itemCost[i] << endl << endl;
  }
}

/**********************************************************
*
* Method sortItem: Class Containers
*_________________________________________________________
* The function sorts names use to prints out the quantity
* of each item sold sorted by item name.
*_________________________________________________________
* PRE-CONDITIONS
*     no parameter
*
* POST-CONDITIONS
*   sort item names
***********************************************************/
template <class E>
void Containers<E>::sortItem() {
  for (size_t i = 0; i < itemName.size()-1; i++) {
    for (size_t j = 0; j < itemName.size()-1-i; j++) {
      if (itemName[j].compare(itemName[j+1])>0)  {
         swapItem(itemName[j],itemName[j+1],itemCount[j],itemCount[j+1],itemCost[j],itemCost[j+1]);
      }
    }
  }
}

/**********************************************************
*
* Method swapItem: Class Containers
*_________________________________________________________
* This method will swap the items' info
*_________________________________________________________
* PRE-CONDITIONS
*     string &s1, string &s2, int &count1, int &count2,
* double &n1, double &n2
*
* POST-CONDITIONS
*   swap the items' info
***********************************************************/
template <class E>
void Containers<E>::swapItem(string &s1, string &s2, int &count1, int &count2, double &n1, double &n2) {
    string s;
    int i;
    double cost;
    s = s1;
    s1 = s2;
    s2 = s;
    i = count1;
    count1 = count2;
    count2 = i;
    cost = n1;
    n1 = n2;
    n2 = cost;
}

/**********************************************************
*
* Method DetermineP: Class Containers
*_________________________________________________________
* Determine if any basic customer should convert their
* membership to preferred status.
*_________________________________________________________
* PRE-CONDITIONS
*     no parameter
*
* POST-CONDITIONS
*   determine to switch membershipType
***********************************************************/
template <class E>
void Containers<E>::DetermineP()
{
  setWTotal();
  for(int i = 0;i<current-1;i++)
    {
      if(array[i].getMembershiptype()== "Basic")
      {
      if(array[i].getTotal()>=300)
        {
          cout <<endl;
        array[i].getinfo();
          cout<<"Spend total: "<<array[i].getTotal()<<endl;
  cout <<"if they change to preferred, the rebate is:\n";
        cout<<array[i].getTotal() * 0.05<<endl;

        cout <<"\nThus should convert membership to preferred status."<<endl;
        }
      }
    }
}

/**********************************************************
*
* Method DetermineB: Class Containers
*_________________________________________________________
* Determine if any preferred customer should convert their
* membership to basic status.
*_________________________________________________________
* PRE-CONDITIONS
*     no parameter
*
* POST-CONDITIONS
*   determine to switch membershipType
***********************************************************/
template <class E>
void Containers<E>::DetermineB()
{
  setWTotal();
  for(int i = 0;i<current-1;i++)
    {
      if(array[i].getMembershiptype()== "Preferred")
      {
      if(array[i].getTotal()<300)
      {
        cout <<endl;
        array[i].getinfo();
          cout<<"Spend total: "<<array[i].getTotal()<<endl;
  cout <<"The rebate is:\n";
        cout<<array[i].getTotal() * 0.05<<endl;

        cout <<"\nThus should convert membership to basic status."<<endl;
        }
    }
      }
}
#endif // CONTAINERS_H
