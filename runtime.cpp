#include "runtime.hpp"


runtime::runtime() : mainloop_state(false), cypher_present_state(false), data_present_state(false)
{

}

std::string runtime::file_input()
{
	std::cout <<
	std::endl << "Enter file name: ";
	std::string file_name;
	bool verified = false;
	do 
	{
		file_name = string_input();
		if(parser::does_this_file_exist(file_name))
		{
			verified = true;
			std::cout << "file exists";
		}
		else
		{
			std::cout <<
			std::endl << "File nonexistent, try again: ";
		}
	}while(!verified);
	return file_name;
}

//this function takes a string input
//verifying that it is not empty else
//prompting the user to enter something again
std::string runtime::string_input()
{
	std::string input;
	bool verified = false;
	do
	{
		std::getline(std::cin, input, '\n');
		if(input.length() == 0)
		{
			std::cout <<
		 	std::endl << "blank, try again: ";
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
bool runtime::boolean_question()
{
	bool verified = false; //determines if question 
			       //loops based on invalid answer
	bool answer; //value of the answer input by the user
	
	std::string input; //single variable needed to store 
			   //input even over repeated iterations 
			   //of prompt
	std::cout << "[y/n]: "; //prompt for user for valid characters, 
	
	do{
		input = string_input(); //getting string from 
					//validated input function
		if(input == "y") //checking for yes and setting bools
		{
			verified = true;
			answer = true;
		}
		else if(input == "n") //checking for no and 
				      //setting bools
		{
			verified = true;
			answer = false;
		}
		else //informing and reprompting user 
		     //in case of invalid input
		{
			std::cout << std::endl << "invalid, try again: ";
			verified = false;
		}
	}while(!verified); //prompt loop until a desired answer 
			   //has been given
	
	return answer;
}



std::string runtime::file_question(std::string type)
{
	std::cout <<
	std::endl << "Please provide a " << type << " file" <<
	std::endl << "(with .txt extension), and ensure it" <<
	std::endl << "meets formatting requirements.";
	return file_input();
}

bool runtime::file_reprompt(std::string type)
{
	std::cout <<
	std::endl << "Would you like to select a different" <<
	std::endl << type << " file[y]  or continue using the" <<
	std::endl << "previous one[n]?";
	return boolean_question();
}

void runtime::start_message()
{
	std::cout <<
	std::endl << "Greeting user, welcome to the Enigma Machine." <<
	std::endl << "This program allows you to provide a cypher" <<
	std::endl << "and provide plain-text files for encryption" <<
	std::endl << "or an encrypted file for decryption." <<
	std::endl;
}

void runtime::proceed_prompt()
{

	std::cout <<
	std::endl << "Would you like to proceed[y] or exit[n]." <<
	std::endl;
}

void runtime::restart_prompt()
{
	std::cout <<
	std::endl << "You have reached the end of the program." <<
	std::endl << 
	std::endl << "Would you like to restart[y] or exit[n]" <<
	std::endl;
}

void runtime::end_message()
{
	std::cout << 
	std::endl << "Thank you for using the Enigma Machine!" <<
	std::endl;
}

void runtime::start()
{
	start_message();
	proceed_prompt();
	mainloop_state = boolean_question();	
	
	while(mainloop_state)
	{

		if(!cypher_present_state)
		{
			cypher_file_name = file_question("cypher");
			cypher_present_state = true;	
		}
		else if(file_reprompt("cypher"))
		{
			cypher_file_name = file_question("cypher");		
		}
/*
		if(!data_present_state)
		{
			data_file_name = file_question("data");
			data_present_state = true;	
		}
		else if(file_reprompt("data"))
		{
			data_file_name = file_question("data");
		}
*/
		parser cypher_file(cypher_file_name);
		std::vector<std::pair<char, std::string>> cypher_pairs = cypher_file.parse_cypher();

		hashmap map(cypher_pairs);
	       	map.print();	

		restart_prompt();
		mainloop_state = boolean_question();
	}
	end_message();
}
	
