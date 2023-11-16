#include <cstdio>
#include <algorithm>
#include <string>
using std::string;
const int N = 1e5 + 5;
string str;
char ch[N];
int ans = 1;
int main(){
    scanf("%s", ch), str = ch, str.append(str);
    int cnt = 1;
    for (int i = 1; i < (int)str.size(); i++){
        if(str[i - 1] != str[i]){
            cnt++;
            ans = std::max(ans, cnt);
        }else cnt = 1;
    }
    printf("%d\n", std::min((int)str.size() >> 1, ans));
    return 0;
}