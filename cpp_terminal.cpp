//head
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>

#define debug(x) cout << #x << " = \"" << x << "\"" << endl
#define commandless(x, y) cout << "在 " << x << " 中找不到指令: " << y << endl << "输入 help 以查看更多信息" << endl
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::endl;


//var
vector<string> command;
vector<string> helpl;
string now = "";
string compfile = "", outfile = "", input = "", output = "", filehead = "";
int from = 0, to = 0;


//method
void print(string content){
    cout << content << endl;
}

string input(string com){
    if(com != "") printf("%s $ ", com.c_str());
    else printf("$ ");
    string inp;
    std::getline(cin, inp);
    cin >> inp;
    return inp;
}

void init(){
    command.push_back("help");
    helpl.push_back("-l");
    helpl.push_back("-q");
    

    command.push_back("clear");
    command.push_back("quit");
    command.push_back("setc");
    command.push_back("cr");

    for (string v : command)
        helpl.push_back(v);
    
    system("clear");
    putchar('\n');
}

bool checker(vector<string> &mother, string inp){
    for (auto v : mother)
        if(inp == v) return 1;
    return 0;
}

string commander(string inp){
    now = inp;
    if(inp == "help"){
        return "帮助列表\n以下是常见指令:\n-l 列出 help 有哪些指令\n\'具体的一个指令\' 查找当前指令的帮助\n -q 退出 help 指令";
    }else if(inp == "clear"){
        system("clear");
        // putchar('\n');
        now = "";
        return "cleared.\n";
    }else if(inp == "quit"){
        return "你确定要退出吗? (y/n)";
    }else if(inp == "setc"){
        return "设置\n";
    }else if(inp == "cr"){
        string compp = "g++ -Wall -Wextra -g3 ";
        compp += compfile;
        compp += " -o ";
        compp += outfile;
        compp += " -std=c++14";
        char tmpc[1000] = compp;
        system(tmpc);
        system(tmpc);
    }
}

string helper(string inp){
    if(inp == "-l"){
        for (auto v : helpl)
            printf("%s\n", v.c_str());
        printf("共 %ld 项", helpl.size());
        return "";
    }else if(inp == "-q"){
        now = "";
        return "退出成功.";
    }else{
        if(!checker(helpl, inp)){
            printf("找不到指令: %s\n", inp.c_str());
        }else{
            if(inp == "help"){
                return "帮助指令.";
            }else if(inp == "clear"){
                return "清屏指令, 输入 \"clear\" 可直接使用";
            }else if(inp == "quit"){
                return "退出程序, 输入 \"quit\" 可直接使用";
            }else if(inp == "setc"){
                return "设置输入文件目录和输出目录以编译.\n-h 以手动输入\n-a 设置输入输出文件\n-m 设置多组输入输出\n输入from和to以设置文件格式";
            }else if(inp == "cr"){
                return "编译运行. 如果没有设置输入输出则抛出错误.";
            }
        }
    }
}

void quiter(string inp){
    if(inp == "y"){
        puts("退出成功.");
        exit(0);
        // system("exit");
    }else if(inp == "n"){
        now = "";
        return;
    }else{
        printf("输入非法,请重新输入.\n");
        quiter(input("quit"));
    }
}

int main(){
    init();
    while (true){
        // debug(now);
        string inp = input(now);
        if(inp == "" or inp == "\n" or inp == "\t") continue;
        // if(!checker(, inp)){
        //     printf("在 %s 中找不到指令: %s\n" , now.c_str(), inp.c_str());
        //     puts("输入 help 以查看更多信息");
        // }else{
            if(now == "") {
                if(!checker(command, inp)) commandless("command", inp);
                else print(commander(inp));
            }else if(now == "help") {
                if(!checker(helpl, inp)) commandless("help", inp);
                else print(helper(inp));
            }else if(now == "quit") {
                quiter(inp);
            }
            
            // printf("需要注意的是, 您当前在 %s 指令下操作.\n", ((now == "") ? "基本(basic)" : now).c_str());
        
    }
    return 0;
}