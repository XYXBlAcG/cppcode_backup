#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using std::ifstream;
using std::cin;
using std::string;
const int N = 1e5 + 5;
string ign = "lbumwterhndckg";
// string p[5] = {"", "", "", "", ""};
string pc = (string)" " + " " + "s" + "p" + " ";
// char pc[5] = {' ', ' ', ' ', ' ', ' '};
char ch[5] = {' ', 'a', ' ', ' ', 's'};
int n = 5757;
string word[N];
int main() {
    int i = 1;
    ifstream fin("sgb-words.txt");
    while (getline(fin, word[i])) i++;
    for (int i = 1; i <= n; i++) {
        int flag = 0;
        for (int j = 0; j < 5; j++) {
            for (auto v : ign){
                if (word[i][j] == v) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) break;
        }
        if (flag == 1) continue;
        for (int k = 0; k < 5; k++){
            char v = pc[k];
            if(v == ' ') continue;
            int fi = 0;
            for (int j = 0; j < 5; j++){
                if(word[i][j] == v && k == j) break;
                if(word[i][j] == v && k != j) fi = 1;
            }
            if(fi == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) continue;
        for (int j = 0; j < 5; j++) {
            if (ch[j] == ' ') continue;
            if (ch[j] != word[i][j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) continue;
        std::cout << word[i] << '\n';
    }
    
    return 0;
}