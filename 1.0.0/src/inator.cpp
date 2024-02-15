#include "../lib/error.hpp"
#include "../lib/interface.hpp"
#include "../lib/parcel.hpp"
#include "../lib/app.hpp"

int main(int argc, char *argv[])
{
	_Assert(argc > 1, "too few arguments, try --help");

	Application MainApp;
	MainApp.run();

	return 0;
}
