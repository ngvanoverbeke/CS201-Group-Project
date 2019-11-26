//This cpp fil ewill be used to decode the data wanted, and encode the data given
// for{
// vector<pair<string,string>> data
// data[i].first
// data[i].second
// }


#include "Main.hpp"
string decrypt(string& toDecrypt, string& masterPass){
    string key = masterPass;
    string cipher = toDecrypt;
    byte iv[AES::BLOCKSIZE] = "CA8A8878F14RFB7";
    string recovered;
	
    CBC_Mode< AES >::Decryption d;
	    d.SetKeyWithIV((byte *) key.c_str(), sizeof(key), iv);

		// The StreamTransformationFilter removes
		//  padding as required.
		StringSource s(cipher, true, 
           new StreamTransformationFilter(d,
			new StringSink(recovered)
			) // StreamTransformationFilter
		); // StringSource
    return recovered;
}

string encrypt(string& toEncrypt, string& masterPass){
	byte iv[16] = "CA8A8878F14RFB7";
	string plain = toEncrypt;
	string key = "passwordis16char";
	string fluff;
	
	byte keyByte[16];
	
	//prng.GenerateBlock(key, sizeof(key));

	CBC_Mode< AES >::Encryption e;
		e.SetKeyWithIV((byte *) key.c_str(), sizeof(key), iv);

		// The StreamTransformationFilter removes
		//  padding as required.
		StringSource s(plain, true, 
			new StreamTransformationFilter(e,
				new StringSink(fluff)
			) // StreamTransformationFilter
		); // StringSource
	return fluff;

}
string encryptALT(string& toEncrypt, string& masterPass){

    AutoSeededRandomPool prng;

	byte key[AES::DEFAULT_KEYLENGTH];
	prng.GenerateBlock(key, sizeof(key));

	//byte iv[AES::BLOCKSIZE];
	//prng.GenerateBlock(iv, sizeof(iv));

    byte iv[16] = "CA8A8878F14RFB7";

	string plain = toEncrypt;
	string cipher, encoded, recovered;

	/*********************************\
	\*********************************/

	// Pretty print key
	encoded.clear();
	encoded = masterPass;
	//cout << "key: " << encoded << endl;

	// Pretty print iv
	encoded.clear();
	StringSource(iv, sizeof(iv), true,
		new HexEncoder(
			new StringSink(encoded)
		) // HexEncoder
	); // StringSource
	//cout << "iv: " << encoded << endl;

	/*********************************\
	\*********************************/

	try
	{
		//cout << "plain text: " << plain << endl;

		CBC_Mode< AES >::Encryption e;
		e.SetKey(key, sizeof(key));

		// The StreamTransformationFilter removes
		//  padding as required.
		StringSource s(plain, true, 
			new StreamTransformationFilter(e,
				new StringSink(cipher)
			) // StreamTransformationFilter
		); // StringSource

#if 0
		StreamTransformationFilter filter(e);
		filter.Put((const byte*)plain.data(), plain.size());
		filter.MessageEnd();

		const size_t ret = filter.MaxRetrievable();
		cipher.resize(ret);
		filter.Get((byte*)cipher.data(), cipher.size());
#endif
	}
	catch(const CryptoPP::Exception& e)
	{
		cerr << e.what() << endl;
		exit(1);
	}

	/*********************************\
	\*********************************/

	// Pretty print
	encoded.clear();
	StringSource(cipher, true,
		new HexEncoder(
			new StringSink(encoded)
		) // HexEncoder
	); // StringSource
	//cout << "cipher text: " << encoded << endl;

	/*********************************\
	\*********************************/

	try
	{
		CBC_Mode< AES >::Decryption d;
		d.SetKeyWithIV(key, sizeof(key), iv);

		// The StreamTransformationFilter removes
		//  padding as required.
		StringSource s(cipher, true, 
			new StreamTransformationFilter(d,
				new StringSink(recovered)
			) // StreamTransformationFilter
		); // StringSource

#if 0
		StreamTransformationFilter filter(d);
		filter.Put((const byte*)cipher.data(), cipher.size());
		filter.MessageEnd();

		const size_t ret = filter.MaxRetrievable();
		recovered.resize(ret);
		filter.Get((byte*)recovered.data(), recovered.size());
#endif

		//cout << "recovered text: " << recovered << endl;
	}
	catch(const CryptoPP::Exception& e)
	{
		cerr << e.what() << endl;
		exit(1);
	}

	/*********************************\
	\*********************************/

	return encoded;
}

void printPassVector(){
vector<pair<string,string>> data;
    data[1].first = "root";
    data[1].second = "pass.com";
    data[2].first = "root";
    data[2].second = "pass2.com";
    
    string output = "";

    for (pair<string,string> pass: data)
    {   
        output += pass.first + " ";
        output += pass.second + "\n";
        std::cout << pass.first;
        std::cout << pass.second;
    }
    
}


