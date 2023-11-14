#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
using std::string;
const int N = 3e5 + 5;
int n, m, ans;
char rd[N];
string str;
void read(string& x){
    scanf("%s", rd), x = rd;
}
int main(){
    scanf("%d%d", &n, &m);
    read(str);
    for (int i = 0; i < (int)str.size(); i++)
        if(i && str[i] == str[i - 1] && str[i] == '.') ans++;
    for (int i = 1, x; i <= m; i++){
        char c;
        std::cin >> x >> c, x--;
        if(str[x] != '.' && c == '.') {
            str[x] = '.';
            if(x > 0 && str[x] == str[x - 1]) ans++;
            if(x < (int)str.size() - 1 && str[x] == str[x + 1]) ans++;
        }else if(str[x] == '.' && c != '.'){
            if(str[x] == str[x - 1]) if(x > 0 && c != str[x - 1]) ans--;
            if(str[x] == str[x + 1]) if(x < (int)str.size() - 1 && c != str[x + 1]) ans--;
            str[x] = c;
        }
        printf("%d\n", ans);
    }
    return 0;
}