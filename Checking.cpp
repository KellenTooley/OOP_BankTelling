#include "Checking.h"
#include <iostream>

void Checking::setOverDraftLimit(double _overDraftLimit)
{
	if (_overDraftLimit > 0)
	{
		overDraftLimit = _overDraftLimit;
	}
	else
	{
		overDraftLimit = 0;
	}
}
double Checking::getOverDraftLimit() const
{
	return overDraftLimit;
}

void Checking::WithdrawMoney(double _amount)
{
	if (_amount <= getBalance())
	{
		Account::WithdrawMoney(_amount);
	}
	else if (_amount <= (getBalance() + overDraftLimit))
	{
		Account::WithdrawMoney(_amount + 20);
	}
	else
	{
		cout << "Insuficient funds" << endl;
	}
}
void Checking::PrintInfo() {
	Account::PrintInfo();
	cout << "Over Draft limit:" << overDraftLimit << endl;
}


void Checking::setAll(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer, double _overDraftLimit)
{
	Account::setAll(_ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer);
	if (_overDraftLimit > 0)
	{
		overDraftLimit = _overDraftLimit;
	}
	else
	{
		overDraftLimit = 0;
	}
	if (_balance == 0 && _withdrawalCounter == 0 && _depositsCounter == 0 && _overDraftLimit == 0)
	{
		CheckingExists = false;
	}
	else
	{
		CheckingExists = true;
	}
}
Checking::Checking() : Account()
{
	overDraftLimit = 0;
	CheckingExists = false;
}
Checking::Checking(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer, double _overDraftLimit)
	:Account(_ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer)
{
	if (_overDraftLimit >= 0)
	{
		overDraftLimit = _overDraftLimit;
	}
	else
	{
		overDraftLimit = 0;
	}
	CheckingExists = true;
}
bool Checking::getCheckingExists() const
{
	return CheckingExists;
}
