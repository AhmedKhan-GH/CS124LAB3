#include "parser.hpp"

bool parser::does_this_file_exist(std::string file_name)
{
	std::ifstream input_filestream(file_name);
	return input_filestream.good();
}

parser::parser(std::string file_name) : file_name(file_name)
{
}

std::vector<std::pair<char, std::string>> parser::parse_cipher()
{
	std::vector<std::pair<char, std::string>> elements;
	std::ifstream input_filestream(file_name);
	std::stringstream linesplitter;
	std::string line;
	char first;
	std::string second;
	while(std::getline(input_filestream, line))
	{
		linesplitter.clear();
		first = '\0';
		second.clear();

		linesplitter << line; 
		linesplitter >> first;
		linesplitter >> second;
		elements.push_back(std::make_pair(first, second));
	}
	return elements;	
}

std::vector<std::string> parser::parse_encryption()
{
	std::vector<std::string> elements;
	std::ifstream input_filestream(file_name);
	char current;
	char previous;
	std::string coda;
	while(input_filestream.get(current))
	{
		if(current == '0' || current == '1')
		{
			coda += current;
			previous = current;
		}
		else
		{
			if(!coda.empty())
			{
				elements.push_back(coda);
				coda.clear();
			}
			if(current == ' ' && previous == ' ')
			{
				elements.push_back(" ");
			}
			previous = current;
		}
	}
	if(!coda.empty())
	{
		elements.push_back(coda);
		std::cout << coda << std::endl;
	}
	return elements;
}

std::vector<std::string> parser::parse_plaintext()
{

	std::vector<std::string> elements;
	std::ifstream input_filestream(file_name);
	std::string word;
	while(input_filestream >> word)
	{
		elements.push_back(word);
	}
	return elements;
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

