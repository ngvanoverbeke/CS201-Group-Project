//This is where everything is referenced and will include the visual part of the project

#include "Main.hpp"
int main()
{
	//file grab
	string userinput;
	string mainpass = "passwordis16char";
	string password = "";
	string address = "";
	vector < pair<string, string>> data;
	int x = 1;
	
	filegrab(data, mainpass);
	/*
	cout << mainpass << endl;
	for (auto i : data)
	{
		cout << i.first << ", " << i.second << endl;
	}
	*/
	cout << "Enter key: ";
	cin >> userinput;
	while (userinput != mainpass)
	{
		cout << "Incorrect, enter key: ";
		cin >> userinput;
	}

	while (x > 0)
	{
		cout << "Hello would you like to store a password(1), Look for a password(2), or exit(0): ";
		cin >> x;

		if (x == 0)
		{
			filesend(data, mainpass);
			return 0;
		}
		else if (x == 1)
		{
			userinput = "temp";
			cout << "Enter an address: ";
			cin >> address;
			cout << "Enter a password: ";
			cin >> password;
			cout << "Are you sure you want to store (Yes/No):\nWEBADDRESS: " << address << "\nPASSWORD: " << password << "\n";
			while (userinput != "no" && userinput != "No" && userinput != "yes" && userinput != "Yes")
			{
				cin >> userinput;
				if (userinput == "Yes"|| userinput == "yes")
				{
					storepassword(password, address, data);
					cout << "Adding password to database.\n";
				}
				else if (userinput == "no" || userinput == "No")
				{
					cout << "Taking you back to main page.\n";
				}
				else
				{
					cout << "Please enter yes or no.";
				}
			}
		}
		else if (x == 2)
		{
			cout << "What address do you want a password for: ";
			cin >> address;
			searchpassword(address, data);
		}
		else
		{
			cout << "Nonvalid number" << endl;
		}
		cout << endl;
		
	}
	
}