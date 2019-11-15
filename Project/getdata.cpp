//This cpp file is used to gather data from the file used
//prototype will not include file download

#include "Main.hpp"

void storepassword(const string& password, const string& adress, vector<pair<string,string>>& data)
{
	pair<string, string> temp;
	temp.first = adress;
	temp.second = password;
	data.push_back(temp);
}
