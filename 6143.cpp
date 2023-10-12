#include <cstdio>
#include <algorithm>
const int N = 1e5 + 5;
int n, m, top, ans[N];
struct Node{
    int v, mx, mn, res;
}node[N], node2[N];
bool cmp(Node a, Node b){
    if(a.mx != b.mx) return a.mx < b.mx;
    return a.mn < b.mn;
}
void cdq(int l, int r){
    int mid = (l + r) >> 1;
    cdq(l, mid);
    // for (int i = lef, j = mid; i < mid or j < rig;)
    //     if (j == rig or (i < mid and d[i].y <= d[j].y)){
    //         if(d[i].type) cnt++;
    //         tmp[p++] = d[i++];
    //     }else{
    //         if(!d[j].type) ans[d[j].idx] += cnt;
    //         tmp[p++] = d[j++];
    //     }
    // for (int i = 0, j = lef; i < p;)
    //     d[j++] = tmp[i++];
    for (int L = l, R = mid + 1, k = l; R < r || L < mid; R++){
        if(R == r || (L < mid && node[L].mx <= node[R].v)){
            node[L].res++, node2[k++] = node[L++];
        }else{
            ans[R] += node[L].res;
            node2[k++] = node[R++];
        }
    }
    cdq(mid + 1, r);
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &node[i].v), node[i].mx = node[i].mn = node[i].v;
    for (int i = 1, x, y; i <= m; i++){
        scanf("%d%d", &x, &y);
        node[x].mx = std::max(node[x].mx, y);
        node[x].mn = std::min(node[x].mn, y);
    }
    std::sort(node + 1, node + 1 + m);
    
    return 0;
}