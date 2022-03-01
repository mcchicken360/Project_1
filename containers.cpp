#include "containers.h"



//void Containers::printDaily() {
//    string date;
//    printf("Enter a date to get daily report(enter 03/05/2013):\n");
//    cin >> date;
//    double total;
//    for (size_t i = 0; i < list.size(); i++)
//    {
//        if (list[i].getDate() == date) {
//            printf("Member ID: %d   ", list[i].getID());
//            for(int j = 0; j < current; j++) {
//              if(list[i].getID()== array[j].getID())
//                cout << "MemberType: " << array[j].getMembershiptype() << endl;
//            }
//            cout << "Item: " << list[i].getItem() << endl;
//            printf("price: %.2f     ", list[i].getCost());
//            printf("Quantities: %d\n\n", list[i].getQuantity());
//            total += list[i].getCost()*list[i].getQuantity();
//        }
//    }
//    printf("Total revenue of the day: %.2f\n\n", total);

//}

//void Containers::printMemberReport() {
//  int num;
//  bool flag;
//  do {
//    printf("Please enter 0 or 1, 0 for entry ID to get report, 1 for entry member name to get the reprot:");
//    scanf("%d", &num);
//    if (num == 0 || num == 1) {
//      flag = false;
//    }
//    else {
//      flag = true;
//      printf("Invaid input!\n");
//    }
//    cin.ignore();
//  } while (flag);
//  if (num == 0) {
//    int ID;
//    printf("Enter Member ID to get report(enter 12899):\n");
//    cin >> ID;
//    for (size_t i = 0; i < list.size(); i++)
//    {
//        if (list[i].getID() == ID) {
//            printf("Member ID: %d\n", list[i].getID());
//            cout << "Date: " << list[i].getDate() << endl;
//            cout << "Item: " << list[i].getItem() << endl;
//            printf("price: %.2f     ", list[i].getCost());
//            printf("Quantities: %d\n\n", list[i].getQuantity());
//        }
//    }
//  }
//  else {
//    string name;
//    int ID;
//    printf("Enter Member name to get report(enter Betty Buysalot):\n");
//    getline(cin,name,'\n');
//    for(int i = 0; i < (current - 1); i++){
//        if (name == array[i].getName()) {
//          ID = array[i].getID();
//        }
//    }
//    for (size_t i = 0; i < list.size(); i++)
//    {
//        if (list[i].getID() == ID) {
//            printf("Member ID: %d\n", list[i].getID());
//            cout << "Date: " << list[i].getDate() << endl;
//            cout << "Item: " << list[i].getItem() << endl;
//            printf("price: %.2f     ", list[i].getCost());
//            printf("Quantities: %d\n\n", list[i].getQuantity());
//        }
//    }
//  }
//}



