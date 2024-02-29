#include "../lib/app.hpp"

Application::Application(std::shared_ptr<parcel<8>> &&mail) 	{ this->mailbox = std::move(mail); }
Application::Application(std::unique_ptr<State> &&input) 	{ this->States.push_back(std::move(input)); }
Application::Application(std::unique_ptr<State> &&input, std::shared_ptr<parcel<8>> &&mail)
{
	this->mailbox = std::move(mail);
	this->States.push_back(std::move(input));
}

void Application::send(std::shared_ptr<parcel<8>> &&mail)
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

		// TODO: I don't like how this currently implements state switching.
		// Something about the derived states having to share space with the
		// internals of the Application object just rubs me the wrong way, it
		// makes something like this a little harder to use for other projects
		// I'm thinking an Application object should be passed a container of State
		// objects that it can reference when being asked to switch to a specific State

		if(this->mailbox->test(EXIT)) return;
	}
}
