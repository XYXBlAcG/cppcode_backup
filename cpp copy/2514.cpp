#include <cstdio>
#include <algorithm>
const int N = 1010;
typedef long long ll;
ll u[N][N];
struct Node
{
    ll idx;
    ll val;
}sm[N * N], bi[N * N] , ans[N * N];
ll bl, sl;
Node *s = sm;
Node *b = bi;
ll reset = 0;
ll cnt[N * N];
bool mi(const Node& a, const Node& b){
    return a.val > b.val;
}
// ll ans[N * 5];
ll n;
inline ll read() {
    ll x = 0, w = 1;
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
        for (int j = 1; j <= n; j++){
            u[i][j] = read();
        }
        // u[i][n + 1] = 1e9 + 10;
    }
    for (int j = 1; j <= n; j++){
        b[++bl] = (Node){j, u[j][1]};
    }
    ll leng = 0;
    ll past = 0;
    std::make_heap(b + 1, b + bl + 1, mi);
    for (int i = 1; i <= n * n; i++){
        if(bl == 0){
            reset++;
            std::swap(s, b);
            std::swap(sl, bl);
        }
        ll tmp = b[1].idx;
        ans[++leng] = (Node){tmp, ++cnt[tmp]};
        past = b[1].val;
        std::pop_heap(b + 1, b + bl-- + 1, mi);
        if(cnt[tmp] < n){
            if(u[tmp][cnt[tmp] + 1] >= past){
                b[++bl] = (Node){tmp, u[tmp][cnt[tmp] + 1]};
                std::push_heap(b + 1, b + bl + 1, mi);
            }else{
                s[++sl] = (Node){tmp, u[tmp][cnt[tmp] + 1]};
                std::push_heap(s + 1, s + sl + 1, mi);
            }
        }
    }
    printf("%lld\n", reset);
    for (int i = 1; i <= leng; i++){
        printf("%lld %lld\n", ans[i].idx, ans[i].val);
    }
    return 0;
}