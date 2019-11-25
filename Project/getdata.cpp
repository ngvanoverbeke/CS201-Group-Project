#include "Main.hpp"

void storepassword(const string& password, const string& address, vector<pair<string,string>>& data)
{
	pair<string, string> temp;
	temp.first = password;
	temp.second = address;
	data.push_back(temp);
}

void filegrab(vector<pair<string, string>>& data, string & mainpass)
{
	int x = 0;
	ifstream myfile;
	myfile.open("PasswordsDontOpen.txt");
	string line;
	pair<string, string> temp;
	string password;
	string address;
	while(getline(myfile, line))
	{
		//decode line RIGHT HERE
		if (x == 0)
		{
			mainpass = line;
		}
		else if ((x % 2) != 0)
		{
			password = line;
			temp.first = password;
		}
		else if ((x % 2) == 0)
		{
			address = line;
			temp.second = address;
			data.push_back(temp);
		}
		x++;
	}
	myfile.close();
}

void filesend(vector<pair<string, string>>& data, string& mainpass)
{
	ofstream myfile;
	myfile.open("PasswordsDontOpen.txt");
	myfile << mainpass << "\n";
	for (auto i : data)
	{
		//i.second = encrypt(i.second, mainpass);
		//i.first = encrypt(i.first, mainpass);
		myfile << encrypt(i.first, mainpass) << "\n" << encrypt(i.second, mainpass) << "\n";
	}
	myfile.close();
}

void searchpassword(const string& address, const vector < pair<string, string>>& data)
{
	for (auto i : data)
	{
		if (address == i.second)
		{
			cout << "Your password for " << address << " is " << i.first << ".\n";
			return;
		}
	}
	cout << "The password was not found.\n";
	return;
}