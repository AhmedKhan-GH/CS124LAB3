#include "parser.hpp"

bool parser::does_this_file_exist(std::string file_name)
{
	std::ifstream input_filestream(file_name);
	return input_filestream.good();
}

parser::parser(std::string file_name) : file_name(file_name)
{

}

std::vector<std::pair<char, std::string>> parser::parse_cypher()
{

}

std::vector<std::string> parser::parse_encryption()
{

}

std::vector<std::string> parser::parse_plaintext()
{

}

bool parser::is_this_file_encrypted(std::string file_name)
{
	std::ifstream input_filestream(file_name); //open given file
	std::string file_contents //read contents of file into string
	(
		(std::istreambuf_iterator<char>(input_filestream)),
		std::istreambuf_iterator<char>()
	);
	return file_contents.find_first_not_of("01 \n")
		== std::string::npos; //return true if find_first
				      //not-of iterator reaches
				      //end of file	
}

