#ifndef inator__interface__hpp
#define inator__interface__hpp

#include "includes.hpp"

using namespace std::literals::string_literals;

inline std::regex  operator ""_r(const char *in, std::size_t len) { return std::regex(in, len); }
inline std::string operator ""_p(const char *in, std::size_t len) { return std::regex_replace(std::string(in, len), "%[a-z]"_r, "{}"s); }
inline std::string operator +(std::string &first, std::string &second) { return first.append(second); }

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

enum { FG = 10, BLACK = 30, RED = 31, GREEN = 32, BLUE = 34, BRIGHT = 60 };
struct ColorPair
{
	std::array<unsigned, 2> col;

	ColorPair(unsigned one, unsigned two) : col{one, two} { }
	unsigned operator[](std::size_t index) const { return col[index]; }
};

static ColorPair err(RED + FG + BRIGHT, BLACK);

template<typename... Args>
inline void Color(unsigned code, std::string &&format, Args&&... args)
{
	Print("\033[%um"_p + format + "\033[0m"s, code, args...);
}

template<typename... Args>
inline void Color(const ColorPair &pair, std::string &&format, Args&&... args)
{
	Print("\033[%u;%um"_p + format + "\033[0m"s, pair[0], pair[1], args...);
}

#endif
