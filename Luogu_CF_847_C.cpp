#include <cstdio>
#include <algorithm>
#include <vector>
#define int long long
int n, k;
std::vector<char> ans;
std::vector<int> st;
signed main(){
    scanf("%lld%lld", &n, &k);
    int dep = 0;
    if(k > n * (n - 1) / 2) return puts("Impossible"), 0;
    while(k){
        if(k - dep < 0) ans.push_back(')'), st.pop_back(), dep--, n--;
        else ans.push_back('('), st.push_back(1), k -= dep, dep++;
    }
    for (int i = 0; i < (int)st.size(); i++){ans.push_back(')'), n--;}
    for (int i = 1; i <= n; i++) ans.push_back('('), ans.push_back(')');
    for (auto v : ans)
        printf("%c", v);
    putchar('\n');
    return 0;
}