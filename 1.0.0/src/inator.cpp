#include "../lib/includes.hpp"
#include "../lib/interface.hpp"
//#include "../lib/error.hpp"

int main(void)
{
	for(std::string line; ; std::getline(std::cin, line))
	{
		Color({101, 30}, "Ready.\n");
	}

	return 0;
}
