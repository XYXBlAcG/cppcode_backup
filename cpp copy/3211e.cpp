#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
const int N = 3e5 + 5;
int fath[N], length[N], max[N];
struct Node{
    int length, son, father, max, to;
}back[N]; int pback;
int find(int a){
    return fath[a] != a ? find(fath[a]) : a;
}
void unite(int x, int y){
    x = find(x), y = find(y);
    // if(x == y) return;
    if(length[x] > length[y]){
        std::swap(x, y);
    }
    back[++pback] = (Node){length[y], x, fath[x], max[y], y};
    fath[x] = y;
    max[y] = std::max(max[x], max[y]);
    if(length[x] == length[y]) length[y]++;
}
int n, m;
int main(){
    int u, v;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++){
        fath[i] = i;
        max[i] = i;
        length[i] = 1;
    }
    for (int i = 1; i <= m; i++){
        std::string op;
        std::cin >> op;
        if (op == "merge"){
            scanf("%d%d",&u,&v);
            // fath[u] = find(fath[v]);
            unite(u, v);
            printf("%d\n", max[find(u)]);
        }else if(op == "query"){
            scanf("%d%d",&u,&v);
            printf("%d\n", find(u) == find(v) ? 1 : 0);
        }else if(op == "ctrlz"){
            if(pback){
                fath[back[pback].son] = back[pback].father;
                max[back[pback].to] = back[pback].max;
                length[back[pback].to] = back[pback].length;
                pback--;
            }
        }
    }
    return 0;
}