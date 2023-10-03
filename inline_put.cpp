#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using std::setw;
namespace xyx{
    int hang = 10;
    void out(){putchar('\n');}
    template<typename T, typename... Args>
    void out(T cur, Args... args){
        std::cout << cur;
        if(sizeof...(args) > 0){
            std::cout << setw(hang);
            out(args...);
        }else out();
    }
    template<typename... Args>
    void output(int ha, Args... args){
        hang = ha;
        out(args...);
    }
};
// old putIO

// template <typename T>
// struct IO{
//     void ele_1(std::string content, T a, int hang = 10){
//         std::cout << content << setw(hang) << a << std::endl;
//     }
//     void ele_2(std::string content, T a, T b, int hang = 10){
//         std::cout << content << setw(hang) << a << setw(hang) << b << std::endl;
//     }
//     void ele_3(std::string content, T a, T b, T c, int hang = 10){
//         std::cout << content << setw(hang) << a << setw(hang) << b << setw(hang) << c << std::endl;
//     }
//     void ele_4(std::string content, T a, T b, T c, T d, int hang = 10){
//         std::cout << content << setw(hang) << a << setw(hang) << b << setw(hang) << c << setw(hang) << d << std::endl;
//     }
//     void ele_5(std::string content, T a, T b, T c, T d, T e, int hang = 10){
//         std::cout << content << setw(hang) << a << setw(hang) << b << setw(hang) << c << setw(hang) << d << setw(hang) << e << std::endl;
//     }
// };
// IO<int> intIO;
// IO<long long> longIO;
// IO<std::string> stringIO;
// IO<char> charIO;