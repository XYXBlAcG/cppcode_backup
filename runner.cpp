#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include "xyx.h"
#define int long long
const int N = 1e5 + 5;
using std::cin;
using std::string;
string str;
namespace calval{
    int pr[N], x;
    char c;
    bool f;
    std::vector<int> num;
    std::vector<char> op;
    void eval() {
        int b = num.back();
        num.pop_back();
        int a = num.back();
        num.pop_back();
        char c = op.back();
        op.pop_back();
        if (c == '+')
            num.push_back(a + b);
        else if (c == '-')
            num.push_back(a - b);
        else if (c == '*')
            num.push_back(a * b);
        else {
            if (b)
                num.push_back(a / b);
            else {
                printf("div 0 or wrong arguments.");
                exit(0);
            }
        }
    }
    void do_() {
        if (f && (c < '0' || c > '9'))
            f = false, num.push_back(x), x = 0;
        if (c >= '0' && c <= '9') {
            f = true;
            x = x * 10 + c - '0';
        } else if (c == '(')
            op.push_back('(');
        else if (c == ')') {
            while (op.back() != '(') eval();
            op.pop_back();
        } else {
            while (pr[op.back()] >= pr[c]) eval();
            op.push_back(c);
        }
    }
    void main() {
        memset(pr, 0, sizeof(pr)), c = 0, f = 0, x = 0, num.clear(), op.clear();
        pr['+'] = pr['-'] = 1, pr['*'] = pr['/'] = 2;
        c = '(';
        do_();
        while ((c = getchar()) != '\n') do_();
        c = ')';
        do_();
        while (num.size() > 1) eval();
        printf("%lld\n", num.back());
    }
}
// void runcommand(){
//     if(str.find("print")){
        
//     }
// }
signed main(){
    puts("loading...");
    while(true){
        printf(">>> ");
        // cin >> str;
        calval::main();
    }
    return 0;
}