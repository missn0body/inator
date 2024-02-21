#ifndef inator__error__hpp
#define inator__error__hpp

#include "includes.hpp"
#include "interface.hpp"
#include "parcel.hpp"

// My C wrapper for printing error functions, but in C++!
// std::source_location is a bit strange, __FILE__ and __LINE__ happen
// to be more concise, but in the land of C++23, I'm compelled to use C++23

template<unsigned T = 8>
[[ __noreturn__ ]] void error(const std::source_location &loc, std::string &&mes, const parcel<T> &status)
{
	if(status.test(ANSI))
	{
		Color(std::cerr, { 101, 30 }, "[%s:%d] "_p, loc.file_name(), loc.line());
		fPrint(std::cerr, "%s\n"_p, mes);
	}
	else
	{
		fPrint(std::cerr, "[%s:%d] %s\n"_p, loc.file_name(), loc.line(), mes);
	}

	std::exit(EXIT_FAILURE);
}

// And of course, these are the actual functions that you should be using.
// Unless you want your errors to always point to this file here
#define _Error(x)	error(std::source_location::current(), x, MainParcel)
#define _Assert(x, y)	if(!(x)) { _Error(y); }

#endif
