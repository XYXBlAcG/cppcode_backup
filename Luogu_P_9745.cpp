#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 1e5 + 5, mod = 998244353;
int n, v[N];
std::vector<int> st[N];
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", v + i);
    for (int i = 1, f; i <= n; i++)
        scanf("%d", &f), st[f].push_back(i), st[i].push_back(f);
    for (int i = 1; i <= n; i++){
        
    }
    return 0;
}