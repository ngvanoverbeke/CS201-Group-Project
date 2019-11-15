//This is where everything is referenced and will include the visual part of the project

#include "Main.hpp"

int main()
{
	//file grab
	string password;
	string address;
	vector < pair<string, string>> data;
	int x = 1;

	while (x > 0)
	{
		cout << "Hello would you like to store a password(1), Look for a password(2), or exit(0): ";
		cin >> x;

		if (x == 0)
		{
			return 0;
		}
		else if (x == 1)
		{
			cout << "Enter a password: ";
			cin >> password;
			cout << "Enter an address: ";
			cin >> address;
			//add double check
			storepassword(address, password, data);
		}
		else if (x == 2)
		{
			cout << "What address do you want a password for: ";
			cin >> address;
			//searchpassword(address, data);
		}
		else
		{
			cout << "Nonvalid number" << endl;
		}
		cout << endl;
		
	}
}