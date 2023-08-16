#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <time.h>
using std::cin;
const int N = 2005;
std::string inp, res, out, inf, ouf, res2;
clock_t st, ed;
int main(){
    puts("请输入你的cpp程序路径,如果跳过这一步,请输入-1,路径长度不应超过1k.");
    std::getline(std::cin, inp);
    puts("请输入你的cpp编译文件路径.,路径长度不应超过1k.");
    std::getline(std::cin, out);
    res = "g++ -Wall -Wextra -std=c++14 " + inp + " -o " + out;
    system(res.c_str());
    puts("如果编译成功,请输入输入文件路径:");
    std::getline(std::cin, inf);
    puts("如果编译成功,请输入输出文件路径:");
    std::getline(std::cin, ouf);
    res2 = out + " < " + inf + " > " + ouf;
    puts("开始执行!");
    st = clock();
    system(res2.c_str());
    ed = clock();
    printf("结束执行,耗时%lf毫秒.\n", double(ed - st));
    return 0;
}