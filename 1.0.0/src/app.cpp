#include "../lib/app.hpp"

Application::Application(std::unique_ptr<parcel<8>> &&mail) 	{ this->mailbox = std::move(mail); }
Application::Application(std::unique_ptr<State> &&input) 	{ this->States.push_back(std::move(input)); }
Application::Application(std::unique_ptr<State> &&input, std::unique_ptr<parcel<8>> &&mail)
{
	this->mailbox = std::move(mail);
	this->States.push_back(std::move(input));
}

void Application::send(std::unique_ptr<parcel<8>> &&mail)
{
	this->mailbox = std::move(mail);
}

void Application::push(std::unique_ptr<State> &&input)
{
	this->States.push_back(std::move(input));
}

void Application::pop()
{
	this->States.erase(States.begin());
}

void Application::process()
{
	if(this->mailbox == nullptr) _Error("parcel not found\n");

	while(!this->States.empty())
	{
		this->States.front()->run(this->mailbox);
		this->pop();
	}
}
