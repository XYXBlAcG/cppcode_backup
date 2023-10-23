#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <random>
#include <map>
#include <string>
#include <iostream>
using std::string;
const int N = 1e5 + 5;
std::mt19937 frand(114514);
int ran(int a, int b){
    return frand() % (b - a + 1) + a;
}
std::map<string, int> ma;
std::vector<string> type;
std::map<string, int> Tp;
std::vector<string> query;
string gens(){
    int u = ran(1, 10);
    string str = "";
    do{
        str = "";
        for (int i = 1; i <= u; i++){
            str += (char)ran('a', 'z');
        }
    }while(ma.find(str) != ma.end());
    return str;
}
string rander(){
    int u = ran(1, 10);
    string tmp = "";
    for (int i = 1; i <= u; i++){
        tmp += (char)ran('a', 'z');
    }
    return tmp;
}
string gent(){
    int u = ran(1, 10);
    string str = "";
    do{
        str = "";
        for (int i = 1; i <= u; i++){
            str += (char)ran('a', 'z');
        }
    }while(Tp.find(str) != Tp.end());
    return str;
}



int main(){
    freopen("smake.in", "r", stdin);
    freopen("smake.out", "w", stdout);
    int n = 100;
    type.push_back("int");
    type.push_back("short");
    type.push_back("byte");
    type.push_back("long");
    for (auto v : type){
        Tp[v] = 1;
    }
    for (int i = 1; i <= n; i++){
        int op = ran(1, 4);
        if(op != 3) printf("%d ", op);
        if(op == 1){
            string str = gens();
            int k = 100;
            std::cout << str << ' ' << k << '\n';
            for (int j = 1; j <= k; j++){
                int v = ran(1, (int)type.size());
                string typ = type[v - 1];
                Tp[typ] = 2;
                string tmp = rander();
                std::cout << typ << ' ' << tmp << '\n';
            }
        }else if(op == 2){
            string str = gent();
            string tmp = rander();
            std::cout << str << ' ' << tmp << '\n';
        }else if(op == 3){
            i--;
        }else{
            printf("%d\n", ran(1, 100));
        }
    }
    return 0;
}