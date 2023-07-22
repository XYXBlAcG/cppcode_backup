#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
const int N = 1e5 + 5;
int n, m, in[N];
int q[N], pq = 0;
std::vector<int> st[N];
bool cmp(int a, int b) {
    return a < b;
}
void toposort() {
    std::vector<int> l;
    pq = 0;
    for (int i = 1; i <= n; i++)
        if (in[i] == 0){
            q[++pq] = i;
        }
    std::make_heap(q + 1, q + 1 + pq, cmp);
    while (pq) {
        int u = q[1];
        std::pop_heap(q + 1, q + pq-- + 1, cmp);
        l.push_back(u);
        for (auto v : st[u]) {
            if (--in[v] == 0) {
                q[++pq] = v;
                std::push_heap(q + 1, q + 1 + pq, cmp);
            }
        }
    }
    if (l.size() == n) {
        for (int j = l.size() - 1; j >= 0; j--) {
            printf("%d ", l[j]);
        }
        printf("\n");
    } else {
        printf("Impossible!\n");
    }
}

int main(){
    int t = 0; scanf("%d", &t);
    while(t--){
        for (int i = 1; i <= n; i++){
            st[i].clear();
        }
        memset(in, 0, sizeof(in));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            st[y].push_back(x);
            in[x]++;
        }
        toposort();
    }
    return 0;
}