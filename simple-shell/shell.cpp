#include <iostream>
#include <string>

const std::string PROMPT = "$> ";

int main()
{
	std::string input;
	std::cout << PROMPT;
	std::getline(std::cin, input);
	std::cout << input << std::endl;
	//making this quitable by command for now
	while(input != "QUIT")
	{
		std::cout << PROMPT;
		std::getline(std::cin, input);
		std::cout << input << std::endl;
	}
	std::cout << "Thanks for using simple-shell" << std::endl;
	return 0;
}