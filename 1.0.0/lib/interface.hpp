#ifndef inator__interface__hpp
#define inator__interface__hpp

#include "includes.hpp"

using namespace std::literals::string_literals;

// Shorthands for creating and operating on objects
inline std::regex  operator ""_r(const char *in, std::size_t len) 	{ return std::regex(in, len); }
inline std::string operator ""_p(const char *in, std::size_t len) 	{ return std::regex_replace(std::string(in, len), "%[a-z]"_r, "{}"s); }
inline std::string operator +(std::string &first, std::string &second) 	{ return first.append(second); }

// Some printf-esque functions in an attempt to keep this code as modern as I want it.
// I don't necessarily like putting a lot of C code in my C++ code, but I also don't really
// like how C++ does output...
namespace
{
        template<typename... Args>
        inline std::string sPrint(const std::string_view &format, Args&&... args)
        {
                return std::vformat(format, std::make_format_args(args...));
        }

        template<typename... Args>
        inline void fPrint(std::ostream &out, const std::string_view &format, Args&&... args)
        {
                out << std::vformat(format, std::make_format_args(args...));
        }

	template <typename... Args>
	inline void Print(const std::string_view &format, Args&&... args)
	{
		fPrint(std::cout, format, args...);
	}
};

// My own small object for defining ANSI color pairs
// I've defined the enumeration below in that I can add
// together these types to create certain attributes that are
// easier to read when looking at source code
enum { BG = 10, BLACK = 30, RED, GREEN, YELLOW, BLUE, BRIGHT = 60 };
struct ColorPair
{
	std::array<unsigned, 2> col;

	ColorPair(unsigned one, unsigned two) : col{one, two} { }
	unsigned operator[](std::size_t index) const { return col[index]; }
};

// Below are a bunch of overloaded functions for outputing
// colors to the screen using ANSI escape codes. These essentially
// wrap around the above functions, creating another level of abstraction.
// First two do not require an outstream argument. I like choices.
template<typename... Args>
inline void Color(unsigned code, std::string &&format, Args&&... args)
{
	Print("\033[%um"_p + format + "\033[0m"s, code, args...);
}

// These ColorPair object arguments can also be fulfiled by passing an
// anonymous object (such as ColorPair(bg, fg) ), or as an initializer list
// (such as {bg, fg } )
template<typename... Args>
inline void Color(const ColorPair &pair, std::string &&format, Args&&... args)
{
	Print("\033[%u;%um"_p + format + "\033[0m"s, pair[0], pair[1], args...);
}

template<typename... Args>
inline void Color(std::ostream &out, unsigned code, std::string &&format, Args&&... args)
{
	fPrint(out, "\033[%um"_p + format + "\033[0m"s, code, args...);
}

template<typename... Args>
inline void Color(std::ostream &out, const ColorPair &pair, std::string &&format, Args&&... args)
{
	fPrint(out, "\033[%u;%um"_p + format + "\033[0m"s, pair[0], pair[1], args...);
}

#endif
