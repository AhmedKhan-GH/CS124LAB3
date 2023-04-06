#include "cryptor.hpp"

std::string cryptor::encrypt(std::vector<std::string>& tokens, Tree& cipher)
{
	std::string result;
	std::string coda;
	for(auto word : tokens)
	{
		for(char c : word)
		{
			coda.clear();
			coda = cipher.find(c);
			result += coda;
			result += " ";	
		}
		result += " ";
	}
	return result;
}

std::string cryptor::decrypt(std::vector<std::string>& tokens, hashmap& decipher)
{	
	std::string result;
	for(auto elem : tokens)
	{
		
		char c = decipher.find(elem);
		if(elem == " ")
		{
			result += " ";
		}
		else if(c != '\0')
		{
			result += c;
		}
		else 
		{
			result += '_'; 
		}
	}
	return result;
}
