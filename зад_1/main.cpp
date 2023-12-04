#include <iostream>
#include "modAlphaCipher.cpp"
using namespace std;

void check(const string& Text, const string& key, const bool destructCipherText=false)
{ 
try {
	string cipherText;
	string decryptedText;
	modAlphaCipher cipher(key);
	cipherText = cipher.encrypt(Text); // зашифровывание
		if (destructCipherText) // надо "портить"?
			cipherText.front() = tolower(cipherText.front()); // "портим"
		decryptedText = cipher.decrypt(cipherText); // расшифровывание
	decryptedText = cipher.decrypt(cipherText);
	cout<<"key="<<key<<endl;
	cout<<Text<<endl;
	cout<<cipherText<<endl;
	
	cout<<decryptedText<<endl;
	} catch (const cipher_error & e) {
		cerr<<"Error: "<<e.what()<<endl;
	}
}
	
int main(int argc, char **argv)
{ 
	check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","Simple");
	check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","");
	check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","ABCD123");
	check("The Quick Brown Fox Jumps Over The Lazy Dog","SUPER");
	check("123","ABCD");
	check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","TOPSECRET",true);
return 0;
}
