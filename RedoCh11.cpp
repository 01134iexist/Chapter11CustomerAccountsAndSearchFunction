
#include <stdlib.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct Date {
	int month;
	int day;
	int year;
};

struct CustomerAccount {
	string name;
	string address;
	string city;
	string state;
	int zip;
	int phoneNumber;
	double accountBalance;
	Date date;

};

void searchCustomers(string, CustomerAccount[10]);

int main()
{
	int index = 0;
	CustomerAccount customerList[9];
	int choice;
	char yesOrNo;
	string userReply1, userReply2, userReply3, userReply4;

	do
	{
		cout << "\nThis program will allow you to manipulate data associated with customer accounts.\n";
		cout << "Please select an option from the list below. \n";
		cout << endl
			<< " 1 - Add Information\n"
			<< " 2 - Change Information\n"
			<< " 3 - Search Feature\n"
			<< " 4 - Exit\n"
			<< " Enter your choice and press return: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "\nEnter the information for the 10 customers.\n";
			for (int count = 0; count < 10; count++) {
				cout << "Employee name : ";

				cin >> customerList[count].name;
				cout << "Address : ";
				cin >> customerList[count].address;
				cout << "City : ";
				cin >> customerList[count].city;
				cout << "State : ";
				cin >> customerList[count].state;

				cout << "Zip : ";
				std::cin >> customerList[count].zip;
				while (std::cin.fail()) {
					if (customerList[count].zip < 0) {
						std::cout << "Error. Enter correct data : " << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> customerList[count].zip;
					}
					std::cout << "Error. Enter correct data : " << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
					std::cin >> customerList[count].zip;
				}




				cout << "Phone Number : ";
				cin >> customerList[count].phoneNumber;
				while (std::cin.fail()) {
					if (customerList[count].phoneNumber< 0) {
						std::cout << "Error. Enter correct data : " << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> customerList[count].phoneNumber;
					}
					std::cout << "Error. Enter correct data : " << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
					std::cin >> customerList[count].phoneNumber;
				}


				cout << "Account Balance : ";
				cin >> customerList[count].accountBalance;
				while (std::cin.fail()) {
					if (customerList[count].accountBalance < 0) {
						std::cout << "Error. Enter correct data : " << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> customerList[count].accountBalance;
					}
					std::cout << "Error. Enter correct data : " << std::endl;
					std::cin.clear();
					std::cin.ignore(256, '\n');
					std::cin >> customerList[count].accountBalance;
				}


				cout << "\nNow enter the date of the last payment : ";
				cout << "\nMonth (up to 2 digits) : ";
				cin >> customerList[count].date.month;
				cout << "Day : ";
				cin >> customerList[count].date.day;
				cout << "Year : ";
				cin >> customerList[count].date.year;
				cout << "Do you want to continue entering information for customers? Enter 'y' for yes or 'n' for no.";
				cin >> yesOrNo;
				if (yesOrNo == 'y') {
					continue;
				}
				else { break; }
			}
			break;
		case 2:
			cout << "Whose information do you wish to change?";

			cin >> userReply1;
			for (int count = 0; count < 10; count++) {
				if (customerList[count].name == userReply1) {
					cout << "What category did you want to change?";
					cin >> userReply2;
					cout << "Enter the new inforamtion here: ";
					cin >> userReply3;
					if (userReply2 == "name") {
						customerList[count].name = userReply3;
					}
					else if (userReply2 == "address") {
						customerList[count].address = userReply3;
					}
					else if (userReply2 == "city") {
						customerList[count].city = userReply3;
					}
					else if (userReply2 == "state") {
						customerList[count].state = userReply3;
					}
					else if (userReply2 == "zip") {
						customerList[count].zip = std::stoi(userReply3);
					}
					else if (userReply2 == "phone number") {
						customerList[count].phoneNumber = std::stoi(userReply3);
					}
					else {
						cout << "Your response in invalid. Please try again.";
						cin >> userReply2;
					}


				}
			}
			break;
		case 3:
			cout << "\nYou may search for one particular record, or you may have all records displayed simultaneously." << endl;
			cout << "Select 1 to search for one record." << endl;
			cout << "Select 2 to display all records." << endl;
			cin >> userReply3;
			if (userReply3 == "1") {
				cout << "\nWho are you searching for? ";
				cin >> userReply4;
				searchCustomers(userReply4, customerList);
			}
			else {
				cout << "\nDisplaying All Customer Information : \n";
				if (customerList[0].name == "")
				{
					cout << "There are no records to display." << endl;
					break;
				}
				for (int count = 0; count < 10; count++) {
					if (customerList[count].name != "") {
						cout << "\nCustomer Name: " << customerList[count].name;
						cout << "\nAddress : " << customerList[count].address;
						cout << "\nCity : " << customerList[count].city;
						cout << "\nState : " << customerList[count].state;
						cout << "\nZip : " << customerList[count].zip;
						cout << "\nPhone Number : " << customerList[count].phoneNumber;
						cout << "\nAccount Balance: $" << customerList[count].accountBalance;
						cout << "\nDate of last payment : " << customerList[count].date.month << " / " << customerList[count].date.day << " / " << customerList[count].date.year << "\n";
					}
					else { break; }
				}
			}

			break;
		case 4:
			cout << "End of program.";
			break;

		default:
			cout << "Not a Valid Choice. \n"
				<< "Choose again.\n";
			break;
		}

	} while (choice != 4);
	return 0;
}

//search feature
void searchCustomers(string reply, CustomerAccount customerList[10]) {
	string customerName = reply;
	for (int count = 0; count < 10; count++) {
		if (customerList[count].name == customerName && customerList[count].name != "") {
			cout << "\nCustomer Name: " << customerList[count].name;
			cout << "\nAddress : " << customerList[count].address;
			cout << "\nCity : " << customerList[count].city;
			cout << "\nState : " << customerList[count].state;
			cout << "\nZip : " << customerList[count].zip;
			cout << "\nPhone Number : " << customerList[count].phoneNumber;
			cout << "\nAccount Balance: $" << customerList[count].accountBalance;
			cout << "\nDate of last payment : " << customerList[count].date.month << " / " << customerList[count].date.day << " / " << customerList[count].date.year << "\n";
			break;
		}
		else {
			cout << "\nNo entry exists for this name." << endl;
			cout << "Use the Add Information feature of the main menu to add information to the database." << endl;
			cout << "You will be returned to the main menu now." << endl;
			break;
		}
	}

}
