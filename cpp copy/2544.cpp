#include <cstdio>
#include <algorithm>
const int N = 1e6 + 10;
typedef long long ll;
ll n, m; int result = 0;
struct Node
{
    int idx;
    ll val;
}pos[N], tmp[N], tmp2[N];
ll sum[N];
bool cmp(const Node& a, const Node& b){
    return a.val < b.val;
}
bool cal(ll z){
    for (int i = 1; i <= n; i++){
        pos[i] = tmp2[i];
        // sum[i] = 0;
    }
    int cnt = 1; ll dig = 0;
    while (cnt <= n){
        int l = tmp[cnt].idx - 1, r = tmp[cnt].idx + 1;
        while((pos[l].val - pos[l + 1].val) > z && l >= 1){
            dig += pos[l].val - pos[l + 1].val - z;
            pos[l].val = pos[l + 1].val + z;
            --l;
        }
        while(pos[r].val - pos[r - 1].val > z && r <= n){
            dig += pos[r].val - pos[r - 1].val - z;
            pos[r].val = pos[r - 1].val + z;
            ++r;
        }
        cnt++;
    }if(dig > m) return 0;
    int l = 1, r = 1; 
    for (int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + pos[i].val;
    }
    for (int i = 1; i <= n; i++){
        while(pos[l].val < (ll)((ll)(i - l) * z) && l < i) {
            // dig -= (i - l) * z - pos[l].val;
            // dig -= (mem[l] - l) * z - pos[l].val;
            l++; 
            // llen++;
        }
        while(pos[r + 1].val >= (ll)((ll)(r - i + 1) * z) && r < n) {
            // dig += pos[r].val - (r - i) * z;
            // mem[r] = i; 
            r++; 
            // dig += pos[r].val - ((r - i) * z);
            // rlen++;
        }
        // unsigned long long aaa = (unsigned long long)dig;
        // aaa -= (ll)(1ll * ((i - l) * (ll)(i - l + 1) >> 1) * z + (ll)(1ll * (r - i) * (ll)(r - i + 1) >> 1) * z);
        // aaa += sum[r] - sum[l - 1];
        // if(aaa >= m){
        //     result = i;
        //     return 1;
        // }
        if(dig 
        + sum[r] - sum[l - 1] 
        - (1ll * ((i - l) * (i - l + 1) >> 1) * z + (1ll * (r - i) * (r - i + 1) >> 1) * z) <= m) 
        {result = i; 
        return 1;}
    }

    return 0;
}
inline ll read() {
    ll x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时
        x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
        // x 是 ll 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
        // ASCII 码，相当于将 ch 转化为对应数字
        // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
        ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}
int main(){
    n = read(); m = read(); 
    for (int i = 1; i <= n; i++){
        tmp2[i] = tmp[i] = pos[i] = (Node){i, read()};
    }std::sort(tmp + 1, tmp + 1 + n, cmp);
    ll l = 0, r = 1e18;
    while(l < r){
        ll mid = (l + r) >> 1;
        if(!cal(mid)) l = mid + 1; 
        else r = mid;
    }// if(!result) result++;
    // printf("%d\n", cal(1)); printf("%d\n", cal(2)); printf("%d\n", cal(3));
    printf("%d \n", result);
    printf("%lld \n", l);
    return 0;
}

// for (int i = 1; i <= n; i++) {
//     ll h = pos[i].val, res = dig;
//     int l = i - 1, r = i + 1; 
//     for(;l > 1 && pos[l].val > pos[l + 1].val && h > 0; h--)
//     for(;r < n && pos[r].val < pos[r + 1].val && h > 0; h--)
//     res += pos[i].val * (r - l);
//     if(res <= m) {result = i; return 1;}
// }

// for (int i = 1; i <= n; i++){
//     printf("%lld ",pos[i].val);
//     sum[i] = sum[i - 1] + pos[i].val;
// }printf(" pass\n");
// int l = 0, r = 1; 
// for (int i = 1; i <= n; i++){
//     ll h = pos[i].val, res = dig;
//     while(pos[l].val > (i - l) * z + h && l <= i){++l;}
//     while(pos[r].val < (r - i) * z + h && r <= n){++r;}
//     // if(pos[i].val < pos[l].val) 
//         res += sum[i] - sum[l - 1] - ((i - l) * ((i - l) * (z)) >> 1);
//     // if(pos[r].val > pos[i].val) 
//         res += sum[r] - sum[i] - ((r - i) * ((r - i) * (z)) >> 1);
//     if(res <= m) {result = i; 
//         for (int j = 1; j <= n; j++){
//             printf("%lld ",pos[j].val);
//         }printf(" true "); printf("z:%lld\n", z);
//     return 1;}
// }return 0;

// for (int j = 1; j <= n; j++){
//         printf("%lld ",pos[j].val);
//     }printf(" true "); printf("z:%lld\n", z);

// int l = tmp[cnt].idx, r = l;
// while(abs(pos[l - 1].val - pos[l].val) > z && l >= 1){
//     dig += std::max(pos[l - 1].val, pos[l].val) - std::min(pos[l - 1].val, pos[l].val) - z;
//     if(pos[l - 1].val > pos[l].val){
//         pos[l - 1].val = pos[l].val + z;
//     }else{
//         pos[l].val = pos[l - 1].val + z;
//     }l--;
// }
// while(abs(pos[r + 1].val - pos[r].val) > z && r <= n){
//     dig += std::max(pos[r + 1].val, pos[r].val) - std::min(pos[r + 1].val, pos[r].val) - z;
//     if(pos[r + 1].val > pos[r].val){
//         pos[r + 1].val = pos[r].val + z;
//     }else{
//         pos[r].val = pos[r + 1].val + z;
//     }r++;
// }cnt++;

// for (int i = 1; i < n; i++) {
    //     dig += std::max((ll)0, pos[i + 1].val - pos[i].val - z);
    //     pos[i + 1].val = std::min(pos[i + 1].val, pos[i].val + z);
    // }

    // for (int i = n; i > 1; i--) {
    //     dig += std::max((ll)0, pos[i - 1].val - pos[i].val - z);
    //     pos[i - 1].val = std::min(pos[i - 1].val, pos[i].val + z);
    // }

    // while(llen){
        //     dig -= (i - llen) * z - pos[i - llen].val; llen--;
        // }
        // while(rlen){
        //     dig += (rlen - i) * z - pos[rlen - i].val; rlen--;
        // }
        // printf("%d %d\n", l, r);