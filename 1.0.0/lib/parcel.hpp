#ifndef inator__parcel__hpp
#define inator__parcel__hpp

#include "includes.hpp"

enum { ANSI = (1 << 1), VERBOSE = (1 << 2), EXIT = (1 << 3), CALC = (1 << 4), READ = (1 << 5) };

template<unsigned T = 8>
struct parcel
{
	std::string sender, reciever;
	std::bitset<T> internals;

	parcel(void) : sender("(null)"), reciever("(null)"), internals(0x00) {}
	parcel(const std::string &first, const std::string &second) : sender(first), reciever(second), internals(0x00) {}

	bool operator[](std::size_t index) const 	{ return this->internals.test(index); }

	void set(std::size_t index)			{ this->internals.set(index); }
	void unset(std::size_t index)			{ this->internals.unset(index); }

	inline void spill(void) { Print("parcel reports: \"%s\" as sender, \"%s\" as reciever\n"_p, this->sender, this->reciever); }
};

static parcel MainParcel;

#endif
