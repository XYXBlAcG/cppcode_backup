#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 1e5 + 5;

int main(){
    std::string str = "";
    std::cin >> str;
    std::string runcommand = "touch /Users/xiexie/code/cpp_new/" + str + ".cpp";
    system(runcommand.c_str());
    runcommand = "cp /Users/xiexie/code/cpp_new/format_new.cpp /Users/xiexie/code/cpp_new/" + str + ".cpp"; 
    system(runcommand.c_str());
    runcommand = "code /Users/xiexie/code/cpp_new/" + str + ".cpp";
    system(runcommand.c_str());
    return 0;
}