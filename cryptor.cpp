#include "cryptor.hpp"

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
