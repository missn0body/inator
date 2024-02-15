#include "../lib/app.hpp"

void Application::push(std::unique_ptr<State> input)
{
	Print("Application::push()\n");
}

void Application::pop(void)
{
	Print("Application::pop()\n");
}

void Application::run(void)
{
	Print("Application::run()\n");
}
