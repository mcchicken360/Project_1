#ifndef CONTAINERS_H
#define CONTAINERS_H

#include <iostream>
#include <string>
#include "members.h"
#include <fstream>

#include <vector>
#include "item.h"

using namespace std;
class Containers : public member
{
public:
  void pushin(member m);
  void getmember(int id);
  void getmember(string name);
  void setWareHouse();
  void display();
  void expMonth(string month);
  // void insert(member, int index);

  void addDay(string Date);
  //void printDaily();
//  void printMemberReport();

   member operator[](int index);
   Item vectorIndex(int index);
   unsigned long getVectorSize();
   int getCurrent();
   // friend class member;
private:
member array[100];
vector<Item> list;
int current = 0;

};

#endif // CONTAINERS_H
