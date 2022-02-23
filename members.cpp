#include "members.h"

member::member()
{
  name = "No Name.";
  EXP = "1/1/2000";
  Membershiptype = "NON.";
  ID = 0;
  Totalamount = 0.0;
  rebate = 0.0;
  ispreferred = false;
}

void member::setinfo()
{
  cout << "Read warehouse shoppers.txt\n";
  cout <<"Name :";
  cin >>name;
   cout <<"ID :";
  cin >>ID;
   cout <<"Membershiptype :";
  cin >>Membershiptype;
  if(Membershiptype=="Preferred" && Membershiptype=="preferred")
  ispreferred=true;
   cout <<"EXP :";
  cin >>EXP;
}

void member::getinfo()
{
    cout << left << setw(21) <<this->name <<" " << left << setw(7) <<this->ID<<" "<< setw(10)  << left <<this->Membershiptype<<" "<< left << setw(11)<<this->EXP<<endl;

}

int member::getID()
{
    return ID;
}

string member::getName()
{
return name;
}

string member::getEXP()
{
return EXP;
}

string member::getMembershiptype() {
  return Membershiptype;
}


void update()
{
  //NO IDEA YET
}

void member::setName(string value){
    name = value;
}
void member::setDate(string value){
    EXP = value;
}
void member::setType(string value){
    Membershiptype = value;
}
void member::setId(int value){
    ID = value;
}
