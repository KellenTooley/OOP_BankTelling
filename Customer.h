#pragma once
#ifndef _Customer_
#define _Customer_
#include <string>
using namespace std;
class Customer
{
	string fname;
	string lname;
	string adress;
	string phonenum;
	string email;
public:
	Customer();
	Customer(string _fname, string _lname, string _adress, string _phonenum, string _email);
	void setAll(string _fname, string _lname, string _adress, string _phonenum, string _email);
	void setFname(string _fname);
	void setLname(string _lname);
	void setAdress(string _adress);
	void setPhonenum(string _phonenum);
	void setEmail(string _email);

	string getFname()const;
	string getLname()const;
	string getAdress()const;
	string getPhonenum()const;
	string getEmail()const;
	void Print();
};

#endif //!_Customer_
