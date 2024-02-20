#ifndef inator__state__read__hpp
#define inator__state__read__hpp

#include "includes.hpp"
#include "interface.hpp"
#include "state.hpp"

class ReadLoop : public State
{
	private:
		void intro();
		void help();

	public:
		void display(std::unique_ptr<parcel<8>> &mail) override;
		void handleInput(std::unique_ptr<parcel<8>> &mail) override;
};

#endif
