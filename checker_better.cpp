#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <time.h>
#include <fstream>
#define int long long
using std::cin;
std::string inputCppFile = "/Users/xiexie/code/cpp_new/6142.cpp", \
res, \
outputCppFile = "/Users/xiexie/code/cpp_new/6142", \
correctCppFile = "/Users/xiexie/code/cpp_new/6142_cp.cpp", \
correctMakeFile = "/Users/xiexie/code/cpp_new/6142_cp", \
inputMakeFile = "/Users/xiexie/code/cpp_new/6142_gen.cpp", \
outputMakeFile = "/Users/xiexie/code/cpp_new/6142_gen", \
res2, \
res3, \
inputFileFolder = "/Users/xiexie/code/cpp_new/6142_f/in/", \
outputFileFolder = "/Users/xiexie/code/cpp_new/6142_f/out/";
int howMany = -1, cnt = 0, ac = 0;
clock_t st, ed;
signed main(){
    std::ofstream outFile;
    res = "g++ -Wall -Wextra -std=c++14 " + inputCppFile + " -o " + outputCppFile;
    res2 = "g++ -Wall -Wextra -std=c++14 " + inputMakeFile + " -o " + outputMakeFile;
    res3 = "g++ -Wall -Wextra -std=c++14 " + correctCppFile + " -o " + correctMakeFile;
    system(res.c_str());
    system(res2.c_str());
    system(res3.c_str());
    outFile.open(inputCppFile + "_log.log");
    outFile << res;
    outFile << res2;
    outFile << res3;
    std::string tmp = "mkdir -p " + inputFileFolder;
    system(tmp.c_str());
    tmp = "mkdir -p " + outputFileFolder;
    system(tmp.c_str());
    while(howMany--){
        cnt++, ac = 0;
        std::string comp = "", outer = "", correct = "", cp = "";
        comp = outputMakeFile + " > " + inputFileFolder + std::to_string(cnt) + ".in";
        system(comp.c_str());
        outFile << comp << "\n";
        outer = outputCppFile + " < " + inputFileFolder + std::to_string(cnt) + ".in" + " > " + outputFileFolder + std::to_string(cnt) + ".out";
        correct = correctMakeFile + " < " + inputFileFolder + std::to_string(cnt) + ".in" + " > " + outputFileFolder + std::to_string(cnt) + ".ans";
        outFile << outer << "\n";
        printf("开始执行! Testcase %lld.\n", cnt);
        system(correct.c_str());
        st = clock();
        system(outer.c_str());
        ed = clock();
        outFile << outer << "\n";
        printf("结束执行,耗时%lf毫秒.\n", (double)(ed - st));
        cp = "diff -w " + outputFileFolder + std::to_string(cnt) + ".ans " + outputFileFolder + std::to_string(cnt) + ".out";
        if(system(cp.c_str())) {
            puts("状态: Wrong Answer.");
            puts("程序已退出.");
            outFile << "Testcase " + std::to_string(cnt) + " quit. Wrong Answer. Time = " + std::to_string(double(ed - st)) + "ms.\n";
            puts("一些操作的日志输出到了目录下的.log文件里面.");
            return 0;
        }else if(double(ed - st) >= 1000){
            puts("状态: Time Limit Exceeded.");
            outFile << "Testcase " + std::to_string(cnt) + " Time Limit Exceeded.";
        }else{
            puts("状态: Accepted!");
            outFile << "Testcase " + std::to_string(cnt) + " Accepted.";
        }
        
    }
    return 0;
}