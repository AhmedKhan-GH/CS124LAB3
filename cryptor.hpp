#ifndef CRYPTOR_HPP
#define CRYPTOR_HPP
#include "hashmap.hpp"
#include "tree.hpp"
#include <vector>
#include <iostream>
class cryptor
{
public:
	//TAKE DATA STRUCTURES BY REFERENCE
	static	std::string decrypt(std::vector<std::string>& tokens, hashmap& decipher); 
//	cryptor(std::vector<std:;string>> tokens, Tree cipher); 
	//void encrypt(cipher_file_name); //updates cipher as novel chars are disovered
	//void append_to_file(std::string file_name)	
private:
	std::string result;
	std::vector<std::string> tokens;

	hashmap decipher;
	Tree cipher;
};

#endif //CRYPTOR_HPP
