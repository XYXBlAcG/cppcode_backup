#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
typedef double d;
const int N = 5e5 + 5;
d ans = 0;
std::string str;
char ch[N];
bool chk(char x){
    return (x == 'I' || x == 'E' || x == 'A' || x == 'O' || x == 'U' || x == 'Y');
}
int main(){
    scanf("%s", ch), str = ch;
    int i = 0, n = str.size();
    for (auto v : str){
        if(chk(v)){
            ans += (d)i * (d)(n - i + 1) / (d)n;
        }
        i++;
    }
    printf("ans = %lf\n", ans);
    return 0;
}