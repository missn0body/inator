#ifndef inator__state__state__hpp
#define inator__state__state__hpp

#include "includes.hpp"

class State
{
	private:
		std::string what;

	public:
		State() : what("(null)") 			{}
		State(const std::string &name) : what(name) 	{}

		virtual void display() = 0;
		virtual void handleInput() = 0;

		void run() 					{ this->display(); this->handleInput(); }
};

#endif
