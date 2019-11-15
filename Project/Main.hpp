//This hpp file wil be used to link everything

#ifndef FILE_MAIN_HPP
#define FILE_MAIN_HPP

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
using std::getline;
#include <vector>
using std::vector;
using std::pair;
#include <fstream>
using std::ofstream;

void storepassword(const string & password, const string & adress, vector<pair<string, string>>& data);

void filegrab(vector<pair<string, string>>& data, string& mainpass);









#endif
