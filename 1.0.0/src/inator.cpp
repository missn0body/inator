#include "../lib/includes.hpp"
#include "../lib/interface.hpp"

class A
{
	private:
		std::string what;

	public:
		A(void) : what("(null)") 		{}
		A(const std::string &what) : what(what) {}

		std::string name(void) const { return this->what; }

		virtual void handleInput() = 0;
		virtual void display() = 0;

		inline void run() { this->display(); this->handleInput(); };
};

class B : public A
{
	public:
		virtual void handleInput() override { Print("B's handleInput()\n"); }
		virtual void display() override	    { Print("B's display()\n"); }
};

class C : public A
{
	public:
		virtual void handleInput() override { Print("C's handleInput()\n"); }
		virtual void display() override	    { Print("C's display()\n"); }
};

int main(void)
{
	std::vector<std::unique_ptr<A>> States;

	States.push_back(std::make_unique<B>());
	States.push_back(std::make_unique<C>());

	while(!States.empty())
	{
		States.front()->run();
		States.erase(States.begin());
	}

	return 0;
}
