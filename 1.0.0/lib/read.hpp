#ifndef inator__state__read__hpp
#define inator__state__read__hpp

#include "includes.hpp"
#include "interface.hpp"
#include "state.hpp"

class ReadLoop : public State
{
	private:
		double runningTotal = 0.00;

		void intro();
		void help();
	public:
		void display(std::shared_ptr<parcel<8>> &mail) override;
		void handleInput(std::shared_ptr<parcel<8>> &mail) override;
};

#endif
