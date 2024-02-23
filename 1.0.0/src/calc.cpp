#include "../lib/calc.hpp"

void Calculate::handleInput(std::shared_ptr<parcel<8>> &mail)
{
	if(mail->test(SWITCH)) mail->unset(SWITCH);
	if(!mail->test(CALC)) mail->set(CALC);

	Print("Calculate::handleInput()\n");
}

void Calculate::display(std::shared_ptr<parcel<8>> &mail)
{
	Print("Calculate::display()\n");
}
