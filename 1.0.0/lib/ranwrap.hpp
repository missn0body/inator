#ifndef inator__ranwrap__hpp
#define inator__ranwrap__hpp

#include "includes.hpp"

template<typename engine = std::mt19937>
class Random
{
    template<typename T>
    using uniDst = std::uniform_real_distribution<T>;
    using uniInt = std::uniform_int_distribution<int>;

    private:
        engine internals;

    public:
        Random(unsigned seed = std::chrono::system_clock::now().time_since_epoch().count()) : internals(seed) {};

        template<typename dist, typename T>
        T getNum(T low, T high)
        {
            dist range(low, high);
            return range(internals);
        }

        template<typename T>
        T getNum(T low, T high) { return getNum<uniDst<T>>(low, high); }

        int randomInt(int low, int high)        { return getNum<uniInt>(low, high); }
        float randomFloat(float low, float high){ return getNum<uniDst<float>>(low, high); }
};

static Random rng;

#endif
