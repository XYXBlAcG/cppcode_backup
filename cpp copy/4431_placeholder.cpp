// int com(int L, int R, int v, int l, int r, int idx, int x){
//     if(L <= l && r <= R){
//         if(!idx){
//             return t[v];
//         }else if(idx == 1){
//             down(v, x);
//             return -1;
//         }
//     }
//     if(r < L || R < l){
//         return -INF;
//     }int mid = (l + r) >> 1;
//     if(idx == 1){
//         down(v << 1, g[v]);
//         down(v << 1 | 1, g[v]);
//         g[v] = 0;
//     }else if(!idx){
//         return std::max(com(L, R, v << 1, l, mid, idx, x), com(L, R, v << 1 | 1, mid + 1, r, idx, x));
//     }
// }