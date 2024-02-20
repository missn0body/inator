#ifndef inator__parcel__hpp
#define inator__parcel__hpp

#include "includes.hpp"
#include "interface.hpp"

enum { ANSI, VERBOSE, EXIT, CALC, READ };

template<unsigned T = 8>
struct parcel
{
	std::string info;
	std::bitset<T> internals;

	parcel(void) : info("(null)"), internals(0x00) {}
	parcel(const std::string &what) : info(what), internals(0x00) {}

	bool test(std::size_t index) const 	{ return this->internals.test(index); }

	void set(std::size_t index)		{ this->internals.set(index); }
	void unset(std::size_t index)		{ this->internals.set(index, false); }

	inline void spill(void) { Print("parcel reports: \"%s\"\n"_p, this->info); }
};

static parcel MainParcel;

#endif
