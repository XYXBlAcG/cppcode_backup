#include <cstdio>
#include <algorithm>
#include <string>
typedef unsigned long long llu;
int n, m;
const int N = 100010;
struct Node
{
    std::string str;
    int idx;
}dic[N];
int bin(std::string x){// min in big
    int l = 1, r = n, mid;
    while(l < r){
        mid = (l + r) >> 1;
        if(dic[mid].str < x){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    return l;
}
bool cmp(const Node& a, const Node& b){
    if(a.str != b.str) return a.str < b.str;
    return a.idx < b.idx;
}
char tmp[20];
inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时
        x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
        // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
        // ASCII 码，相当于将 ch 转化为对应数字
        // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
        ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}
int main(){
    n = read();
    for (int i = 1; i <= n; i++){
        scanf("%s",tmp);
        dic[i] = (Node){tmp, read()};
    }
    std::sort(dic + 1, dic + 1 + n, cmp);
    m = read();
    for (int i = 1; i <= m; i++){
        scanf("%s",tmp);
        printf("%d\n", dic[bin(tmp)].idx);
    }
    return 0;
}