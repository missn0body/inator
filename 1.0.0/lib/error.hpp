#ifndef inator__error__hpp
#define inator__error__hpp

#include "includes.hpp"
#include "interface.hpp"
#include "parcel.hpp"

template<unsigned T = 8>
[[ __noreturn__ ]] void error(const std::source_location &loc, std::string &&mes, const parcel<T> &status)
{
	if(status[ANSI])
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

#define _Error(x)	error(std::source_location::current(), x, MainParcel)
#define _Assert(x, y)	if(!(x)) { _Error(y); }

#endif
