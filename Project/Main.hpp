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
using std::ifstream;
using std::getline;

void storepassword(const string & password, const string & address, vector<pair<string, string>>& data);

void filegrab(vector<pair<string, string>>& data, string& mainpass);

void filesend(vector<pair<string, string>>& data, string& mainpass);

void searchpassword(const string& address, const vector < pair<string, string>>& data);

//header info for encryption function
#include <cryptopp/osrng.h>
using CryptoPP::AutoSeededRandomPool;

using std::cerr;

#include <cstdlib>
using std::exit;

#include <cryptopp/cryptlib.h>
using CryptoPP::Exception;

#include <cryptopp/hex.h>
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include <cryptopp/filters.h>
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;

#include <cryptopp/aes.h>
using CryptoPP::AES;

#include <cryptopp/ccm.h>
using CryptoPP::CBC_Mode;

#include <assert.h>

string encrypt(string& toEncrypt);
#endif
