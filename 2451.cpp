#include <cstdio>
#include <algorithm>
using std::min;
using std::sort;
using std::abs;
const int N = 1e3 + 5;
int n, m;
struct Node
{
    int idx;
    int val;
}f[2][N * N];
int f2[2][N * N];
// int f[2][N * 2];
int num[2][N * N];
int f2n[2][N * N];
int jlen[5];
int ji[5][N];
bool cmp(const Node& a, const Node& b){
    return a.val < b.val;
}
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
    // scanf("%d",&n);
    for (int i = 1; i <= 4; i++){
        jlen[i] = read();
        for (int j = 1; j <= jlen[i]; j++){
            ji[i][j] = read();
        }
    }
    int cnt1 = 0;
    for (int i = 1; i <= jlen[1]; i++){
        for (int j = 1; j <= jlen[2]; j++){
            ++cnt1;
            f[0][cnt1].idx = cnt1;
            f[0][cnt1].val = ji[1][i] + ji[2][j];
        }
    }
    int cnt2 = 0;
    for (int i = 1; i <= jlen[3]; i++){
        for (int j = 1; j <= jlen[4]; j++){
            ++cnt2;
            f[1][cnt2].idx = cnt2;
            f[1][cnt2].val = ji[3][i] + ji[4][j];
        }
    }
    m = read();
    int min1 = 1e9;
    long long cnt = 0;
    int tmp = 0;
    sort(f[0] + 1, f[0] + cnt1 + 1, cmp);
    sort(f[1] + 1, f[1] + cnt2 + 1, cmp);
    for (int i = 1; i <= cnt1; i++){
        if(f[0][i].val != f[0][i - 1].val){
            ++tmp;
        }
        f2n[0][f[0][i].idx] = tmp;
        num[0][tmp]++;
    }tmp = 0;
    for (int i = 1; i <= cnt2; i++){
        if(f[1][i].val != f[1][i - 1].val){
            ++tmp;
        }
        f2n[1][f[1][i].idx] = tmp;
        num[1][tmp]++;
    }
    // for (int i = 1; i <= cnt1; i++){
    //     printf("f2n:%d ",f2n[0][f[0][i].idx]);
    //     printf("num:%d \n",num[0][f2n[0][f[0][i].idx]]);
    // }
    // for (int i = 1; i <= cnt2; i++){
    //     printf("f2n:%d ",f2n[1][f[1][i].idx]);
    //     printf("num:%d \n",num[1][f2n[1][f[1][i].idx]]);
    // }

    // for (int i = 1; i <= cnt1; i++){
    //     printf("f:%d \n",f[0][i].val);
    // }
    // for (int i = 1; i <= cnt2; i++){
    //     printf("f:%d \n",f[1][i].val);
    // }
    int tmp1 = 1e9 + 8;
    // int flag1 = 0, minb = 1;
    int ansi = 0, ansj = 0;
    for (int i = 1, j = cnt2; i <= cnt1 && j > 0;){
        // for (int j = cnt2; j > 0;){
            int numi = num[0][f2n[0][f[0][i].idx]];
            int numj = num[1][f2n[1][f[1][j].idx]];
            int ii = f[0][i].val;
            int jj = f[1][j].val;
            while(ii == f[0][i - 1].val){
                i++;
                numi = num[0][f2n[0][f[0][i].idx]];
                ii = f[0][i].val;
            }
            while(jj == f[1][j + 1].val){
                j--;
                numj = num[1][f2n[1][f[1][j].idx]];
                jj = f[1][j].val;
                // continue;
            }
            min1 = min(abs(ii + jj - m), min1);
            // printf("numi: %d ",numi);
            // printf("numj: %d ",numj);
            // printf("ii: %d ",ii);
            // printf("jj: %d ",jj);
            // printf("cnt1: %d ",cnt);
            
            if(tmp1 != min(tmp1, min1)){
                tmp1 = min1;
                cnt = 0;
                ansi = ii;
                ansj = jj;
            }
            if(abs(ii + jj - m) == min1){
                cnt += 1ll * numi * numj;
            }
            
            // printf("cnt2: %d \n",cnt);
            if(ii + jj > m){
                j--;
            }else if(ii + jj <= m){
                i++;
            }
        // }
        // i++;
    }
    printf("%d ", ansi + ansj);
    printf("%lld ", cnt);
    return 0;
}