#include "../lib/read.hpp"
#include "../lib/ranwrap.hpp"

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
			f("ansi", "turns on ANSI colors"),
			f("dansi", "tuns off ANSI colors"),
			f("(exp)", "a math expression consisting of numbers and operators") })
	{
		Print("\t\"%s\"\t\t%s\n"_p, p.first, p.second);
	}

	return;
}

void ReadLoop::display(std::unique_ptr<parcel<8>> &mail)
{
	if(mail->test(CALC) == false) mail->set(CALC);
	this->intro();
	return;
}

void ReadLoop::handleInput(std::unique_ptr<parcel<8>> &mail)
{
	std::string buffer, head, foot, pattern;
	std::smatch results;

	std::vector<std::string> pardon = { "huh?", "pardon?", "excuse me?", "que?", "gesundheit?", "bless you?"};
	auto r = [&](const std::string &str)
	{
		if	(str[0] < 91 && isprint(str[0])) head = sPrint("%c%c"_p, str[0], (char)(str[0] + 32));
		else if	(str[0] > 96 && isprint(str[0])) head = sPrint("%c%c"_p, (char)(str[0] - 32), str[0]);
		foot = str.substr(1);

		pattern = sPrint("[%s](%s)?"_p, head, foot);
		return std::regex(pattern);
	};

	while(std::cin.good())
	{
		if(mail->test(ANSI)) 	Color(BLUE + BRIGHT, "Ready.\n] ");
		else 			Print("Ready.\n] ");

		std::getline(std::cin, buffer);

		if	(std::regex_match(buffer, r("help"))) 	{ this->help(); }
		else if	(std::regex_match(buffer, r("intro"))) 	{ this->intro(); }
		else if (std::regex_match(buffer, r("ansi")))	{ mail->set(ANSI); }
		else if (std::regex_match(buffer, r("dansi")))	{ mail->unset(ANSI); }
		else if	(std::regex_match(buffer, r("exit"))) 	{ mail->set(EXIT); }
		else if	(std::regex_match(buffer, r("quit"))) 	{ mail->set(EXIT); }
		else if	(std::regex_match(buffer, r("kill"))) 	{ mail->set(EXIT); }
		else
		{
			if(mail->test(ANSI)) 	Color(YELLOW, "%s\n"_p, pardon[rng.randomInt(0, pardon.size() - 1)]);
			else 			Print("%s\n"_p, pardon[rng.randomInt(0, pardon.size() - 1)]);
		}

		if(mail->test(EXIT)) return;
	}
}
