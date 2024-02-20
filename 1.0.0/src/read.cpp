#include "../lib/read.hpp"

void ReadLoop::intro()
{
	Print("Welcome to the Calculator-inator! You are currently in interactive mode.\n");
	Print("Type \"help\" for a list of commands. Type \"intro\" to see this text again.\n");
	Print("Copyright 2023, anson. See LICENSE for related details.\n");
	return;
}

void ReadLoop::help()
{
	Print("If you want to calculate math expressions, just type them out!\n");
	Print("For instance, if you want to calculate the square of two plus three, type \"2^2 + 3\".\n\n");
	Print("Listed comments are:\n");

	auto f = [](auto &one, auto &two) { return std::make_pair(one, two); };
	for(auto &p : { f("help", "displays this info"),
			f("intro", "displays the intro"),
			f("exit", "quits the application"),
			f("(exp)", "a math expression consisting of numbers and operators") })
	{
		Print("\t\"%s\"\t\t%s\n"_p, p.first, p.second);
	}

	return;
}

void ReadLoop::display()
{
	this->intro();
	return;
}

void ReadLoop::handleInput()
{
	std::string buffer;
	while(std::cin.good())
	{
		Color(BLUE + BRIGHT, "Ready.\n] ");
		std::getline(std::cin, buffer);

		if(buffer.compare("help") == 0) { this->help(); }
		if(buffer.compare("intro") == 0) { this->intro(); }
		if(buffer.compare("exit") == 0) return;
	}
}
