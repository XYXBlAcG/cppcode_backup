// head
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>

#define quiter() if(i > (int)line[k].size()) break
#define debug(x, y) std::cout << "当前处理的是: k = " << x << " , i = " << y << " 的 字符\'" << line[x][y] << "\', 连着的三个字符为: \"" << line[x][y - 1] << line[x][y] << line[x][y + 1] << "\"" << std::endl
#define debug2(x, y) std::cout << "当前处理的是: k = " << x << " , i = " << y << " 的 字符\'" << line[x][y] << "\', 连着的二个字符为(前): \"" << line[x][y - 1] << line[x][y] << "\"" << std::endl
#define debug3(x, y) std::cout << "当前处理的是: k = " << x << " , i = " << y << " 的 字符\'" << line[x][y] << "\', 连着的二个字符为(后): \"" << line[x][y] << line[x][y + 1] << "\"" << std::endl
#define debug4(x) std::cout << "进过处理后的本行答案为: \"" << ans[x] << "\"" << std::endl

using std::cin;
using std::getline;
using std::string;
using std::vector;
using std::map;
using std::unordered_map;

// var
const int N = 1e6 + 5;
string inp = "something", code = "", done = "", ans[N], line[N];
string fuhao = "+-*/%=>><<&&||^?:";
int cnt = 0, suojin[N], flagForTwo;

struct Stack{
    int s[N], ps;
    inline void push(int x){s[++ps] = x;}
    inline int top(){return s[ps];}
    inline void pop(){s[ps--] = 0;}
}jian, qut, bigg;

// func

void trim(string &s){
    if(!s.empty()){
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
    }
}

void input(){
    while(inp != "end"){
        std::getline(cin, inp);
        if(inp == "end") break;
        trim(inp);
        code += inp + '\n';
        line[++cnt] = inp;
    }
}

void output(string &result){
    std::cout << result;
}

void spfu(int& i, char x, char y, int k){ 
    // std::cout << "处理 i = " << i << " , 字符 = \'" << line[k][i] << "\' 的时候使用了 spfu\n";
    if(line[k][i] == x && line[k][i + 1] == y){ 
        if(line[k][i - 1] != ' ') ans[k] += ' ';
        ans[k] += x;
        ans[k] += y;
        if(line[k][i + 2] != ' ') ans[k] += ' ';
        flagForTwo = 1;
        i++;
        // i += 2;
    }
    else if(line[k][i - 1] == x && line[k][i] == y){ 
        // i += 2;
        // i++;
        flagForTwo = 0;
    }
}

void nofu(int i, char x, int k){
    if(line[k][i - 1] != ' ' && ans[k].back() != ' '){
        ans[k] += ' ';
    }
    if(line[k][i] == x){
        ans[k] += x;
    }
    if(line[k][i + 1] != ' ' && ans[k].back() != ' '){
        ans[k] += ' ';
    }
    i++;
    // i += 2;
}

void direct(int i, char x, int k){
    if(line[k][i] == x){
        ans[k] += x;
    }
}

void fenhao(int i, int k){
    if((int)line[k].size() - 1 == i) ans[k] += ";";
    else{
    // if((int)line[k].size() - 1 != i){
        if(line[k][i + 1] == ' ') ans[k] += ';';
        else ans[k] += "; ";
    }
}

void douhao(int i, int k){
    if(line[k][i - 1] == ' ' && ans[k].back() == ' '){
        ans[k].pop_back();
        // ans[k] += ' ';
    }
    if(line[k][i] == ','){
        ans[k] += ',';
    }
    if(line[k][i + 1] != ' ' && ans[k].back() != ' '){
        ans[k] += ' ';
    }
}

void work(){
    // for (auto v : line[k]){
    //     if(v != ' ' && v != '\n')
    //         nospace += v;
    // }
    for (int k = 1; k <= cnt; k++){
        for (int i = 0; i < (int)line[k].size(); i++){
            // if(i == 0) debug3(k, i);
            // else if(i == (int)line[k].size() - 1) debug2(k, i);
            // else debug(k, i);
            // while(i < (int)line[k].size() && line[k][i] == ' ') i++;
            // if(line[k][i] == )
            // if(line[k].back() == ' ') break;
            if(line[k][i] == ' ' && ans[k].back() != ' ') ans[k] += ' ';

            // if(line[k][i] == '#'){
            //     if(line[k].substr(i + 1, 7) == "include"){
            //         ans[k] += "#include ";
            //         // i += 8;
            //         i += 7;
            //     }else if(line[k].substr(i + 1, 6) == "define"){
            //         ans[k] += "#define ";
            //         // i += 7;
            //         i += 6;
            //     }
            //     // quiter();
            //     if(line[k][i] == '<'){
            //         ans[k] += '<';
            //         jian.push(i);
            //     }
            // }
            // quiter();
            
            if(fuhao.find(line[k][i]) != std::string::npos){
                for (string a : {"//", "/*", "*/"}){

                }
                for(char a : {'<', '>', '&', '|', '+', '-', '='}){
                    if(line[k][i] == a) spfu(i, a, a, k);
                    // quiter();
                }
                for(std::string a : {"<=", ">=", "!="}){
                    if((line[k][i] == a[0] && line[k][i + 1] == a[1]) || (line[k][i - 1] == a[0] && line[k][i] == a[1]))
                        spfu(i, a[0], a[1], k);
                    // quiter();
                }
                if(line[k][i] == '>' && !flagForTwo){
                    if(jian.top()){
                        ans[k] += '>';
                        jian.pop();
                    }else{
                        ans[k] += " > ";
                    }
                }
                if(!flagForTwo){
                    for (char a : {'<', '+', '-', '*', '/', '=', '^', '?', ':', '~'}){
                        nofu(i, a, k);
                        // quiter();
                    }
                }
            }
            if((line[k][i] >= 65 && line[k][i] <= 90) || (line[k][i] >= 97 && line[k][i] <= 122) || (line[k][i] >= 48 && line[k][i] <= 57)){
                ans[k] += line[k][i];
            }
            if(line[k][i] == ';') fenhao(i, k);
            if(line[k][i] == ',') douhao(i, k);
            for (char a : {'{', '}', '(', ')', '.', '_', '$', '@', '!', '\'', '%', '&'}){
                direct(i, a, k);
            }
            if(line[k][i] == '"'){
                i++;
                ans[k] += '"';
                while(line[k][i] != '"'){
                    ans[k] += line[k][i];
                    i++;
                }
                ans[k] += line[k][i];
            }
            // debug4(k);
        }
    }

    // memset(suojin, -1, sizeof(suojin));

    for (int i = 1; i <= cnt; i++){
        // int flag = 0;

        trim(ans[i]);

        int ssize = ans[i].size();
        if(suojin[i] == 0) suojin[i] = suojin[i - 1];
        for (int j = 0; j < ssize; j++){
            // int hang = 0;
            // if((ans[i][j] != ' ') && (flag == 1)){
            //     // ans[i][j] = '\n' + ans[i][j];
            //     ans[i].insert(j, "\n");
            //     flag = 0;
            // }
            if(ans[i][j] == '{'){
                bigg.push(i);
                if(ans[i].find('}') != string::npos) {suojin[i] = suojin[i - 1]; printf("the same line {}\n");}
                else {suojin[i + 1] = suojin[i] + 4; printf("modify + 4\n");}
                // flag = 1;
                // if(j < (int)ans[i].size() - 1){
                //     ans[i].insert(j, "\n");
                // }else{
                //     ans[i] += '\n';
                // }
                // hang = 1;
            }else if(ans[i][j] == '}'){
                int az = bigg.top();
                // hang = 1;
                if(az == i) continue;
                else suojin[i] = suojin[az];
            }
            // if(hang == 0) suojin[i] = suojin[i - 1];
        }
        // printf("so far %d\n", i);
        //     for (int k = 1; k <= i; k++){
        //         printf("suojin[%d] = %d\n", k, suojin[k]);
        //     }printf("end\n");
        if(ans[i].back() == ';' or ans[i].back() == '{' or ans[i].back() == '}') ans[i] += '\n';
    }

    // for (int i = 1; i <= cnt; i++){
    //     printf("suojin[%d] = %d\n", i, suojin[i]);
    // }

    for (int i = 1; i <= cnt; i++){
        string tmp = string(suojin[i], ' ');
        ans[i] = tmp + ans[i];
    }

    for (int i = 1; i <= cnt; i++){
        done += ans[i];
    }
}

int main(){
    input();
    work();
    output(done);
    
    return 0;
}