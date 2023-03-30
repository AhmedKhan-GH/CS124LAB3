#ifndef RUNTIME_HPP
#define RUNTIME_HPP
#include <iostream> 
class Runtime
{
public:
	std::string string_input();
	bool boolean_question();
	Runtime();
	void start();
private:
	bool mainloop_state;
};

#endif //RUNTIME_HPP
