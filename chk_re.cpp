#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <time.h>
#include <fstream>
#include <vector>
#define int long long
using std::cin;
std::ofstream outFile;
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
int howMany = -1, cnt = 0, ac = 0, filemax = 10, cnt2 = 0;

struct ReadFile{
    std::vector<std::string> vec;
    bool content(){
        std::string result;
        std::ifstream infile;
        infile.open("checker.config", std::ios::in);
        if (!infile.is_open()){
            std::cout << "读取文件 'checker.config' 失败. 请在当前目录下检查你是否创建了该文件, 或者给予了本程序访问权限. " << '\n';
            return 0;
        }
        std::string buf;
        while (getline(infile, buf)){
            vec.push_back(buf);
        } 
        return 1;
    }
    void format(){
        printf("'checker.config' 文件不合法. \n");
        printf("格式: 一行一个文件路径或数字.\n");
        printf("  .. write your cpp file \n  .. write the right cpp file \n  .. write the make file \n  .. write the content folder\n  .. how many\n  .. filemax\n");
    }
    int getnum(std::string num){
        int ans = 0, fu = 1;
        for (auto v : num){
            if(v == '-') {fu = -1; continue;}
            (ans *= 10) += (v - '0');
        }
        return ans * fu;
    }
    bool anay(){
        if(vec.size() != 6) {
            format(); return 0;
        }
        outputCppFile = vec[0];
        inputCppFile = vec[0] + ".cpp";
        correctMakeFile = vec[1];
        correctCppFile = vec[1] + ".cpp";
        outputMakeFile = vec[2];
        inputMakeFile = vec[2] + ".cpp";
        inputFileFolder = vec[3] + "in/";
        outputFileFolder = vec[3] + "out/";
        howMany = getnum(vec[4]);
        filemax = getnum(vec[5]);
        return 1;
    }
}readfile;

clock_t st, ed;
void runcommand(std::string str){
    if(system(str.c_str())){
        puts("config内的配置文件可能存在问题, 或你的程序出现问题导致程序输出了额外语句, 请进行检查.");
    }
    outFile << str << '\n';
}
signed main(){
    
    if(!readfile.content()){
        puts("程序已退出.");
        return 0;
    }else{
        if(!readfile.anay()){
            puts("程序已退出.");
            return 0;
        }else{
            puts("成功读入config.");
        }
    }
    outFile.open(inputCppFile + "_log.log");
    res = "g++ -Wall -Wextra -std=c++17 -O2 " + inputCppFile + " -o " + outputCppFile;
    res2 = "g++ -Wall -Wextra -std=c++17 -O2 " + inputMakeFile + " -o " + outputMakeFile;
    res3 = "g++ -Wall -Wextra -std=c++17 -O2 " + correctCppFile + " -o " + correctMakeFile;
    // system(res.c_str());
    // system(res2.c_str());
    // system(res3.c_str());
    // outFile << res << '\n';
    // outFile << res2 << '\n';
    // outFile << res3 << '\n';
    runcommand(res);
    runcommand(res2);
    runcommand(res3);
    std::string tmp = "mkdir -p " + inputFileFolder;
    // system(tmp.c_str());
    runcommand(tmp);
    tmp = "mkdir -p " + outputFileFolder;
    // system(tmp.c_str());
    runcommand(tmp);
    while(howMany--){
        cnt %= filemax;
        cnt++, ac = 0, cnt2++;
        std::string comp = "", outer = "", correct = "", cp = "";
        comp = outputMakeFile + " > " + inputFileFolder + std::to_string(cnt) + ".in";
        // system(comp.c_str());
        runcommand(comp);
        // outFile << comp << "\n";
        outer = outputCppFile + " < " + inputFileFolder + std::to_string(cnt) + ".in" + " > " + outputFileFolder + std::to_string(cnt) + ".out";
        correct = correctMakeFile + " < " + inputFileFolder + std::to_string(cnt) + ".in" + " > " + outputFileFolder + std::to_string(cnt) + ".ans";
        // outFile << outer << "\n";
        printf("开始执行! Testcase %lld.\n", cnt2);
        // system(correct.c_str());
        runcommand(correct);
        st = clock();
        // system(outer.c_str());
        runcommand(outer);
        ed = clock();
        // outFile << outer << "\n";
        printf("结束执行,耗时%lf毫秒.\n", (double)(ed - st));
        cp = "diff -w " + outputFileFolder + std::to_string(cnt) + ".ans " + outputFileFolder + std::to_string(cnt) + ".out";
        outFile << cp << '\n';
        if(system(cp.c_str())) {
            puts("状态: Wrong Answer.");
            puts("程序已退出.");
            printf("错误文件输入: %lld.in\n", cnt);
            outFile << "Testcase " + std::to_string(cnt2) + " quit. Wrong Answer. Time = " + std::to_string(double(ed - st)) + "ms.\n";
            puts("一些操作的日志输出到了目录下的.log文件里面.");
            return 0;
        }else if(double(ed - st) >= 1000){
            puts("状态: Time Limit Exceeded.");
            outFile << "Testcase " + std::to_string(cnt2) + " Time Limit Exceeded.\n";
        }else{
            puts("状态: Accepted!");
            outFile << "Testcase " + std::to_string(cnt2) + " Accepted.\n";
        }
    }
    return 0;
}