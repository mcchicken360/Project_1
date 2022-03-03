#include "item.h"
/******************************************************
*   Item()
*   Constructor; Initialize class attributes
*   Parameters: none
*   Variables: None
*   Return: none
*****************************************************/
Item::Item() {}

/***********************************************************
*  void setItem()
*
* MUTATORS; set name of an Item object
*------------------------------------------------------------------
*   Parameters: s(string) - IN //pass in the name attributes
*------------------------------------------------------------------
* VARIABLES:
*   None
* PRE-CONDITIONS
*   None
*
* POST-CONDITIONS
*   set new name attributes of an Item object

*   Return: None
**********************************************************/
void Item::setItem(string s) {
    _item = s;
}

/***********************************************************
*  void setDate()
*
* MUTATORS; set date of an Item object
*------------------------------------------------------------------
*   Parameters: s(string) - IN //pass in the date attributes
*------------------------------------------------------------------
* VARIABLES:
*   None
* PRE-CONDITIONS
*   None
*
* POST-CONDITIONS
*   set new date attributes of an Item object

*   Return: None
**********************************************************/
void Item::setDate(string s) {
    _date = s;
}

/***********************************************************
*  void setID(int num)
*
* MUTATORS; set ID of an Item object
*------------------------------------------------------------------
*   Parameters: num(int) - IN //pass in the ID attributes
*------------------------------------------------------------------
* VARIABLES:
*   None
* PRE-CONDITIONS
*   None
*
* POST-CONDITIONS
*   set new ID attributes of an Item object

*   Return: None
**********************************************************/
void Item::setID(int num) {
    _id = num;
}

/***********************************************************
*  void setQuantity(int num)
*
* MUTATORS; set Quantity of an Item object
*------------------------------------------------------------------
*   Parameters: num(int) - IN //pass in the Quantity attributes
*------------------------------------------------------------------
* VARIABLES:
*   None
* PRE-CONDITIONS
*   None
*
* POST-CONDITIONS
*   set new Quantity attributes of an Item object

*   Return: None
**********************************************************/
void Item::setQuantity(int num) {
    _quantity = num;
}

/***********************************************************
*  void setCost(double num)
*
* MUTATORS; set cost of an Item object
*------------------------------------------------------------------
*   Parameters: num(int) - IN //pass in the cost attributes
*------------------------------------------------------------------
* VARIABLES:
*   None
* PRE-CONDITIONS
*   None
*
* POST-CONDITIONS
*   set new cost attributes of an Item object

*   Return: None
**********************************************************/
void Item::setCost(double num) {
    _cost = num;
}

/***********************************************************
*  string getItem()
*
* ACCESSORS; get name attributes of an Item object
*------------------------------------------------------------------
*   Parameters: None
*------------------------------------------------------------------
* VARIABLES:
*   None
* PRE-CONDITIONS
*   None
*
* POST-CONDITIONS
*   return name attributes of an Item object

*   Return: _item
**********************************************************/
string Item::getItem() {
    return _item;
}

/***********************************************************
*  string getDate()
*
* ACCESSORS; get date attributes of an Item object
*------------------------------------------------------------------
*   Parameters: None
*------------------------------------------------------------------
* VARIABLES:
*   None
* PRE-CONDITIONS
*   None
*
* POST-CONDITIONS
*   return date attributes of an Item object

*   Return: _date
**********************************************************/
string Item::getDate() {
    return _date;
}

/***********************************************************
*  int getID()
*
* ACCESSORS; get ID attributes of an Item object
*------------------------------------------------------------------
*   Parameters: None
*------------------------------------------------------------------
* VARIABLES:
*   None
* PRE-CONDITIONS
*   None
*
* POST-CONDITIONS
*   return ID attributes of an Item object

*   Return: _id
**********************************************************/
int Item::getID() {
    return _id;
}

/***********************************************************
*  int getQuantity()
*
* ACCESSORS; get Quantity attributes of an Item object
*------------------------------------------------------------------
*   Parameters: None
*------------------------------------------------------------------
* VARIABLES:
*   None
* PRE-CONDITIONS
*   None
*
* POST-CONDITIONS
*   return Quantity attributes of an Item object

*   Return: _quantity
**********************************************************/
int Item::getQuantity() {
    return _quantity;
}

/***********************************************************
*  double getCost()
*
* ACCESSORS; get Cost attributes of an Item object
*------------------------------------------------------------------
*   Parameters: None
*------------------------------------------------------------------
* VARIABLES:
*   None
* PRE-CONDITIONS
*   None
*
* POST-CONDITIONS
*   return Cost attributes of an Item object

*   Return: _cost
**********************************************************/
double Item::getCost() {
    return _cost;
}
