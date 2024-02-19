#ifndef inator__state__read__hpp
#define inator__state__read__hpp

#include "includes.hpp"
#include "interface.hpp"
#include "state.hpp"

class ReadLoop : public State
{
	public:
		void display() override;
		void handleInput() override;
};

#endif
