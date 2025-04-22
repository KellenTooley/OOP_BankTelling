#pragma once
#ifndef _SavingAccount_
#define _SavingAccount_
#include "Account.h"
using namespace std;
class SavingAccount : public Account {
	double interestRate;
	bool SavingExists;
public:
	void setInterestRate(double _interestRate);
	double getInterestRate() const;
	bool getSavingExists();

	SavingAccount();
	SavingAccount(double _interestRate, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer);;

	void setAll(double _interestRate, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer);
	void payInterest();
	void transfer(double amount, SavingAccount& destinationAccount);
	void PrintInfo();
};
#endif //!_SavingAccount
