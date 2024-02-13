#include "../lib/includes.hpp"
#include "../lib/interface.hpp"
#include "../lib/error.hpp"

int main(int argc, char *argv[])
{
	_Assert(argc > 1, "too few arguments, try --help\n");

	for(std::string line; ; std::getline(std::cin, line))
	{
		Print("Ready.\n");
	}

	return 0;
}
