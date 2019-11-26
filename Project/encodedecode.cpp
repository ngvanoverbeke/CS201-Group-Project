//This cpp fil ewill be used to decode the data wanted, and encode the data given

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
	string key = masterPass;
	string fluff;
	
	byte keyByte[16];

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