#ifndef RUNTIME_HPP
#define RUNTIME_HPP
#include <iostream> 
class Runtime
{
public:
	std::string string_input();
	bool boolean_question();
	void start_message();
	void end_message();
	void proceed_prompt();
	void restart_prompt();
	Runtime();
	void start();
private:
	bool mainloop_state;
	bool file_present;
	bool cypher_present;
};

#endif //RUNTIME_HPP
