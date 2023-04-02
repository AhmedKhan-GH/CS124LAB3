#ifndef RUNTIME_HPP
#define RUNTIME_HPP
#include <iostream>
#include "parser.hpp"
class runtime
{
public:
	std::string string_input();
	std::string file_input();
	bool boolean_question();
	void start_message();
	void end_message();
	void proceed_prompt();
	void restart_prompt();
	runtime();
	std::string file_question(std::string type);
	bool file_reprompt(std::string type);
	void start();
private:
	//domain state booleans
	bool mainloop_state;
	bool data_present_state;
	bool cypher_present_state;

	//file names
	std::string cypher_file_name;
	std::string data_file_name;
};

#endif //RUNTIME_HPP
