#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <cstdlib>
std::string cf, out;
struct ReadFile{
    std::vector<std::string> vec;
    bool content(){
        std::string result;
        std::ifstream infile;
        infile.open("read.config", std::ios::in);
        if (!infile.is_open()){
            std::cout << "读取文件 'read.config' 失败. 请在当前目录下检查你是否创建了该文件, 或者给予了本程序访问权限. " << '\n';
            return 0;
        }
        std::string buf;
        while (getline(infile, buf)){
            vec.push_back(buf);
        } 
        return 1;
    }
    void format(){
        printf("'read.config' 文件不合法. \n");
        printf("格式: 一行一个文件路径或数字.\n");
        printf("二进制文件\n输出文件\n");
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
        if(vec.size() != 2) {
            format(); return 0;
        }
        cf = vec[0];
        out = vec[1];
        return 1;
    }
}readfile;
int main(){
    if(!readfile.content()){
        return 0;
    }else{
        if(!readfile.anay()){
            return 0;
        }else{
            puts("以下是输出到屏幕的内容:");
        }
    }
    system(cf.c_str());
    
    #ifdef WIN_32
        std::ifstream infile;
        infile.open(out, std::ios::in);
        if (!infile.is_open()){
            std::cout << "读取文件 " << out << " 失败. 请在当前目录下检查你是否创建了该文件, 或者给予了本程序访问权限. " << '\n';
            return 0;
        }
        std::string buf;
        while(getline(infile, buf)){
            std::cout << buf << '\n';
        }
    #else
        std::string tmp = "cat " + out;
        system(tmp.c_str());
    #endif
    return 0;
}