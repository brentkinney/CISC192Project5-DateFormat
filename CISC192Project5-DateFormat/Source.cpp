//this program takes a given date from the user and displays that date in a number of different formats. 
//written by Brent Kinney 4/30/19

#include <iostream>
#include <string>
using namespace std;

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
	Date date;

	do
	{
		//ask for date from users
		cout << "Enter a date (mm/dd/yyyy): ";
		cin >> dateGiven;
		cout << "\n" << endl;

		if (dateGiven.size() != 10 || dateGiven[2] != '/' || dateGiven[5] != '/') {
			cout << "Invalid date format.  Please use (mm/dd/yyyy)" << endl;
		}
		else
		{
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
				cout << "Invalid day. Not leap year, must be 1-28 \n";
			}
			else if ((date.month == 2) && (date.year % 4 == 0) && (date.day > 29 || date.day < 1))
			{
				cout << "Invalid day. Must be 1-29 \n";
			}
			else
			{
				string month;
				if (date.month == 1)
					month = "January";
				else if (date.month == 2)
					month = "February";
				else if (date.month == 3)
					month = "March";
				else if (date.month == 4)
					month = "April";
				else if (date.month == 5)
					month = "May";
				else if (date.month == 6)
					month = "June";
				else if (date.month == 7)
					month = "July";
				else if (date.month == 8)
					month = "August";
				else if (date.month == 9)
					month = "September";
				else if (date.month == 10)
					month = "October";
				else if (date.month == 11)
					month = "November";
				else
					month = "December";

				cout << date.month << "/" << date.day << "/" << date.year << " (US)" << endl;
				cout << month << " " << date.day << "," << date.year << " (US Expanded)" << endl;
				cout << date.day << " " << month << " " << date.year << " (US Military)" << endl;
				cout << date.year << "-" << date.month << "-" << date.day << " (International)" << endl;
			}
		}
		






		//see if the user wants to continue and continue if desired
		cout << "\nWould you like to check another time? (Y/N): ";
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