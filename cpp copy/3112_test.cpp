#include <iostream>
#include <vector>
using std::vector;

const int MAXN = 1e6 + 10;
vector<int> out[MAXN], in[MAXN]; 

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int d;
        scanf("%d", &d);
        while (d--) {
            int u;
            scanf("%d", &u);
            out[i].push_back(u);
            in[u].push_back(i);
        }
    }
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%lu ", in[i].size());
        for (auto &u : in[i]) {
            printf("%d ", u);
        }
        printf("\n");
    }
    return 0;
}
