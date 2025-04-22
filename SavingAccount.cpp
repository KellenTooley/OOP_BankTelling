#include <iostream>
#include <string>
#include "SavingAccount.h"

void SavingAccount::setInterestRate(double _interestRate) {
	if (_interestRate > 0) {
		interestRate = _interestRate;
	}
	else {
		interestRate = 0;
	}
}
double SavingAccount::getInterestRate() const {
	return interestRate;
}

bool SavingAccount::getSavingExists()
{
	return SavingExists;
}
void SavingAccount::setAll(double _interestRate, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer) {
	setInterestRate(_interestRate);
	Account::setAll(_ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer);
	if (_interestRate == 0 && _balance == 0 && _withdrawalCounter == 0 && _depositsCounter == 0)
	{
		SavingExists = false;
	}
	else
	{
		SavingExists = true;
	}
}
SavingAccount::SavingAccount(double _interestRate, int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer)
	: Account(_ID, _balance, _withdrawalCounter, _depositsCounter, _accountCustomer) {
	setInterestRate(_interestRate);
	SavingExists = true;
}
SavingAccount::SavingAccount() : Account() {
	interestRate = 0.0;
	SavingExists = false;
}

void SavingAccount::payInterest() {
	double interest;
	interest = getBalance() * interestRate;
	setBalance(getBalance() + interest);
}
void SavingAccount::transfer(double amount, SavingAccount& destinationAccount) {
	if (getBalance() >= amount) {
		setBalance(getBalance() - amount);
		destinationAccount.setBalance(destinationAccount.getBalance() + amount);
	}
}
void SavingAccount::PrintInfo() {
	Account::PrintInfo();
	cout << "Interest Rate: " << interestRate << "%." << endl;
}
