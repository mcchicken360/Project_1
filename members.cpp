#include "members.h"

/*********************************************************
 * Constructor
 * member();
 * The functionality of the constructor is to initialize
 * the private member variables within the member class.
 * Initialize all member variables to a "NULL" or 0 status.
 * Strings are declared as needed in the txt files provided.
*********************************************************/
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

/*********************************************************
 * Constructor
 * member(const member&);
 * The functionality of the constructor is to initialize
 * the private member variables within the member class.
 * In this function we initialize all member variables to
 * a single argument m.
*********************************************************/
member::member(const member& m)
{
  name = m.name;
  EXP = m.EXP;
  Membershiptype = m.Membershiptype;
  ID = m.ID;
  Totalamount = m.Totalamount;
  rebate = m.rebate;
}

/*********************************************************
 * getinfo();
 * This function is used to return a human-readable description
 * of the provided information in the txt files.
 * For this to work we would need to be provided with
 * a name, ID, membership type, and expiration of their
 * membership
*********************************************************/
void member::getinfo()
{
    cout << left << setw(21) <<this->name <<" " << left << setw(7) <<this->ID<<" "<< setw(10)  << left <<this->Membershiptype<<" "<< left << setw(11)<<this->EXP<<endl;

}

/*********************************************************
 * getID();
 * This function returns the private variable ID, we create
 * a function to return the private variable to make this
 * variable dynamic.
*********************************************************/
int member::getID()
{
    return ID;
}

/*********************************************************
 * getName();
 * This function returns the private variable name, we create
 * a function to return the private variable to make this
 * variable dynamic.
*********************************************************/
string member::getName()
{
    return name;
}

/*********************************************************
 * getEXP();
 * This function returns the private variable EXP (or
 * expiration), we create a function to return the private
 * variable to make this variable dynamic.
*********************************************************/
string member::getEXP()
{
    return EXP;
}

/*********************************************************
 * getMembershiptype();
 * This function returns the private variable Membershiptype,
 * we create a function to return the private variable to
 * make this variable dynamic.
*********************************************************/
string member::getMembershiptype()
{
    return Membershiptype;
}

/*********************************************************
 * getTotal();
 * This function returns the private variable Totalamount,
 * we create a function to return the private variable to
 * make this variable dynamic.
*********************************************************/
double member::getTotal()
{
    return Totalamount;
}

/*********************************************************
 * getRebate();
 * This function returns the private variable rebate,
 * we create a function to return the private variable to
 * make this variable dynamic.
*********************************************************/
double member::getRebate()
{
    return rebate;
}

/*********************************************************
 * setinfo();
 * This function will read information from the txt file
 * provided and set the information needed from the files.
 * The information withheld in the txt files will be needed
 * for later use, however this function declares what information
 * will be held in what private member
*********************************************************/
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

/*********************************************************
 * setTotal(double)
 * This function declares the private variable Totalamount
 * to the argument T. We use this to calculate the total
 * amount customers have spent during a given amount of time,
 * which will be called on later
*********************************************************/
void member::setTotal(double T)
{
    this->Totalamount = T;
}

/*********************************************************
 * setName(string);
 * This function has a parameter value string that is set
 * to the private member name. This is important because
 * these functions update the value of the variable
 * outside of the encapsulating class
*********************************************************/
void member::setName(string value)
{
    name = value;
}

/*********************************************************
 * setDate(string);
 * This function has a parameter value string that is set
 * to the private member EXP. This is important because
 * these functions update the value of the variable
 * outside of the encapsulating class
*********************************************************/
void member::setDate(string value)
{
    EXP = value;
}

/*********************************************************
 * setType(string);
 * This function has a parameter value string that is set
 * to the private member membershiptype. This is important because
 * these functions update the value of the variable
 * outside of the encapsulating class
*********************************************************/
void member::setType(string value)
{
    Membershiptype = value;
}

/*********************************************************
 * setId(string);
 * This function has a parameter value string that is set
 * to the private member ID. This is important because
 * these functions update the value of the variable
 * outside of the encapsulating class
*********************************************************/
void member::setId(int value)
{
    ID = value;
}

/*********************************************************
 * setRebate(string);
 * This function has a parameter value string that is set
 * to the private member rebate. This is important because
 * these functions update the value of the variable
 * outside of the encapsulating class
*********************************************************/
void member::setRebate(double value)
{
    rebate = value;
}

/*********************************************************
 * BtoP();
 * This function is used to change a spcific customers
 * memberstip status to preferred if decided.
*********************************************************/
void member::BtoP()
{
  this->Membershiptype = "Perforred";
}

/*********************************************************
 * PtoB();
 * This function is used to change a spcific customers
 * memberstip status to basic if decided.
*********************************************************/
void member::PtoB()
{
  this -> Membershiptype = "Basic";
}

/*********************************************************
 * operator =(const member&);
 * The overload assignment operator is used to create an
 * object similar to the copy constructor.
 * In this function we have one const argument m and declare
 * that to the private variables
*********************************************************/
void member::operator=(const member& m)
{
  name = m.name;
  EXP = m.EXP;
  Membershiptype = m.Membershiptype;
  ID = m.ID;
  Totalamount = m.Totalamount;
  rebate = m.rebate;
}
