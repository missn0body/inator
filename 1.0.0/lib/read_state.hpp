#ifndef inator__read__state__hpp
#define inator__read__state__hpp

#include "interface.hpp"
#include "state.hpp"

class ReadLoop : State
{
	void handleInput(void) override;
	void run(void) override;
}

#endif
