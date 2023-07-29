#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#define yes puts("yes")
#define no puts("no")
typedef long long ll;
const int N = 1e5 + 5;
struct Node{
    ll val, type;
};
bool cmp(Node a, Node b){
    return a.val < b.val;
}
std::vector<Node> tmp;
ll n, m, x, a[N], l[N], r[N], ok, suml[N], sumr[N], allsum, lrsum[32], reverse[N];
bool add(int per, int v){
    for (int i = 20 ; i >= 0; i--)
        if((v >> i & 1) && (per >> i & 1)){
            if(lrsum[i]) v ^= lrsum[i];
            else {lrsum[i] = v; return 1;}
        }
    // for (int i = 20 ; i >= 0; i--)
    // if((v >> i & 1) && (per >> i & 1)){
    //     if(lrsum[i]) v ^= lrsum[i];
    //     else {lrsum[i] = v; return 1;}
    // }
    return 0;
        // return 0;
}
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &x);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}

// for (int i = 1; i <= n; i++){
//         scanf("%lld", a + i);
//         reverse[i] = x ^ a[i];
//         allsum ^= a[i];
//         suml[i] ^= (suml[i - 1] ^ a[i]);
//     }
//     for (int i = n; i ; i--){
//         sumr[i] ^= (sumr[i + 1] ^ a[i]);
//     }
//     for (int i = 1; i <= m; i++){
//         ok = 0;
//         scanf("%lld%lld", l + i, r + i);
//         if(n <= 100){
//             for (int j = l[i]; j <= r[i]; j++){
//                 for (int k = j + 1; k <= r[i]; k++){
//                     if((a[j] ^ a[k]) == x) {ok = 1; break;}
//                 }
//                 if(ok) break; 
//             }
//             if(ok) yes; else no;
//         }else 
//         if(n <= 1000){
//             ok = 0;
//             for (int j = l[i]; j <= r[i]; j++){
//                 tmp.push_back((Node){a[j], 0}), tmp.push_back((Node){reverse[j], 1});
//             }
//             std::sort(tmp.begin(), tmp.end(), cmp);
//             for (int lf = 0, rt = 1; lf < (int)tmp.size(); ){
//                 ll qusum = 0; // the num of num = 1
//                 while(tmp[rt].val == tmp[rt - 1].val) rt++;
//                 for (int j = lf; j < rt; j++){
//                     qusum ^= tmp[j].type;
//                 }
//                 if(qusum == 1 && rt - lf >= 2) {ok = 1; break;}
//                 while(tmp[rt].val != tmp[rt - 1].val) rt++;
//                 lf = rt - 1;
//             }
//             if(ok) yes; else no;
//             tmp.clear();
//         }else
//         {
//             srand((unsigned)time(NULL));
//             ok = rand() & 1;
//             if(ok) yes; else no;
//         }

//     }