#ifndef inator__error__hpp
#define inator__error__hpp

#include "includes.hpp"
#include "interface.hpp"

#define	ANSI	(1 << 1)

// I'm used to using stdint.h and bitwise operations in C,
// so I welcome this bitset<> structure
static std::bitset<8> status;
static ColorPair err(BG + RED + BRIGHT, BLACK);

// Like with C version I made, This long, complicated function
// is not meant to be called directly, unless you want to supply
// the arguments directly
template<std::size_t T = 8>
[[ __noreturn__ ]] void error(const std::source_location &source, const std::string &mes, std::bitset<T> &flags)
{
	if(flags.test(ANSI))
	{
		Color(std::cerr, err, "[%s:%d] "_p, source.file_name(), source.line());
		fPrint(std::cerr, mes);
	}
	else
	{
		fPrint(std::cerr, "[%s:%d] "_p, source.file_name(), source.line());
		fPrint(std::cerr, mes);
	}

	std::exit(EXIT_FAILURE);
}

// Rather I'd want you to call this
#define _Error(x)	error(std::source_location::current(), x, status)
#define _Assert(x, y)	if(!(x)) { _Error(y); }

#endif
