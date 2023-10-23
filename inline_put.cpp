#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using std::setw;
namespace xyx{
    // debugger output
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
    // fast read
    template<typename T>
    void read(T& x) {
        T w = 1;
        char ch = 0;
        while (ch < '0' || ch > '9') {
            if (ch == '-') w = -1;
            ch = getchar();
        }
        while (ch >= '0' && ch <= '9') {
            x = x * 10 + (ch - '0');
            ch = getchar();
        }
        x *= w;
    }
    template<typename T>
    void fin(T& cur){cur = 0, read(cur);}
    template<typename T, typename... Args>
    void fin(T& cur, Args&... args){
        cur = 0;
        read(cur);
        if(sizeof...(args) > 0){
            fin(args...);
        }
    }
    // fast output
    template<typename T>
    void write(T x) {
        T sta[40];
        int top = 0;
        do {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top) putchar(sta[--top] + 48);
    }
    template<typename T>
    void fout(T cur){write(cur);}
    template<typename T, typename... Args>
    void fout(T cur, Args... args){
        write(cur);
        if(sizeof...(args) > 0){
            fout(args...);
        }
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