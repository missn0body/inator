#ifndef inator__calc__hpp
#define inator__calc__hpp

#include "includes.hpp"
#include "interface.hpp"
#include "parcel.hpp"
#include "state.hpp"

class Calculate : public State
{
	public:
		void display(std::shared_ptr<parcel<8>> &mail) override;
		void handleInput(std::shared_ptr<parcel<8>> &mail) override;
};

#endif
