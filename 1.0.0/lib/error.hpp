#ifndef inator__error__hpp
#define inator__error__hpp

enum { ANSI = (1 << 1) };

#define RED             "\033[30;101m"
#define BLUE            "\033[34m"
#define GREEN           "\033[32m"
#define RESET           "\033[0m"

static std::bitset<8> status(0x0000);

template<std::size_t T = 8>
[[ __noreturn__ ]] void error(const std::string_view &mes, const std::bitset<T> &flags, const std::source_location state = std::source_location::current())
{
        if(flags.test(ANSI))    fPrint(std::cerr, "%s(%s:%d)%s %s\n"_p, RED, state.file_name(), state.line(), RESET, mes);
        else                    fPrint(std::cerr, "(%s:%d) %s\n"_p, state.file_name(), state.line(), mes);

        exit(EXIT_FAILURE);
}

#define _Error(x) 				error(x, status)
#define _Assert(x, y) 				{ if (!(x)) { _Error(y); } }

inline void _Warn(const std::string_view &mes)	{ fPrint(std::cerr, "%s%s%s\n"_p, RED, mes, RESET); }
inline void _Note(const std::string_view &mes)	{ fPrint(std::cout, "%s%s%s\n"_p, GREEN, mes, RESET); }

#endif
