#ifndef ITEM_H
#define ITEM_H
#include "members.h"
#include <vector>
using namespace std;

class Item
{
  public:
    Item();
    void newDate(string fileName);
    void setItem(string);
    void setDate(string);
    void setID(int);
    void setQuantity(int);
    void setCost(double);

    string getItem();
    string getDate();
    int getID();
    int getQuantity();
    double getCost();

  private:
    string _item, _date;
    int _id, _quantity;
    double _cost;
    vector <string> _storeDates;
};

#endif // ITEM_H
