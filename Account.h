#pragma once
#ifndef _Account_
#define _Account_
#include "Customer.h"

using namespace std;
class Account {
	int ID;
	double balance;
	int withdrawalCounter;
	int depositsCounter;
	Customer* accountCustomer;
public:
	void setID(int _ID);
	void setBalance(double _balance);
	void setWithdrawalCounter(int _withdrawalCounter);
	void setDepositsCounter(int _depositsCounter);
	void setAccountCustomer(Customer* _accountCustomer);

	int getID() const;
	double getBalance() const;
	int getWithDrawelCounter() const;
	int getDepositsCounter() const;
	Customer getAccountCustomer();

	Account(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer);
	Account();

	void setAll(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer);
	void depositMoney(double amount);
	void WithdrawMoney(double amount);
	void PrintInfo();
};
#endif //!_Account_
