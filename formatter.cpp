// head
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
#define quiter() if(i > (int)line[k].size()) break
using std::cin;
using std::getline;
using std::string;
using std::vector;
using std::map;
using std::unordered_map;

// var
const int N = 5e5 + 5;
string inp = "something", code = "", done = "", ans[N], line[N];
string fuhao = "+-*/%=>><<&&||^?:";
int cnt = 0;

struct Stack{
    int s[N], ps;
    inline void push(int x){s[++ps] = x;}
    inline int top(){return s[ps];}
    inline void pop(){s[ps--] = 0;}
}jian;

// func

void trim(string &s){
    if(!s.empty()){
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
}

void input(){
    while(inp != ""){
        std::getline(cin, inp);
        trim(inp);
        code += inp + '\n';
        line[++cnt] = inp;
    }
}

void output(string &result){
    std::cout << result;
}

void spfu(int i, char x, char y, int k){ 
    if(line[k][i] == x && line[k][i + 1] == y){ 
        if(line[k][i - 1] != ' ') ans[k] += ' ';
        ans[k] += x + y;
        if(line[k][i + 2] != ' ') ans[k] += ' ';
    }else if(line[k][i - 1] == x && line[k][i] == y){ 
        // i += 2;
        i++; 
    }
}

void nofu(int i, char x, int k){
    if(line[k][i - 1] != ' '){
        ans[k] += ' ';
    }
    if(line[k][i] == x){
        ans[k] += x;
    }
    if(line[k][i + 1] != ' '){
        ans[k] += ' ';
    }
}

void direct(int i, char x, int k){
    if(line[k][i] == x){
        ans[k] += x;
    }
}

void work(){
    // for (auto v : line[k]){
    //     if(v != ' ' && v != '\n')
    //         nospace += v;
    // }
    for (int k = 1; k <= cnt; k++){
        for (int i = 0; i < (int)line[k].size(); i++){
            while(i < (int)line[k].size() && line[k][i] == ' ') i++;
            if(line[k][i] == '#'){
                if(line[k].substr(i + 1, 7) == "include"){
                    ans[k] += "#include ";
                    // i += 8;
                    i += 7;
                }else if(line[k].substr(i + 1, 6) == "define"){
                    ans[k] += "#define ";
                    // i += 7;
                    i += 6;
                }
                // quiter();
                if(line[k][i] == '<'){
                    ans[k] += '<';
                    jian.push(i);
                }
            }
            // quiter();
            if(fuhao.find(line[k][i]) != std::string::npos){
                for(char a : {'<', '>', '&', '|'}){
                    spfu(i, a, a, k);
                    quiter();
                }
                for(std::string a : {"<=", ">=", "!="}){
                    spfu(i, a[0], a[1], k);
                    quiter();
                }
                if(line[k][i] == '>'){
                    if(jian.top()){
                        ans[k] += '>';
                        jian.pop();
                    }else{
                        ans[k] += " > ";
                    }
                }
                for (char a : {'<', '+', '-', '*', '/', '=', '%', '^', '?', ':', '~'}){
                    nofu(i, a, k);
                    quiter();
                }
            }
            if((line[k][i] >= 65 && line[k][i] <= 90) || (line[k][i] >= 97 && line[k][i] <= 122)){
                ans[k] += line[k][i];
            }
            for (char a : {';', '{', '}', '(', ')'}){
                direct(i, a, k);
            }
        }
    }
    for (int i = 1; i <= cnt; i++){
        
    }
}

int main(){
    input();
    work();
    // output(done);
    
    return 0;
}