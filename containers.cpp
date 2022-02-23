#include "containers.h"

void Containers::pushin(member m)
{
  array[current]=m;
  current++;
}

void Containers::getmember(int id)
{
  for(int i =0; i <current;i++)
  {
    if(array[i].getID() == id)
    {
      array[i].getinfo();
      return;
    }
  }
  cout<<"Not Found"<<endl;
}

void Containers::getmember(string name)
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


void Containers::setWareHouse(){
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

void Containers::display(){
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
void Containers::expMonth(string month) {
    bool flag = false;
    for(int i = 0; i < (current - 1); i++){
        if (month[0] == array[i].getEXP()[0] && month[1] == array[i].getEXP()[1]) {
          cout << "EXP:\n";
          array[i].getinfo();
          if (array[i].getMembershiptype().compare("Preferred")==0)
            cout << "Due amount: $75.\n";
          else
            cout << "Due amount: $60.\n";

          flag = true;
        }
    }
    if(!flag)
      cout << "No EXP on the month.\n";
}

member Containers::operator[](int index){
    return array[index];
}

Item Containers::vectorIndex(int index){
    return list[index];
}
unsigned long Containers::getVectorSize(){
    return list.size();
}

int Containers::getCurrent(){
    return current;
}
void Containers::addDay(string Date){
    ifstream myFile(Date);
    string name;
    string date;
    int ID,quantity;
    double cost;
    if(myFile.fail())
        return;
    while (!myFile.eof()) {
        getline(myFile, date, '\n');
        myFile >> ID;
        myFile.get(); //get the '\n'
        getline(myFile, name, '\n');
        myFile >> cost;
        myFile >> quantity;

        Item item;
        item.setItem(name);
        item.setID(ID);
        item.setDate(date);
        item.setQuantity(quantity);
        item.setCost(cost);
        myFile.get();

        list.push_back(item);
    }
}

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



