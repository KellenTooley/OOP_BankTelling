#include "Account.h"
#include <iostream>
void Account::setID(int _ID) {
	if (_ID > 0) {
		ID = _ID;
	}
	else {
		ID = 0;
	}
}
void Account::setBalance(double _balance) {
	if (_balance > 0) {
		balance = _balance;
	}
	else {
		balance = 0;
	}
}
void Account::setWithdrawalCounter(int _withdrawalCounter) {
	withdrawalCounter = 0;
}
void Account::setDepositsCounter(int _depositsCounter) {
	depositsCounter = 0;
}
void Account::setAccountCustomer(Customer* _accountCustomer) {
	accountCustomer = _accountCustomer;
}
int Account::getID() const {
	return ID;
}
double Account::getBalance() const {
	return balance;
}
int Account::getWithDrawelCounter() const {
	return withdrawalCounter;
}
int Account::getDepositsCounter() const {
	return depositsCounter;
}
Customer Account::getAccountCustomer() {
	return *accountCustomer;
}
Account::Account(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer) {
	setID(_ID);
	setBalance(_balance);
	setWithdrawalCounter(_withdrawalCounter);
	setDepositsCounter(_depositsCounter);
	setAccountCustomer(_accountCustomer);
}
Account::Account() {
	ID = 0;
	balance = 0;
	withdrawalCounter = 0;
	depositsCounter = 0;
	accountCustomer = 0;
}
void Account::setAll(int _ID, double _balance, int _withdrawalCounter, int _depositsCounter, Customer* _accountCustomer) {
	setID(_ID);
	setBalance(_balance);
	setWithdrawalCounter(_withdrawalCounter);
	setDepositsCounter(_depositsCounter);
	setAccountCustomer(_accountCustomer);
}
void Account::depositMoney(double amount) {
	if (amount >= 0) {
		balance += amount;
		depositsCounter++;
	}
	else {

	}
}
void Account::WithdrawMoney(double amount) {
	if (amount >= 0) {
		if (balance >= amount) {
			balance -= amount;
			withdrawalCounter++;
		}
	}
	else {

	}
}
void Account::PrintInfo() {
	accountCustomer->Print();

	cout << "ID:\t\t " << ID << endl;

	cout << "Balance:\t " << balance << endl;

	cout << "Withdraw Counter:" << withdrawalCounter << endl;

	cout << "Deposits Counter:" << depositsCounter << endl;

}
