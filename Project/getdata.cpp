//This cpp file is used to gather data from the file used
//prototype will not include file download

#include "Main.hpp"

void storepassword(const string& password, const string& address, vector<pair<string,string>>& data)
{
	pair<string, string> temp;
	temp.first = password;
	temp.second = address;
	data.push_back(temp);
}

/*void filegrab(vector<pair<string, string>>& data, string & mainpass)
{
	ofstream myfile;
	myfile.open("PasswordsDontOpen.txt");
	
	myfile.close();
}
*/

void filesend(vector<pair<string, string>>& data, string& mainpass)
{
	ofstream myfile;
	myfile.open("PasswordsDontOpen.txt");
	myfile << mainpass << "\n";
	for (auto i : data)
	{
		myfile << i.first << "," << i.second << "\n";
	}
	myfile.close();
}

