#include "item.h"

Item::Item() {}

void Item::setItem(string s) {
    _item = s;
}

void Item::setDate(string s) {
    _date = s;
}

void Item::setID(int num) {
    _id = num;
}

void Item::setQuantity(int num) {
    _quantity = num;
}

void Item::setCost(double num) {
    _cost = num;
}

string Item::getItem() {
    return _item;
}

string Item::getDate() {
    return _date;
}

int Item::getID() {
    return _id;
}

int Item::getQuantity() {
    return _quantity;
}

double Item::getCost() {
    return _cost;
}
