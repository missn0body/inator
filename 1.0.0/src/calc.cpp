#include "../lib/calc.hpp"

void Calculate::shunt(std::shared_ptr<parcel<8>> &mail)
{
	std::string copy = mail->info;
	for(; !copy.empty(); copy.erase(copy.begin()))
	{
		char index = copy.front();
		if(index == '\t' || index == ' ') continue;

		Print("%s\n"_p, index);
	}
}

void Calculate::display(std::shared_ptr<parcel<8>> &mail)
{
	// TODO: one of these days I'll make a parcel function
	// to easily switch one bit on and the other off in one statement
	if(mail->test(SWITCH)) mail->unset(SWITCH);
	if(!mail->test(CALC)) mail->set(CALC);

	this->shunt(mail);
}

void Calculate::handleInput(std::shared_ptr<parcel<8>> &mail)
{
	mail->unset(CALC);
	mail->set(READ);
	mail->set(SWITCH);
}
