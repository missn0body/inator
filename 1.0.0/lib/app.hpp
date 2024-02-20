#ifndef inator__state__app__hpp
#define inator__state__app__hpp

#include "state.hpp"
#include "parcel.hpp"

class Application
{
	private:
		std::vector<std::unique_ptr<State>> States;
		std::unique_ptr<parcel<8>> mailbox;

	public:
		Application(std::unique_ptr<parcel<8>> &&mail);
		Application(std::unique_ptr<State> &&input);
		Application(std::unique_ptr<State> &&input, std::unique_ptr<parcel<8>> &&mail);

		void send(std::unique_ptr<parcel<8>> &&input);

		void push(std::unique_ptr<State> &&input);
		void pop(void);

		void process(void);
};

#endif
