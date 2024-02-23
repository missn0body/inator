#include "../lib/app.hpp"
#include "../lib/read.hpp"
#include "../lib/includes.hpp"
#include "../lib/interface.hpp"
#include "../lib/parcel.hpp"

int main(void)
{
	Application inator(std::make_unique<ReadLoop>());
	inator.send(std::make_shared<parcel<8>>(MainParcel));

	inator.process();
	return 0;
}
