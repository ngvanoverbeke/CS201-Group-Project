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
		myfile << i.first << "\n" << i.second << "\n";
	}
	myfile.close();
}

