#ifndef inator__app__hpp
#define inator__app__hpp

#include "interface.hpp"
#include "state.hpp"
#include "parcel.hpp"

class Application
{
	private:
		std::vector<std::unique_ptr<State>> States;

	public:
		Application() { Print("Application::Application()\n"); };

		void push(std::unique_ptr<State> input);
		void pop(void);

		void run(void);
};

#endif
