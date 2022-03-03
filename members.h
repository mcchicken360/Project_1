/***********************************************************************************
 * Authors      : David Mei, Matthew Mirbasoo, You Lyu, Ruitau He
 * Project #1   : Super Warehouse
 * Class        : CS008
 * Due Date     : 03/03/2022
***********************************************************************************/
#ifndef MEMBERS_H
#define MEMBERS_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class member
{
public:
  /*********************
   * ** CONSTRUCTOR **
  *********************/
  member();
  member(const member&);

  /**************************
   * ***** GETTERS *****
  **************************/
  void getinfo();
  int getID();
  string getName();
  string getEXP();
  string getMembershiptype();
  double getTotal();
  double getRebate();

  /**************************
   * ***** SETTERS *****
  **************************/
  void setinfo();
  void setTotal(double);
  void setName(string);
  void setDate(string);
  void setType(string);
  void setId(int);
  void setRebate(double);

  /**************************
   * Basic to Preferred &
   * Preferred to Basic
  **************************/
  void BtoP();
  void PtoB();

  /**************************
   * FRIEND OF THE CLASS
  **************************/
  friend class memberc;

  /*****************************
   * ASSIGNED OVERLOAD OPERATOR
  *****************************/
  void operator=(const member&);

private:
  string name,EXP,Membershiptype;
  int ID;
  double Totalamount, rebate;
  bool ispreferred;
};

/*********************
 * ** CONSTRUCTOR **
*********************/
/***********************************************************
 * member();
 * Initializes class attributes
 * Parameter: none
 * Return: none
 ***********************************************************/
/***********************************************************
 * member(const member& m);
 * Initializes class attributes under one argument
 * Parameter: m
 * Return: none
************************************************************/

/**************************
 * ***** GETTERS *****
**************************/
/***********************************************************
 * getinfo();
 * Prints a human-readble description of the individuals name,
 * ID, membership type and its expiration.
 * Parameters: none
 * Return: none
************************************************************/
/***********************************************************
 * getID();
 * Return the private variable associated with the function
 * Parameters: none
 * Return: ID
************************************************************/
/***********************************************************
 * getName();
 * Return the private variable associated with the function
 * Parameters: none
 * Return: name
************************************************************/
/***********************************************************
 * getEXP();
 * Return the private variable associated with the function
 * Parameters: none
 * Return: EXP
************************************************************/
/***********************************************************
 * getMembershiptype();
 * Return the private variable associated with the function
 * Parameters: none
 * Return: Membershiptype
************************************************************/
/***********************************************************
 * getTotal();
 * Return the private variable associated with the function
 * Parameters: none
 * Return: Totalamount
************************************************************/
/***********************************************************
 * getRebate();
 * Return the private variable associated with the function
 * Parameters: none
 * Return: rebate
************************************************************/

/**************************
 * ***** SETTERS *****
**************************/
/***********************************************************
 * setinfo();
 * Outputs the given information in the txt files in order
 * by name, ID, membership type and expiration
 * Parameters: none
 * Return: none
************************************************************/
/************************************************************
 * setTotal(double);
 * Declares Totalamount to the parameter
 * Parameter: T
 * Return: none
************************************************************/
/************************************************************
 * setName(string);
 * Declares name to the parameter
 * Parameter: value
 * Return: none
************************************************************/
/************************************************************
 * setDate(string)
 * Declares EXP to the parameter
 * Parameter: value
 * Return: none
************************************************************/
/************************************************************
 * setType(string)
 * Declares Membershiptype to the parameter
 * Parameter: value
 * Return: none
************************************************************/
/************************************************************
 * setID(int);
 * Declares ID to the parameter
 * Parameter: value
 * Return: none
************************************************************/
/************************************************************
 * setRebate(double);
 * Declares rebate to the parameter
 * Parameter: value
 * Return: none
************************************************************/

/**************************
 * Basic to Preferred &
 * Preferred to Basic
**************************/
/************************************************************
 * BtoP();
 * Declares Membershiptype to Preferred
 * Parameters: none
 * Return: none
************************************************************/
/************************************************************
 * PtoB();
 * Declares Membershiptype to Basic
 * Parameters: none
 * Return: none
************************************************************/

/*****************************
 * ASSIGNED OVERLOAD OPERATOR
*****************************/
/************************************************************
 *  operator =(const member&);
 *  Assigns all private variables to itself with reference to
 *  the argument
 *  Parameters: m
 *  Return: none
************************************************************/
#endif // MEMBERS_H
