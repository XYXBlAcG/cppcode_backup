#include <cstdio>
#include <cstdlib>
#include <ctime>
namespace xyx{
    void frand(){srand((unsigned)time(NULL));}
    template <typename T>
    T random(T a = 0, T b = RAND_MAX){
        return (rand() % (b - a + 1)) + a;
    }
    template <typename T>
    T rand01(){return rand() / double(RAND_MAX);}
};
