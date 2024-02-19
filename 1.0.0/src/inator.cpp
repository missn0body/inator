#include "../lib/app.hpp"
#include "../lib/read.hpp"
#include "../lib/includes.hpp"
#include "../lib/interface.hpp"

int main(void)
{
	Application inator;
	inator.push(std::make_unique<ReadLoop>());
	inator.process();

	return 0;
}
