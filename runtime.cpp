#include "runtime.hpp"

//this function takes a string input
//verifying that it is not empty else
//prompting the user to enter something again
std::string Runtime::string_input()
{
	std::string input;
	bool verified = false;
	do
	{
		std::getline(std::cin, input, '\n');
		if(input.length() == 0)
		{
			std::cout << std::endl << "blank, try again: ";
		}
		else
		{
			verified = true;
		}
	}while(!verified);
	return input;
}

//COMPLETE
//this function uses string_input to return a bool based on user input
bool Runtime::boolean_question()
{
	bool verified = false; //determines if question loops based on invalid answer
	bool answer; //value of the answer input by the user
	
	std::string input; //single variable needed to store input even over repeated iterations of prompt
	std::cout << "[y/n]: "; //prompt for user for valid characters, 
	
	do{
		input = string_input(); //getting string from validated input function
		if(input == "y") //checking for yes and setting bools
		{
			verified = true;
			answer = true;
		}
		else if(input == "n") //checking for no and setting bools
		{
			verified = true;
			answer = false;
		}
		else //informing and reprompting user in case of invalid input
		{
			std::cout << std::endl << "invalid, try again: ";
			verified = false;
		}
	}while(!verified); //prompt loop until a desired answer has been given
	
	return answer;
}


Runtime::Runtime() : mainloop_state(false)
{

}

void Runtime::start_message()
{
	std::cout <<
	std::endl << "Greeting user, welcome to the Enigma Machine." <<
	std::endl << "This program allows you to provide a cypher" <<
	std::endl << "and provide plain-text files for encryption" <<
	std::endl << "or an encrypted file for decryption." <<
	std::endl;
}

void Runtime::proceed_prompt()
{

	std::cout <<
	std::endl << "Would you like to proceed[y] or exit[n]." <<
	std::endl;
}

void Runtime::restart_prompt()
{
	std::cout <<
	std::endl << "You have reached the end of the program." <<
	std::endl << 
	std::endl << "Would you like to restart[y] or exit[n]" <<
	std::endl;
}

void Runtime::end_message()
{
	std::cout << 
	std::endl << "Thank you for using the Enigma Machine!" <<
	std::endl;
}

void Runtime::start()

{
	start_message();
	proceed_prompt();
	mainloop_state = boolean_question();	
	
	while(mainloop_state)
	{
		restart_prompt();
		mainloop_state = boolean_question();
	}
	end_message();
}

