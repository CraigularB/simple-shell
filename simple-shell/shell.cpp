#include <iostream>
#include <string>
#include "utils.h"

const std::string& PROMPT = "$> ";
void get_input(std::ostream& out, std::istream& in, const std::string& prompt, std::string& cmd, std::string& args);

int main()
{
	std::string cmd("");
	std::string args("");
	get_input(std::cout, std::cin, PROMPT, cmd, args);
	//making this quitable by command for now
	while(cmd != "QUIT")
	{
		// will find a better way to do a large if-elif block later
		if (cmd == "echo")
		{
			echo(args);
		}
		else
		{
			std::cout << "Command '" << cmd << "' not recognized. Please input a valid command" << std::endl;
		}
		//update input
		get_input(std::cout, std::cin, PROMPT, cmd, args);
	}
	std::cout << "Thanks for using simple-shell" << std::endl;
	return 0;
}

void get_input(std::ostream& out, std::istream& in, const std::string& prompt, std::string& cmd, std::string& args)
{
	std::string input;
	out << PROMPT;
	std::getline(in, input);
	
	if (std::find(input.begin(), input.end(), ' ') != input.end())
	{
		cmd = input.substr(0, input.find(' '));
		args = input.substr(input.find(' ') + 1, input.length() - 1);
	}
	else
	{
		cmd = input;
		args = "";
	}
}