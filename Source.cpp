#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
//Add TEMP folder to C:Drive
#include "Customer.h"
#include "Account.h"
#include "SavingAccount.h"
#include "Checking.h"

using namespace std;

//aggregate functions
void menuSelection(int &, int);
void menuConfirmation(char&);
bool determineCustomer(const int, int&, Customer[]);
double validateCurrency();
void SaveCheckingToFile(Checking _account, Customer _customer);
void SaveSavingToFile(SavingAccount _account, Customer _customer);

//Main body functions
void createNewCustomer(const int, Customer[]);
void createCheckingAccount(const int, Customer[], Checking[]);
void createSavingAccount(const int SIZE, Customer[], SavingAccount[]);
void viewAccountInformation(const int SIZE, Customer customerList[], Checking CheckingAccountList[], SavingAccount SavingAccountList[]);
void modifyAccountInformation(const int SIZE, Customer customerList[], Checking CheckingAccountList[], SavingAccount SavingAccountList[]);
void deleteAccount(const int SIZE, Customer customerList[], Checking CheckingAccountList[], SavingAccount SavingAccountList[]);
void transferBetweenCustomers(const int SIZE, Customer customerList[], Checking CheckingAccountList[], SavingAccount SavingAccountList[]);
void transferBetweenCustomerAccounts(const int SIZE, Customer customerList[], Checking CheckingAccountList[], SavingAccount SavingAccountList[]);
void transferToOrFromCustomer(const int SIZE, Customer customerList[], Checking CheckingAccountList[], SavingAccount SavingAccountList[]);
void saveDataToFile(const int SIZE, Customer customerList[], Checking CheckingAccountList[], SavingAccount SavingAccountList[]);




int main() {
	const int SIZE = 10;
	Customer customerList[SIZE];
	Checking CheckingAccountList[SIZE];
	SavingAccount SavingAccountList[SIZE];
	string password;
	cout << "-----Welcome to Tooley & Schulze Banking-----" << endl << endl;
	cout << "\tEnter Super Secure Password: ";
	cin >> password;
	int userChoice;
	if (password == "1234")
	{

		int userChoice;
		do {
			system("cls");
			cout << "---------Banking System---------" << endl;
			cout << "1) Create a new customer." << endl;
			cout << "2) Create a Checking Account." << endl;
			cout << "3) Create a Saving Account." << endl;
			cout << "4) View Account Information." << endl;
			cout << "5) Modify Account Information." << endl;
			cout << "6) Delete Accounts." << endl;
			cout << "7) Transfer Money Between Customers." << endl;
			cout << "8) Transfer Money Between Checkings and Savings." << endl;
			cout << "9) Save data to a file." << endl;
			cout << "10) Deposit or withdraw money from an account." << endl;
			cout << "11) Exit." << endl << endl;

			menuSelection(userChoice, 11);


			switch (userChoice) {
			case 1:
				//1) Create a new customer account.
				createNewCustomer(SIZE, customerList);
				break;
			case 2:
				//2) Create a checking account.
				createCheckingAccount(SIZE, customerList, CheckingAccountList);

				break;
			case 3:
				//3) Create a saving account.
				createSavingAccount(SIZE, customerList, SavingAccountList);

				break;
			case 4:
				//4) View Account information.
				viewAccountInformation(SIZE, customerList, CheckingAccountList, SavingAccountList);

				break;
			case 5:
				//5) Modify Account information.
				modifyAccountInformation(SIZE, customerList, CheckingAccountList, SavingAccountList);

				break;
			case 6:
				//6) Delete accounts.
				deleteAccount(SIZE, customerList, CheckingAccountList, SavingAccountList);

				break;
			case 7:
				//7) Transfer between customers.
				transferBetweenCustomers(SIZE, customerList, CheckingAccountList, SavingAccountList);

				break;
			case 8:
				//8) Transfer between accounts.
				transferBetweenCustomerAccounts(SIZE, customerList, CheckingAccountList, SavingAccountList);

				break;
			case 9:
				saveDataToFile(SIZE, customerList, CheckingAccountList, SavingAccountList);

				break;
			case 10:
				//10) Deposit or withdraw money from an account
				transferToOrFromCustomer(SIZE, customerList, CheckingAccountList, SavingAccountList);
				break;
			}

		} while (userChoice != 11);
		cout << "Have a great day!" << endl;
	}
	system("pause");
	return 0;
}
void menuSelection(int &userValue, int upperLimit) {
	//Recieve and validate input for a menu selection
	do {
		cout << "Please enter your choice: ";
		cin >> userValue;
		//if the value is a number, and is also in the desired range
		if (cin.good() && userValue >= 1 && userValue <= upperLimit) {
			return;
		}
		else {
			cout << "Wrong option entered. Please try again." << endl;
			//Clear the entered value from the console. Prevents an infinite loop when inputing a string value
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (userValue < 1 || userValue > upperLimit);
}
void menuConfirmation(char& userValue) {
	//Recieve and validate input for a menu confirmation, then return the input by reference
	do {
		cout << "Please enter your choice: ";
		cin >> userValue;
		//if the value is a y or n, exit the loop
		if (tolower(userValue) == 'y' || tolower(userValue) == 'n') {
			return;
		}
		else {
			cout << "Wrong option entered. Please try again." << endl;
			//Clear the entered value from the console. Prevents an infinite loop when inputing a string value
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (true);
}
bool determineCustomer(const int SIZE, int& customerID, Customer customerList[]) {
	//Receive user input on the customer's name and return the ID of the account.
	string customerFName, customerLName;
	bool accountExists = false;

	do {
		cout << "Please enter the customer's first name: ";
		cin >> customerFName;
		cout << "Please enter the customer's last name: ";
		cin >> customerLName;

		//Check if the customer record exists
		for (int i = 0; i < SIZE; i++) {
			if (customerList[i].getFname() == customerFName && customerList[i].getLname() == customerLName) {
				accountExists = true;
				customerID = i;
				return true;
			}
		}
		if (accountExists == false) {
			char userChoice = 'n';
			cout << "Customer name does not exist. Would you like to try again? (Y/N)." << endl;
			menuConfirmation(userChoice);
			if (tolower(userChoice) == 'y') {
				accountExists = false;
			}
			else {
				return false;
			}

		}

	} while (accountExists == false);
}
double validateCurrency() {
	double userValue = 0.0;
	do {
		cin >> userValue;
		//if the value is a number, and is also zero or above
		if (cin.good() && userValue >= 0) {
			return userValue;
		}
		else {
			cout << "Wrong option entered. Please try again." << endl;
			//Clear the entered value from the console. Prevents an infinite loop when inputing a string value
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (true);
}
void createNewCustomer(const int SIZE, Customer customerList[]) {
	system("cls");
	cout << "---------Create a New Customer--------" << endl;
	string customerFName, customerLName, address, phonenum, email;

	cout << "Please enter the customer's first name: ";
	cin >> customerFName;
	cout << "Please enter the customer's last name: ";
	cin >> customerLName;
	cout << "Please enter the customer's address: ";
	cin.ignore();
	getline(cin, address);
	cout << "Please enter the customer's phone number: ";
	getline(cin, phonenum);
	cout << "Please enter the customer's email: ";
	cin >> email;
	int ID;
	//Check if the customer record exists
	for (int i = 0; i < SIZE; i++) {
		if (customerList[i].getFname() == customerFName && customerList[i].getLname() == customerLName && customerList[i].getEmail() == email 
			&& customerList[i].getAdress() == address && customerList[i].getPhonenum() == phonenum) {
			cout << "The customer already exist." << endl;
			cout << "Exiting to Main Menu..." << endl;
			system("pause");
			return;
		}
	}
	//customer does not already exist
	//Find an account ID that is not already used
	for (int i = 0; i < SIZE; i++) {
		if (customerList[i].getFname() == "" && customerList[i].getLname() == "") {
			ID = i;
			customerList[ID].setAll(customerFName, customerLName, address, phonenum, email);
			break;
		}
	}

	cout << "---New Customer Information---" << endl;
	customerList[ID].Print();

	cout << "Exiting to Main Menu..." << endl;
	system("pause");
}
void createCheckingAccount(const int SIZE, Customer customerList[], Checking CheckingAccountList[]) {
	system("cls");
	cout << "---------Create a Checking Account--------" << endl;

	//Variable to store the ID of the customer account we are using
	int ID; 
	//if the user does not determine what customer to use, exit the seletection. Otherwise continue.
	if (!determineCustomer(SIZE, ID, customerList)) {
		cout << "Exiting to Main Menu..." << endl;
		system("pause");
		return;
	}

	//Create the checking account with all values set to zero.
	CheckingAccountList[ID].setAll(ID, 0, 0, 0, &customerList[ID], 20);
	cout << "Account created successfully!" << endl;
	system("pause");

}
void createSavingAccount(const int SIZE, Customer customerList[], SavingAccount SavingAccountList[]) {
	system("cls");
	cout << "---------Create a Savings Account--------" << endl;

	//Variable to store the ID of the customer account we are using
	int ID;
	//if the user does not determine what customer to use, exit the seletection. Otherwise continue.
	if (!determineCustomer(SIZE, ID, customerList)) {
		cout << "Exiting to Main Menu..." << endl;
		system("pause");
		return;
	}

	//Create the Saving account with all values set to zero.
	double interestRate = 0.02;
	SavingAccountList[ID].setAll(interestRate, ID, 0, 0, 0, &customerList[ID]);

	cout << "Account created successfully!" << endl;
	system("pause");

}
void viewAccountInformation(const int SIZE, Customer customerList[], Checking CheckingAccountList[], SavingAccount SavingAccountList[]) {
	system("cls");
	cout << "---------View Account Information--------" << endl;

	//Variable to store the ID of the customer account we are using
	int ID;
	//if the user does not determine what customer to use, exit the seletection. Otherwise continue.
	if (!determineCustomer(SIZE, ID, customerList)) {
		cout << "Exiting to Main Menu..." << endl;
		system("pause");
		return;
	}

	int userChoice = 4;
	do {
		cout << "-------------------------------------" << endl;
		cout << "1) View customer records." << endl;
		cout << "2) View customer checkings account." << endl;
		cout << "3) View customer savings account." << endl;
		cout << "4) Exit." << endl;

		menuSelection(userChoice, 4);

		switch (userChoice) {
		case 1:
			system("cls");
			cout << "---------Customer Records--------" << endl;
			customerList[ID].Print();
			break;
		case 2:
			if (CheckingAccountList[ID].getCheckingExists() == true)
			{
				system("cls");
				cout << "---------Customer Checkings Account--------" << endl;
				CheckingAccountList[ID].PrintInfo();
			}
			else
			{
				system("cls");
				cout << "Customer does not have a Checking Account." << endl;
			}
			break;
		case 3:
			if (SavingAccountList[ID].getSavingExists() == true)
			{
				system("cls");
				cout << "---------Customer Savings Account--------" << endl;
				SavingAccountList[ID].PrintInfo();
			}
			else
			{
				system("cls");
				cout << "Customer does not have a Saving Account." << endl;
			}
			break;
		}

	} while (userChoice != 4);

	cout << "Exiting to Main Menu..." << endl;
	system("pause");
}
void modifyAccountInformation(const int SIZE, Customer customerList[], Checking CheckingAccountList[], SavingAccount SavingAccountList[]) {
	system("cls");
	cout << "---------Modify Account Information--------" << endl;

	//Variable to store the ID of the customer account we are using
	int ID;
	//if the user does not determine what customer to use, exit the seletection. Otherwise continue.
	if (!determineCustomer(SIZE, ID, customerList)) {
		cout << "Exiting to Main Menu..." << endl;
		system("pause");
		return;
	}

	int userChoice = 4;
	do {
		cout << "-------------------------------------" << endl;
		cout << "1) Modify customer records." << endl;
		cout << "2) Modify customer checkings account." << endl;
		cout << "3) Modify customer savings account." << endl;
		cout << "4) Exit." << endl;

		menuSelection(userChoice, 4);

		string userValue;
		int userSubChoice = 6;
		double userMonetaryValue;
		switch (userChoice) {
		case 1:
			cout << "---------Modifying Customer Records--------" << endl;
			cout << "---Current Information---" << endl;
			customerList[ID].Print();
			cout << endl;
			do {
				cout << "-------------------------------------" << endl;
				cout << "1) Modify customer first name." << endl;
				cout << "2) Modify customer last name." << endl;
				cout << "3) Modify customer address." << endl;
				cout << "4) Modify customer phone number." << endl;
				cout << "5) Modify customer email" << endl;
				cout << "6) Exit." << endl;

				menuSelection(userSubChoice, 6);

				switch (userSubChoice)
				{
				case 1:
					cout << "---Modify customer first name---" << endl;
					cout << "Please enter the new first name: " << endl;
					cin >> userValue;
					customerList[ID].setFname(userValue);
					break;
				case 2:
					cout << "---Modify customer last name---" << endl;
					cout << "Please enter the new last name: " << endl;
					cin >> userValue;
					customerList[ID].setLname(userValue);
					break;
				case 3:
					cout << "---Modify customer address---" << endl;
					cout << "Please enter the new address: " << endl;
					cin.ignore();
					getline(cin, userValue);
					customerList[ID].setAdress(userValue);
					break;
				case 4:
					cout << "---Modify customer phone number---" << endl;
					cout << "Please enter the new phone number: " << endl;
					cin.ignore();
					getline(cin, userValue);
					customerList[ID].setPhonenum(userValue);
					break;
				case 5:
					cout << "---Modify customer email---" << endl;
					cout << "Please enter the new email: " << endl;
					cin >> userValue;
					customerList[ID].setEmail(userValue);
					break;
				}
				cout << "---New Current Information---" << endl;
				customerList[ID].Print();
				cout << endl;
			} while (userSubChoice != 6);
			break;

		case 2:
			if (CheckingAccountList[ID].getCheckingExists() == true)
			{
				cout << "---------Modifying Checkings Account--------" << endl;
				CheckingAccountList[ID].PrintInfo();
				cout << endl;
				cout << "---Modify over draft limit---" << endl;
				cout << "Please enter the new over draft limit: " << endl;
				cin >> userMonetaryValue;
				CheckingAccountList[ID].setOverDraftLimit(userMonetaryValue);

				cout << "---New Current Information---" << endl;
				CheckingAccountList[ID].PrintInfo();
				cout << endl;
			}
			else
			{
				system("cls");
				cout << "Can not edit account that does not exist." << endl;
				system("pause");
			}
			break;

		case 3:
			if (SavingAccountList[ID].getSavingExists() == true)
			{
				cout << "---------Modifying Savings Account--------" << endl;
				SavingAccountList[ID].PrintInfo();
				cout << endl;
				cout << "---Modify Interest Rate---" << endl;

				cout << "Please enter the new interest rate: " << endl;
				cin >> userMonetaryValue;
				SavingAccountList[ID].setInterestRate(userMonetaryValue);

				cout << "---New Current Information---" << endl;
				SavingAccountList[ID].PrintInfo();
				cout << endl;
			}
			else
			{
				system("cls");
				cout << "Can not edit account that does not exist." << endl;
				system("pause");
			}
			break;
		}

		
	} while (userChoice != 4);
	cout << "Exiting to Main Menu..." << endl;
	system("pause");
}
void deleteAccount(const int SIZE, Customer customerList[], Checking CheckingAccountList[], SavingAccount SavingAccountList[]) {
	system("cls");
	cout << "---------Delete Account--------" << endl;

	//Variable to store the ID of the customer account we are using
	int ID;
	//if the user does not determine what customer to use, exit the seletection. Otherwise continue.
	if (!determineCustomer(SIZE, ID, customerList)) {
		cout << "Exiting to Main Menu..." << endl;
		system("pause");
		return;
	}

	int userChoice = 4;
	do {
		cout << "-------------------------------------" << endl;
		cout << "1) Delete entire customer account." << endl;
		cout << "2) Delete customer checkings account." << endl;
		cout << "3) Delete customer savings account." << endl;
		cout << "4) Exit." << endl;

		menuSelection(userChoice, 4);

		char userSubChoice;
		switch (userChoice) {

		case 1:
			//Delete the customer and every account
			cout << "-------------------------------------" << endl;
			cout << "Warning! This action will delete the entire customer from the system." << endl;
			cout << "Do you want to continue? (Y/N): ";
			menuConfirmation(userSubChoice);
			if (tolower(userSubChoice) == 'y') {
				//Ensure that the customer accounts do not have any money in them.
				if (CheckingAccountList[ID].getBalance() == 0 && SavingAccountList[ID].getBalance() == 0) {
					customerList[ID].setAll("", "", "", "", "");
					CheckingAccountList[ID].setAll(0, 0, 0, 0, &customerList[ID], 0);
					SavingAccountList[ID].setAll(0, 0, 0, 0, 0, &customerList[ID]);
					cout << "Account deleted." << endl;
				}
				else {
					cout << "Error: The customer still has money in an account." << endl;
					cout << "Ensure the remaining balance is zero before deleting the account" << endl;
				}
				
			}
				break;
		case 2:
			//Delete only the customers checking account
			cout << "-------------------------------------" << endl;
			cout << "Warning! This action will delete the entire checkings account from the system." << endl;
			cout << "Do you want to continue? (Y/N): ";
			menuConfirmation(userSubChoice);
			if (tolower(userSubChoice) == 'y') {
				//Ensure that the checking account does not have any money in it.
				if (CheckingAccountList[ID].getBalance() == 0) {
					CheckingAccountList[ID].setAll(0, 0, 0, 0, &customerList[ID], 0);
					cout << "Checking account deleted." << endl;
				}
				else {
					cout << "Error: The customer still has money in the checking account." << endl;
					cout << "Ensure the remaining balance is zero before deleting the account" << endl;
				}

			}
			break;
		case 3:
			//Delete only the customers checking account
			cout << "-------------------------------------" << endl;
			cout << "Warning! This action will delete the entire saving account from the system." << endl;
			cout << "Do you want to continue? (Y/N): ";
			menuConfirmation(userSubChoice);
			if (tolower(userSubChoice) == 'y') {
				//Ensure that the Saving account does not have any money in it.
				if (SavingAccountList[ID].getBalance() == 0) {
					SavingAccountList[ID].setAll(0, 0, 0, 0, 0, &customerList[ID]);
					cout << "Saving account deleted." << endl;
				}
				else {
					cout << "Error: The customer still has money in the saving account." << endl;
					cout << "Ensure the remaining balance is zero before deleting the account" << endl;
				}

			}
			break;
		}
	} while (userChoice != 4);

	cout << "Exiting to Main Menu..." << endl;
	system("pause");
}
void transferBetweenCustomers(const int SIZE, Customer customerList[], Checking CheckingAccountList[], SavingAccount SavingAccountList[]) {
	system("cls");
	cout << "---------Transfer Between Customers--------" << endl;

	//Variable to store the ID of the customer account we are using
	int ID_Withdraw;
	//if the user does not determine what customer to use, exit the seletection. Otherwise continue.
	cout << "---Enter Information for the withdrawing customer:---" << endl;
	if (!determineCustomer(SIZE, ID_Withdraw, customerList)) {
		cout << "Exiting to Main Menu..." << endl;
		system("pause");
		return;
	}
	int userWithdrawChoice;
	cout << "What account do you want to withdraw from?:" << endl;
	cout << "1) Checkings account. " << endl;
	cout << "2) Savings account. " << endl;
	cout << "3) Cancel." << endl;
	menuSelection(userWithdrawChoice, 3);
	if (userWithdrawChoice == 3) {
		return;
	}

	int ID_Deposit;
	//if the user does not determine what customer to use, exit the seletection. Otherwise continue.
	cout << "---Enter Information for the depositing customer:---" << endl;
	if (!determineCustomer(SIZE, ID_Deposit, customerList)) {
		cout << "Exiting to Main Menu..." << endl;
		system("pause");
		return;
	}
	int userDepositChoice;
	cout << "What account do you want to deposit into?:" << endl;
	cout << "1) Checkings account. " << endl;
	cout << "2) Savings account. " << endl;
	cout << "3) Cancel." << endl;
	menuSelection(userDepositChoice, 3);
	if (userWithdrawChoice == 3) {
		return;
	}

	double transferAmount = 0.0;
	bool validTransfer = false;
	do {
		cout << "-----------------------" << endl;
		cout << "Please enter the amount you wish to transfer: $";
		transferAmount = validateCurrency();

		//Checking to Checking
		if (userWithdrawChoice == 1 && userDepositChoice == 1) {
			if (CheckingAccountList[ID_Withdraw].getCheckingExists() == true && CheckingAccountList[ID_Deposit].getCheckingExists() == true) {
				//Check if there is enough money in the withdrawal account
				if (transferAmount <= (CheckingAccountList[ID_Withdraw].getBalance() + CheckingAccountList[ID_Withdraw].getOverDraftLimit())) {
					CheckingAccountList[ID_Withdraw].WithdrawMoney(transferAmount);
					CheckingAccountList[ID_Deposit].depositMoney(transferAmount);
					validTransfer = true;
				}
				else {
					validTransfer = false;
				}
			}
			else {
				cout << "Account does not exist. Please try again." << endl;
				system("pause");
				return;
			}
		}
		else if (userWithdrawChoice == 1 && userDepositChoice == 2) { //Checking to saving
			if (CheckingAccountList[ID_Withdraw].getCheckingExists() == true && SavingAccountList[ID_Deposit].getSavingExists() == true) {

				//Check if there is enough money in the withdrawal account
				if (transferAmount <= CheckingAccountList[ID_Withdraw].getBalance() + CheckingAccountList[ID_Withdraw].getOverDraftLimit()) {
					CheckingAccountList[ID_Withdraw].WithdrawMoney(transferAmount);
					SavingAccountList[ID_Deposit].depositMoney(transferAmount);
					validTransfer = true;
				}
				else {
					validTransfer = false;
				}
			}
			else {
				cout << "Account does not exist. Please try again." << endl;
				system("pause");
				return;
			}
		}
		else if (userWithdrawChoice == 2 && userDepositChoice == 1) { //Saving to checking
			if (SavingAccountList[ID_Withdraw].getSavingExists() == true && CheckingAccountList[ID_Deposit].getCheckingExists() == true) {

				//Check if there is enough money in the withdrawal account
				if (transferAmount <= SavingAccountList[ID_Withdraw].getBalance()) {
					SavingAccountList[ID_Withdraw].WithdrawMoney(transferAmount);
					CheckingAccountList[ID_Deposit].depositMoney(transferAmount);
					validTransfer = true;
				}
				else {
					validTransfer = false;
				}
			}
			else {
				cout << "Account does not exist. Please try again." << endl;
				system("pause");
				return;
			}
		}
		else { //Saving to Saving
			if (SavingAccountList[ID_Withdraw].getSavingExists() == true && SavingAccountList[ID_Deposit].getSavingExists() == true) {

				//Check if there is enough money in the withdrawal account
				if (transferAmount <= SavingAccountList[ID_Withdraw].getBalance()) {
					SavingAccountList[ID_Withdraw].WithdrawMoney(transferAmount);
					SavingAccountList[ID_Deposit].depositMoney(transferAmount);
					validTransfer = true;
				}
				else {
					validTransfer = false;
				}
			}
			else {
				cout << "Account does not exist. Please try again." << endl;
				system("pause");
				return;
			}
		}
	} while (!validTransfer);
	cout << "Transfer completed." << endl;
	cout << "Exiting to Main Menu..." << endl;
	system("pause");
}
void transferBetweenCustomerAccounts(const int SIZE, Customer customerList[], Checking CheckingAccountList[], SavingAccount SavingAccountList[]) {
	system("cls");
	cout << "---------Transfer Between Customer's Accounts--------" << endl;

	//Variable to store the ID of the customer account we are using
	int ID;
	//if the user does not determine what customer to use, exit the seletection. Otherwise continue.
	if (!determineCustomer(SIZE, ID, customerList)) {
		cout << "Exiting to Main Menu..." << endl;
		system("pause");
		return;
	}
	if (CheckingAccountList[ID].getCheckingExists() == false || SavingAccountList[ID].getSavingExists() == false) {
		cout << "User does not have both a checkings and savings. Please try again." << endl;
		system("pause");
		return;
	}

	int userWithdrawChoice;
	cout << "What account do you want to withdraw from?:" << endl;
	cout << "1) Checkings account. " << endl;
	cout << "2) Savings account. " << endl;
	cout << "3) Cancel." << endl;
	menuSelection(userWithdrawChoice, 3);
	double transferAmount = 0.0;
	bool validTransfer = false;
	do {
		if (userWithdrawChoice == 3) {
			//User selected cancel.
			return;
		}
		else {
			cout << "-----------------------" << endl;
			cout << "Please enter the amount you wish to transfer: $";
			transferAmount = validateCurrency();
			if (userWithdrawChoice == 1) {
				//From Checkings into Savings.
				if (transferAmount <= (CheckingAccountList[ID].getBalance() + CheckingAccountList[ID].getOverDraftLimit())) {
					validTransfer = true;
					CheckingAccountList[ID].WithdrawMoney(transferAmount);
					SavingAccountList[ID].depositMoney(transferAmount);
					cout << "New Checking Account Balance: $" << CheckingAccountList[ID].getBalance() << endl;
					cout << "New Saving Account Balance: $" << SavingAccountList[ID].getBalance() << endl;
				}
				else {
					validTransfer = false;
				}
			}
			else{
				//From Savings into Savings.
				if (transferAmount <= SavingAccountList[ID].getBalance()) {
					validTransfer = true;
					SavingAccountList[ID].WithdrawMoney(transferAmount);
					CheckingAccountList[ID].depositMoney(transferAmount);
					cout << "New Checking Account Balance: $" << CheckingAccountList[ID].getBalance() << endl;
					cout << "New Saving Account Balance: $" << SavingAccountList[ID].getBalance() << endl;
				}
				else {
					validTransfer = false;
				}
			}
		}
	} while (!validTransfer);
	cout << "Transfer completed." << endl;
	cout << "Exiting to Main Menu..." << endl;
	system("pause");
}
void transferToOrFromCustomer(const int SIZE, Customer customerList[], Checking CheckingAccountList[], SavingAccount SavingAccountList[]) {
	system("cls");
	cout << "---------Deposit or Withdraw from Account--------" << endl;

	//Variable to store the ID of the customer account we are using
	int ID;
	//if the user does not determine what customer to use, exit the seletection. Otherwise continue.
	if (!determineCustomer(SIZE, ID, customerList)) {
		cout << "Exiting to Main Menu..." << endl;
		system("pause");
		return;
	}
	//What account is being used
	int userAccountChoice;
	cout << "What account do you want to deposit or withdraw from?:" << endl;
	cout << "1) Checkings account. " << endl;
	cout << "2) Savings account. " << endl;
	cout << "3) Cancel." << endl;
	menuSelection(userAccountChoice, 3);
	if (userAccountChoice == 3) {
		//User selected cancel.
		return;
	}
	else if (userAccountChoice == 2) {
		if (SavingAccountList[ID].getSavingExists() == false){
			cout << "User does not have a savings account. Please try again." << endl;
			system("pause");
			return;
		}
	}
	else {
		if (CheckingAccountList[ID].getCheckingExists() == false) {
			cout << "User does not have a checking account. Please try again." << endl;
			system("pause");
			return;
		}
	}

	//Depositing or Withdrawing money
	int userActionChoice;
	cout << "Do you want to deposit or withdraw money?:" << endl;
	cout << "1) Deposit. " << endl;
	cout << "2) Withdraw. " << endl;
	cout << "3) Cancel." << endl;
	menuSelection(userActionChoice, 3);
	if (userActionChoice == 3) {
		//User selected cancel.
		return;
	}
	
	double transferAmount = 0.0;
	bool validTransfer = false;

	do {
		cout << "-----------------------" << endl;
		cout << "Please enter the amount you wish to transfer: $";
		transferAmount = validateCurrency();

		if (userActionChoice == 1) { //Depositing money
			if (userAccountChoice == 1) { // Checkings account
				CheckingAccountList[ID].depositMoney(transferAmount);
				cout << "New Balance: $" << CheckingAccountList[ID].getBalance() << endl;
				validTransfer = true;
			}
			else { //Savings Account
				SavingAccountList[ID].depositMoney(transferAmount);
				cout << "New Balance: $" << SavingAccountList[ID].getBalance() << endl;
				validTransfer = true;
			}
		}
		else { //Withdrawing money
			if (userAccountChoice == 1) { // Checkings account
				if (transferAmount <= (CheckingAccountList[ID].getBalance() + CheckingAccountList[ID].getOverDraftLimit())) {
					validTransfer = true;
					CheckingAccountList[ID].WithdrawMoney(transferAmount);
					cout << "New Balance: $" << CheckingAccountList[ID].getBalance() << endl;
				}
				else {
					cout << "Insufficient Funds: Please try again." << endl;
					validTransfer = false;
				}
			}
			else { //Savings Account
				if (transferAmount <= SavingAccountList[ID].getBalance()) {
					validTransfer = true;
					SavingAccountList[ID].WithdrawMoney(transferAmount);
					cout << "New Balance: $" << SavingAccountList[ID].getBalance() << endl;
				}
				else {
					cout << "Insufficient Funds: Please try again." << endl;
					validTransfer = false;
				}
			}
		}
	} while (!validTransfer);

	cout << "Transfer completed." << endl;
	cout << "Exiting to Main Menu..." << endl;
	system("pause");
}
void SaveCheckingToFile(Checking _account, Customer _customer)
{
	ofstream outFile("c:\\TEMP\\CheckingAccount.txt", ios::out);
	outFile << "First Name:       " << _customer.getFname() << endl;
	outFile << "Last Name:        " << _customer.getLname() << endl;
	outFile << "Address:          " << _customer.getAdress() << endl;
	outFile << "Phone Number:     " << _customer.getPhonenum() << endl;
	outFile << "Email:            " << _customer.getEmail() << endl;
	outFile << "ID:               " << _account.getID() << endl;
	outFile << "Balance:          " << _account.getBalance() << endl;
	outFile << "Withdraw Counter: " << _account.getWithDrawelCounter() << endl;
	outFile << "Deposits Counter: " << _account.getDepositsCounter() << endl;
	outFile << "Balance:          " << _account.getBalance() << endl;
	outFile << "Over Draft Limit: " << _account.getOverDraftLimit() << endl;
	outFile.close();
	cout << "----------Sucessfully Saved to File----------" << endl;
}

void SaveSavingToFile(SavingAccount _account, Customer _customer)
{
	ofstream outFile("c:\\TEMP\\SavingAccount.txt", ios::out);
	outFile << "First Name:       " << _customer.getFname() << endl;
	outFile << "Last Name:        " << _customer.getLname() << endl;
	outFile << "Address:          " << _customer.getAdress() << endl;
	outFile << "Phone Number:     " << _customer.getPhonenum() << endl;
	outFile << "Email:            " << _customer.getEmail() << endl;
	outFile << "ID:               " << _account.getID() << endl;
	outFile << "Balance:          " << _account.getBalance() << endl;
	outFile << "Withdraw Counter: " << _account.getWithDrawelCounter() << endl;
	outFile << "Deposits Counter: " << _account.getDepositsCounter() << endl;
	outFile << "Interest Rate:    " << _account.getInterestRate() << endl;
	outFile.close();
	cout << "----------Sucessfully Saved to File----------" << endl;
}
void saveDataToFile(const int SIZE, Customer customerList[], Checking CheckingAccountList[], SavingAccount SavingAccountList[]) {
	//9) Save data to a file
	int whichFile = 0;
	int customerID = 0;
	system("cls");
	cout << "---------- Saving to Files ----------" << endl;
	cout << "1) Save Savings to File" << endl;
	cout << "2) Save Checkings to File" << endl;
	cout << "3) Save both to File" << endl;
	menuSelection(whichFile, 3);
	determineCustomer(SIZE, customerID, customerList);
	if (whichFile == 1)
	{
		SaveSavingToFile(SavingAccountList[customerID], customerList[customerID]);
		system("pause");
	}
	else if (whichFile == 2)
	{
		SaveCheckingToFile(CheckingAccountList[customerID], customerList[customerID]);
		system("pause");
	}
	else if (whichFile == 3)
	{
		SaveCheckingToFile(CheckingAccountList[customerID], customerList[customerID]);
		SaveSavingToFile(SavingAccountList[customerID], customerList[customerID]);
		system("pause");
	}
}
else if (whichFile == 3){
	SaveCheckingToFile(CheckingAccountList[customerID], customerList[customerID]);
	SaveSavingToFile(SavingAccountList[customerID], customerList[customerID]);
	system("pause");
	}
}
