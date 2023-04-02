#include "parser.hpp"

bool parser::does_this_file_exist(std::string file_name)
{
	std::ifstream input_filestream(file_name);
	return file.good();
}

parser::parser(std::string file_name) : file_name(file_name)
{

}

std::vector<std::pair<char, std::string>> parser::parse_cypher()
{

}

std::vector<<std::string> parse_encryption
{

}

std::vector<<std::string> parser::parse_plaintext()
{

}

bool parser::is_this_file_encrypted(std::string file_name)
{

}
