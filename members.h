#ifndef MEMBERS_H
#define MEMBERS_H


#include <iostream>
#include <string>
#include <fstream>
//#include "memberc.h"

using namespace std;
class member
{
public:
  member();
  void getinfo();
  void setinfo();
  int getID();
  string getName();
  string getEXP();
  string getMembershiptype();


  void update(); //for update a member's shoping info
  double getRebate();

  //void SalesReport(Date d);//Date d is date class object
  void getTotalpurchases(string name);
  void getTotalpurchases(int id);
  void YearlyReport();
  friend class memberc;

    void setName(string);
    void setDate(string);
    void setType(string);
    void setId(int);


private:
  string name,EXP,Membershiptype; //expiration date
  int ID;
  double Totalamount, rebate;
  bool ispreferred;
};
#endif // MEMBERS_H
