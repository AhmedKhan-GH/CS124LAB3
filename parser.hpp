#ifndef PARSER_HPP
#define PARSER_HPP
#include <fstream>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
class parser
{
public:
	parser(std::string file_name);
	static bool does_this_file_exist(std::string file_name);
	std::vector<std::pair<char, std::string>> parse_cipher();
	std::vector<std::string> parse_encryption();
	std::vector<std::string> parse_plaintext();
	static bool is_this_file_encrypted(std::string file_name);
private:
	std::string file_name;
};
#endif //PARSER_HPP
