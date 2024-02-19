#include "../lib/app.hpp"

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
	while(!this->States.empty())
	{
		this->States.front()->run();
		this->pop();
	}
}
