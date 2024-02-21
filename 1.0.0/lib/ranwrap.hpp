#ifndef inator__ranwrap__hpp
#define inator__ranwrap__hpp

#include "includes.hpp"

// This is from an earlier project that never really got off the ground,
// and really, it shamelessly copies a part from Hopson's basic SFML game engine
// I use it because it happens to be terse and really easy to use, compared
// with the often wordy syntax for PRNGs that C++ offers
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
