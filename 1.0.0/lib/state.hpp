#ifndef inator__state__state__hpp
#define inator__state__state__hpp

#include "includes.hpp"
#include "parcel.hpp"

class State
{
	private:
		std::string what;

	public:
		State() : what("(null)") 			{}
		State(const std::string &name) : what(name) 	{}

		virtual void display(std::shared_ptr<parcel<8>> &mail) = 0;
		virtual void handleInput(std::shared_ptr<parcel<8>> &mail) = 0;

		void run(std::shared_ptr<parcel<8>> &mail)	{ this->display(mail); this->handleInput(mail); }
};

#endif
