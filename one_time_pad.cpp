#include <iostream>
#include <string>
#include <bitset>

#define LENGTH 50
#define BITLENGTH 8

std::string one_time_pad(char * message, char* key, int length)
{
	std::string myret = "";
	for (int i = 0; i < length; i++)
		myret.append(1,(char)(message[i] ^ key[i]));
	return myret;
}

std::string char2bin(char inchar)
{
    return (std::bitset<BITLENGTH>(inchar)).to_string();
}

int main()
{
	char message[LENGTH] = "HelloHelloHelloHelloHelloHelloHelloHelloHelloHelo";
	char key[LENGTH] =     "fhseruilfhjkfdlfjojerojkgdal;.sfkodlfkheufkhjdfjk";

	std::cout << "Message:   ";
	for(int i = 0; i < LENGTH; i++)
		std::cout << char2bin(message[i]);
	std::cout << std::endl;
	std::cout << "Key:       ";
	for(int i = 0; i < LENGTH; i++)
		std::cout << char2bin(key[i]);
	std::cout << std::endl;
	std::cout << "Encrypted: ";
	std::string mystring= one_time_pad(message,key,LENGTH);
	for(int i = 0; i < LENGTH; i++)
		std::cout << char2bin(mystring[i]);
	std::cout << std::endl;
}