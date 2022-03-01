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
  void pushin(E m);
  string getmember(int id);
  void getmember(string name);
  void setWareHouse();
  void display();
  // void insert(member, int index);

  void addDay(string Date);
  void findItem(string s);
  //void printDaily();
//  void printMemberReport();

   E operator[](int index);
   Item vectorIndex(int index);
   unsigned long getVectorSize();
   int getCurrent();
   // friend class member;
   vector<string> itemName;
   vector<int> itemCount;
   vector<double> itemCost;

   void bestSelling();

private:
E array[100];
vector<Item> list;
int current = 0;

};

template<class E>
void Containers<E>::pushin(E m)
{
  array[current]=m;
  current++;
}

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
// member memberc::operator[](int index){
//   return array[index];
// }

// void memberc::insert(member value, int index){
//     array[index] = value;
// }

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

template<class E>
void Containers<E>::display(){
    for(int i = 0; i < (current - 1); i++){
        cout << "Customer " << i + 1 << ": ";
        array[i].getinfo();
    }
}


// void Containers::getMemberType(int value){
//   bool complex;
//   complex = false;
//     for(int i = 0; i < (current - 1); i++){
//        if(array[i].getID() == value)
//               array[i].getinfo();
//         else
//           complex = true;
//     }
//     if(complex)
//       cout << "No matching customer.";
// }


template<class E>
E Containers<E>::operator[](int index){
    return array[index];
}
template<class E>
Item Containers<E>::vectorIndex(int index){
    return list[index];
}
template<class E>
unsigned long Containers<E>::getVectorSize(){
    return list.size();
}
template<class E>
int Containers<E>::getCurrent(){
    return current;
}
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
        for (int i=0; i< itemName.size(); i++) {
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

#endif // CONTAINERS_H
