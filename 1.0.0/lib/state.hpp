#ifndef inator__state__hpp
#define inator__state__hpp

struct State
{
	virtual void handleInput() = 0;
	virtual void run() = 0;
};

#endif
