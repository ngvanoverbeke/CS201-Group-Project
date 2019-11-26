//This cpp file holds the functions to encrpyt and decrypt the passwords and addresses when necessary

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
	byte iv[AES::BLOCKSIZE] = "CA8A8878F14RFB7";
	string plain = toEncrypt;
	string key = masterPass;
	string fluff;

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