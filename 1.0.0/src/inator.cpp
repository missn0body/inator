#include "../lib/includes.hpp"
#include "../lib/interface.hpp"

class A
{
	public: virtual void hm() = 0;
};

class B : public A
{
	public: virtual void hm() override { Print("Inherited\n"); }
};

class C : public A
{
	public: virtual void hm() override { Print("Second inherited\n"); }
};

int main(void)
{
	std::vector<std::unique_ptr<A>> States;

	States.push_back(std::make_unique<B>());
	States.push_back(std::make_unique<C>());

	while(!States.empty())
	{
		States.front()->hm();
		States.erase(States.begin());
	}

	return 0;
}
