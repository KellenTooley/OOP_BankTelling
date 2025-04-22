#pragma once
#ifndef _Checking_
#define _Checking_
#include "Account.h"
using namespace std;
class Checking : public Account
{
	bool CheckingExists;
	double overDraftLimit;
public:
	void setOverDraftLimit(double _overDraftLimit);
	double getOverDraftLimit() const;
	bool getCheckingExists() const;
	Checking();
	Checking(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer, double _overDraftLimit);
	void setAll(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer, double _overDraftLimit);
	void WithdrawMoney(double _amount);
	void PrintInfo();
};
#endif
