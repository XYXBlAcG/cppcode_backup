#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
using std::string;
const int N = 1e5 + 5;
char rd[N];
void read(string& x){scanf("%s", rd), x = rd;}
string str;
int n;
bool chk(int x){
    int cur = -1, cv = -1;
    for (int i = 0; i < (int)str.size(); i++){
        char v = str[i];
        if(v == '*' && cv < i && cur == -1) cur = i;
        if(v == 'P'){
            if(cur == -1) {
                cv = i + x;
                continue;
            }
            int dis = i - cur;
            if(dis > x) return 0;
            if(dis * 3 < x)
                cv = i + (x - dis * 2);
            else
                cv = i + (x - dis) / 2;
            cur = -1;
        }
    }
    return (cur == -1);
}
int bin(){
    int l = 0, r = 2 * n + 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(chk(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
int main(){
    scanf("%d", &n);
    read(str);
    printf("%d\n", bin());
    return 0;
}