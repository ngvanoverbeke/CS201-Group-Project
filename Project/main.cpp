//This is where everything is referenced and will include the visual part of the project

#include "Main.hpp"

int main()
{
	string password;
	string address;
	int x = 1;

	while (x > 0)
	{
		cout << "Hello would you like to store a password(1), Look for a password(2), or exit(0)";
		cin >> x;

		if (x == 0)
		{
			return 0;
		}
		else if (x == 1)
		{
			cout << "Enter a password:";
			getline(cin, password);
			cout << "Enter an address:";
			getline(cin, address);
			//storepassword(address, password);
		}
		else if (x == 2)
		{
			cout << "What address do you want a password for:";
			getline(cin, address);
			//searchpassword(address);
		}
		else
		{
			cout << "Nonvalid number" << endl;
		}
	}
}