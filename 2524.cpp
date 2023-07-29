#include <cstdio>
#include <algorithm>
using std::sort;
const int N = 1e5 + 10;
typedef unsigned long long llu;
int n;
long long ans[N];
long long ans1[N];
long long midd[N];
long long midd1[N];
struct Node
{
    int idx;
    int x;
    int y;
    int type;
}all[N], tmp[N];
void msort1(int lef, int rig){
    if(lef + 1 == rig)
        return;
    int mid = (lef + rig) / 2;
    msort1(lef, mid);
    msort1(mid, rig);
    int p = 0;
    long long cnt = 0;
    for (int i = lef, j = mid; i < mid or j < rig;)
        if (j == rig or (i < mid and all[i].x < all[j].x)){
            // if(all[i].type) 
            cnt++;
            tmp[p++] = all[i++];
        }else{
            // if(!all[j].type) 
            midd[all[j].idx] += cnt;
            tmp[p++] = all[j++];
        }
    for (int i = 0, j = lef; i < p;)
        all[j++] = tmp[i++];
}
void msort2(int lef, int rig){
    if(lef + 1 == rig)
        return;
    int mid = (lef + rig) / 2;
    msort2(lef, mid);
    msort2(mid, rig);
    int p = 0;
    long long cnt = 0;
    for (int i = lef, j = mid; i < mid or j < rig;)
        if (j == rig or (i < mid and all[i].y > all[j].y)){
            // if(all[i].type) 
            cnt++;
            tmp[p++] = all[i++];
        }else{
            // if(!all[j].type) 
            midd1[all[j].idx] += cnt;
            tmp[p++] = all[j++];
        }
    for (int i = 0, j = lef; i < p;)
        all[j++] = tmp[i++];
}
void msort3(int lef, int rig){
    if(lef + 1 == rig)
        return;
    int mid = (lef + rig) / 2;
    msort3(lef, mid);
    msort3(mid, rig);
    int p = 0;
    long long cnt = 0;
    for(int i = mid; i < rig; i++){
        cnt += midd1[all[i].idx];
    }
    // printf("cnt: %lld \n", cnt);
    for (int i = lef, j = mid; i < mid or j < rig;)
        if (j == rig or (i < mid and all[i].x < all[j].x)){
            // if(!all[i].type) 
            ans[all[i].idx] += cnt;
            tmp[p++] = all[i++];
        }else{
            // if(all[j].type) 
            cnt -= midd1[all[j].idx];
            tmp[p++] = all[j++];
        }
    for (int i = 0, j = lef; i < p;)
        all[j++] = tmp[i++];
}
void msort4(int lef, int rig){
    if(lef + 1 == rig)
        return;
    int mid = (lef + rig) / 2;
    msort4(lef, mid);
    msort4(mid, rig);
    int p = 0;
    long long cnt = 0;
    // for(int i = mid; i < rig; i++){
    //     if(all[i].type) cnt += midd1[all[i].idx];
    // }
    for(int i = mid; i < rig; i++){
        cnt += midd[all[i].idx];
    }
    for (int i = lef, j = mid; i < mid or j < rig;)
        if (j == rig or (i < mid and all[i].y > all[j].y)){
            // if(!all[i].type) 
            ans1[all[i].idx] += cnt;
            tmp[p++] = all[i++];
        }else{
            // if(all[j].type) 
            cnt -= midd[all[j].idx];
            tmp[p++] = all[j++];
        }
    for (int i = 0, j = lef; i < p;)
        all[j++] = tmp[i++];
}
bool cmp(Node a, Node b){
    // if(a.idx == b.idx) return a.type < b.type;
    return a.idx < b.idx;
}
// bool cmp2(Node a, Node b){
//     return a.idx > b.idx;
// }
// bool cmp2(Node a, Node b){
//     if(a.idx == b.idx) return a.type < b.type;
//     return a.idx > b.idx;
// }
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
        all[i] = (Node){i, read(), read(), 1};
        // all[i + n] = (Node){i, all[i].x, all[i].y, 0};
    }
    sort(all + 1, all + 1 + n , cmp);
    msort1(1 , n  + 1);
    sort(all + 1, all + 1 + n , cmp);
    msort2(1 , n  + 1);
    sort(all + 1, all + 1 + n , cmp);
    msort3(1 , n  + 1);
    sort(all + 1, all + 1 + n , cmp);
    msort4(1 , n  + 1);
    for (int i = 1; i <= n; i++){
        printf("%lld %lld %lld\n", ans[i], ans1[i], midd[i] * midd1[i]);
    }
    return 0;
}