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

	// I wanted a better way to print two columns of information so I came up with this lambda to
	// make a std::pair object on the spot
	auto f = [](const std::string &one, const std::string &two) { return std::make_pair(one, two); };
	for(auto &p : { f("help", "displays this info"),
			f("intro", "displays the intro"),
			f("exit", "quits the application"),
			f("ansi on", "turns on ANSI colors"),
			f("ansi off", "turns off ANSI colors"),
			f("verbose on", "displays verbose information and debugging statements"),
			f("verbose off", "turns off verbose mode"),
			f("(exp)", "a math expression consisting of numbers and operators") })
	{
		// With the longer commands, the tab character kind of breaks, so for clean cut columns
		// of text, some arbitrary value minus the length of the command will provide adequate
		// spacing
		Print("\t\"%s\"%s%s\n"_p, p.first, std::string((15 - p.first.length()) + 1, ' '),  p.second);
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
	// I like to call the user a stupid smelly dumb head whenever I can :3
	std::vector<std::string> pardon = { "huh?", "pardon?", "excuse me?", "que?", "gesundheit?", "bless you?", "what?", "eh?" };

	// The lambda functions below are quick shorthands to make the gigantic if/else statement
	// below use less characters. r() provides a quick case-insensitive (sort of) regex pattern
	// for any given single word
	// Unfortunately std::regex seems to be the problem child of the regex engines (or so some user
	// on StackOverflow told me) and does not support any lookahead/behind of any kind, making these
	// regex patterns not truly case insensitive. I like to make my regex patterns nice and concise,
	// and I have other parts of this program that I really should be putting more effort in
	auto r = [&](const std::string &str)
	{
		if	(str[0] < 91 && isprint(str[0])) head = sPrint("%c%c"_p, str[0], (char)(str[0] + 32));
		else if	(str[0] > 96 && isprint(str[0])) head = sPrint("%c%c"_p, (char)(str[0] - 32), str[0]);
		foot = str.substr(1);

		pattern = sPrint("\\s*[%s](%s)?\\s*"_p, head, foot);
		return pattern;
	};
	// And this lambda is a shorthand for writing std::regex_match. Any lambda that serves to
	// solely be a shorthand, I usually assign a single character
	auto m = [&](const std::string &rx)
	{
		if(mail->test(VERBOSE)) Print("%s\n"_p, rx);
		return std::regex_match(buffer, std::regex(rx));
	};

	while(std::cin.good())
	{
		if(mail->test(ANSI)) 	Color(BLUE + BRIGHT, "Ready.\n] ");
		else 			Print("Ready.\n] ");

		std::getline(std::cin, buffer);

		// In this list of statements here, we only parse no-argument commands
		// and switch-argument commands, such that their only arguments are a switch,
		// either on or off.
		if	(m(r("help")))  			{ this->help(); }
		else if	(m(r("intro"))) 			{ this->intro(); }
		else if	(m(r("exit"))) 				{ mail->set(EXIT); }
		else if	(m(r("quit")))				{ mail->set(EXIT); }
		else if (m("\\s*[Aa]nsi\\s+[Oo]n\\s*"))		{ mail->set(ANSI); }
		else if (m("\\s*[Aa]nsi\\s+[Oo]ff\\s*"))	{ mail->unset(ANSI); }
		else if (m("\\s*[Vv]erbose\\s+[Oo]n\\s*"))  	{ mail->set(VERBOSE); }
		else if (m("\\s*[Vv]erbose\\s+[Oo]ff\\s*")) 	{ mail->unset(VERBOSE); }
		// The message below is mainly a placeholder
		else if (m("\\d.*") && mail->test(VERBOSE)) 	{ Print("Looks like you've typed some sort of expression.\n"); }
		else
		{
			if(mail->test(ANSI)) Color(YELLOW, "%s\n"_p, pardon[rng.randomInt(0, pardon.size() - 1)]);
			else 		     Print("%s\n"_p, pardon[rng.randomInt(0, pardon.size() - 1)]);
		}

		if(mail->test(EXIT)) return;
	}
}
