#include <iostream>
#include <string>
#include "Customer.h"

	Customer::Customer()
	{
		fname = "";
		lname = "";
		adress = "";
		phonenum = "";
		email = "";
	}
	Customer::Customer(string _fname, string _lname, string _adress, string _phonenum, string _email)
	{
		fname = _fname;
		lname = _lname;
		adress = _adress;
		phonenum = _phonenum;
		email = _email;
	}
	void Customer::setAll(string _fname, string _lname, string _adress, string _phonenum, string _email)
	{
		fname = _fname;
		lname = _lname;
		adress = _adress;
		phonenum = _phonenum;
		email = _email;
	}
	void Customer::setFname(string _fname)
	{
		fname = _fname;
	}
	void Customer::setLname(string _lname)
	{
		lname = _lname;
	}
	void Customer::setAdress(string _adress)
	{
		adress = _adress;
	}
	void Customer::setPhonenum(string _phonenum)
	{
		phonenum = _phonenum;
	}
	void Customer::setEmail(string _email)
	{
		email = _email;
	}
	string Customer::getFname() const {
		return fname;
	}
	string Customer::getLname() const {
		return lname;
	}
	string Customer::getAdress() const {
		return adress;
	}
	string Customer::getPhonenum() const {
		return phonenum;
	}
	string Customer::getEmail() const {
		return email;
	}
	

	void Customer::Print()
	{
		cout << "First Name is:\t " << fname << endl;
		cout << "Last Name is:\t " << lname << endl;
		cout << "Adress is:\t " << adress << endl;
		cout << "Phone number is: " << phonenum << endl;
		cout << "Email is:\t " << email << endl;
	}
