#include <cstdio>
#include <vector>
const int N = 1e6 + 5;
int n, m;
std::vector<int> st[N];
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        int a;
        scanf("%d", &a);
        st[a].push_back(i);
    }
    for (int i = 1; i <= n; i++){
        printf("%d ", (int)st[i].size());
        for (auto v : st[i]){
            printf("%d ", v);
        }putchar('\n');
    }
    return 0;
}