//this program takes a given date from the user and displays that date in a number of different formats. 
//written by Brent Kinney 4/30/19

#include <iostream>
#include <string>
using namespace std;

string validDate(int month, int day, int year)
{
	string errorMessage;

	if ((year < 999) || (year > 10000))
	{
		errorMessage = "Invalid year \n";
	}
	else if ((month == 1 || month == 3 || month == 5 || month == 7 ||
		month == 8 || month == 10 || month == 12) && (day > 31 || day < 1))
	{
		errorMessage = "Invalid day. Must be 1-31 \n";
	}
	else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30 || day < 1))
	{
		errorMessage = "Invalid day. Must be 1-30 \n";
	}
	else if ((month < 1) || (month > 12))
	{
		errorMessage = "Invalid month \n";
	}
	else if ((month == 2) && (year % 4 != 0) && (day > 28 || day < 1))
	{
		errorMessage = "Invalid day. Must be 1-28 \n";
	}
	else if ((month == 2) && (year % 4 == 0) && (day > 29 || day < 1))
	{
		errorMessage = "Invalid day. Must be 1-29 \n";
	}

	return errorMessage;
}

string usFormat(int day, int month, int year)
{
	cout << month << "/" << day << "/" << year << "(US)" << endl;
}

void usExpandedFormat(int day, string month, int year)
{
	cout << month << " " << day << "," << year << " (US Expanded)" << endl;
}

void usMilitaryFormat(int day, string month, int year)
{
	cout << day << " " << month << " " << year << " (US Military)" << endl;
}

void internationalFormat(int day, int month, int year)
{
	cout << year << "-" << month << "-" << day << " (International)" << endl;
}

struct Date {
	int day;
	int month;
	int year;

	//Default constructor
	Date()
	{
		month = 0;
		day = 0;
		year = 0;
	}

	//constructor
	Date(int monthGiven, int dayGiven, int yearGiven)
	{
		month = monthGiven;
		day = dayGiven;
		year = yearGiven;
	}
};

int main()
{
	string dateGiven;
	char choice = 'y';
	char fill = '/';
	Date date;

	do
	{
		//ask for date from users
		cout << "Enter a date (mm/dd/yyyy): ";
		cin >> dateGiven;

		date.month = stoi(dateGiven.substr(0, 2));
		date.day = stoi(dateGiven.substr(3, 2));
		date.year = stoi(dateGiven.substr(6));

		if ((date.year < 999) || (date.year > 10000))
		{
			cout << "Invalid year \n";
		}
		else if ((date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 ||
			date.month == 8 || date.month == 10 || date.month == 12) && (date.day > 31 || date.day < 1))
		{
			cout << "Invalid day. Must be 1-31 \n";
		}
		else if ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && (date.day > 30 || date.day < 1))
		{
			cout << "Invalid day. Must be 1-30 \n";
		}
		else if ((date.month < 1) || (date.month > 12))
		{
			cout << "Invalid month \n";
		}
		else if ((date.month == 2) && (date.year % 4 != 0) && (date.day > 28 || date.day < 1))
		{
			cout << "Invalid day. Must be 1-28 \n";
		}
		else if ((date.month == 2) && (date.year % 4 == 0) && (date.day > 29 || date.day < 1))
		{
			cout << "Invalid day. Must be 1-29 \n";
		}
		else
		{
			cout << date.month << "/" << date.day << "/" << date.year << "(US)" << endl;
			cout << date.month << " " << date.day << "," << date.year << " (US Expanded)" << endl;
			cout << date.day << " " << date.month << " " << date.year << " (US Military)" << endl;
			cout << date.year << "-" << date.month << "-" << date.day << " (International)" << endl;
		}






		//see if the user wants to continue and continue if desired
		cout << "Would you like to check another time? (Y/N): ";
		cin >> choice;
		cout << endl << endl;

	} while (choice == 'y' || choice == 'Y');

	//display author of the program
	cout << "Programmed by Brent Kinney" << endl;

	cout << "Press [Enter] key to end..."; //prompt lets user know
	cin.ignore(256, '\n');
	cin.get();

	return 0;
}