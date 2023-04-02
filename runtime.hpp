#ifndef RUNTIME_HPP
#define RUNTIME_HPP
#include <iostream>
#include "parser.hpp"
#include "hashmap.hpp"
class runtime
{
public:
	std::string string_input();
	std::string file_input();
	bool boolean_question();
	bool encrypted_question();
	bool plaintext_question();
	void start_message();
	void end_message();
	bool proceed_question();
	bool restart_question();
	runtime();
	std::string file_question(std::string type);
	bool file_reprompt(std::string type);
	void start();
private:
	//domain state booleans
	bool mainloop_state;
	bool data_present_state;
	bool cipher_present_state;
	bool file_save_state;
	bool encrypted_state;

	std::vector<std::string> tokens;
	//file names
	std::string cipher_file_name;
	std::string data_file_name;
};

#endif //RUNTIME_HPP
