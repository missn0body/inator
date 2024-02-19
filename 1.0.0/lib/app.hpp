#ifndef inator__state__app__hpp
#define inator__state__app__hpp

#include "state.hpp"

class Application
{
	private:
		std::string what;
		std::vector<std::unique_ptr<State>> States;

	public:
		void push(std::unique_ptr<State> &&input);
		void pop(void);

		void process(void);
};

#endif
