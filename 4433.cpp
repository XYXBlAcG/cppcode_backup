#include <cstdio>
#include <algorithm>
#include <iostream>
#define int long long
#define de(x) std::cout << #x << " = " << x << std::endl
#define tag(x) tree[x].tag
#define sum(x) tree[x].sum
#define rev(x) tree[x].rev
#define mi(x,y) tree[y].mi[x]
#define lm(x,y) tree[y].lm[x]
#define rm(x,y) tree[y].rm[x]
#define rl(x) tree[x].rl
#define ll(x) tree[x].ll
using std::swap;
const int N = 2e5 + 5;
int n, m, a[N], op, l1, r1, aans;
struct Segment_Tree {
    int sum, tag, rev, mi[3], lm[3], rm[3], rl, ll;
    // sum 表示总共有多少个1, tag 表示修改方式, 1 = 全是 1, 0 = 全是 0 , -1 表示不操作, rev 表示反转, mi 表示中间最多有多少个1
    // lm 表示左边最多有多少个1, rm 表示右边最多有多少个1
} tree[5 * N];
    void fuckyou(){l1++, r1++;}
    inline int ls(int u) { return u << 1; }
    inline int rs(int u) { return u << 1 | 1; }
    inline int len(int u) { return rl(u) - ll(u) + 1; }
    
    inline void pushdown(int u){
        if(tag(u) >= 0){
            rev(u) = 0;
            sum(ls(u)) = len(ls(u)) * (tag(u));
            sum(rs(u)) = len(rs(u)) * (tag(u));
            tag(ls(u)) = tag(rs(u)) = tag(u);
            rev(ls(u)) = rev(rs(u)) = 0;
            mi(tag(u),ls(u)) = lm(tag(u),ls(u)) = rm(tag(u),ls(u)) = len(ls(u));
            mi(tag(u),rs(u)) = lm(tag(u),rs(u)) = rm(tag(u),rs(u)) = len(rs(u));
            mi(tag(u) ^ 1,ls(u)) = lm(tag(u) ^ 1,ls(u)) = rm(tag(u) ^ 1,ls(u)) = 0;
            mi(tag(u) ^ 1,rs(u)) = lm(tag(u) ^ 1,rs(u)) = rm(tag(u) ^ 1,rs(u)) = 0;
            tag(u) = -1;
        }
        if(rev(u)){
            sum(ls(u)) = len(ls(u)) - sum(ls(u)); 
            sum(rs(u)) = len(rs(u)) - sum(rs(u));
            if(tag(ls(u)) >= 0) tag(ls(u)) ^= 1; else rev(ls(u)) ^= 1;
            if(tag(rs(u)) >= 0) tag(rs(u)) ^= 1; else rev(rs(u)) ^= 1;
            swap(mi(0,ls(u)), mi(1,ls(u))), swap(lm(0,ls(u)), lm(1,ls(u))), swap(rm(0,ls(u)), rm(1,ls(u)));
            swap(mi(0,rs(u)), mi(1,rs(u))), swap(lm(0,rs(u)), lm(1,rs(u))), swap(rm(0,rs(u)), rm(1,rs(u)));
            rev(u) = 0;
        }
    }

    inline void pushup(int u) {
        sum(u) = (sum(ls(u)) + sum(rs(u)));
        for (int i = 0; i <= 1; i++){
            lm(i,u) = lm(i,ls(u));
            if(((sum(ls(u)) == len(ls(u))) && i) || (!sum(ls(u)) && !i))
                lm(i,u) += lm(i,rs(u));
            rm(i,u) = rm(i,rs(u));
            if(((sum(rs(u)) == len(rs(u))) && i) || (!sum(rs(u)) && !i))
                rm(i,u) += rm(i,ls(u));
            mi(i,u) = rm(i,ls(u)) + lm(i,rs(u));
            mi(i,u) = std::max(mi(i,u), std::max(mi(i,ls(u)), mi(i,rs(u))));
            mi(i,u) = std::max(mi(i,u), std::max(lm(i,u), rm(i,u)));
        }
    }

    inline void build(int u, int l, int r, int *a) {
        tag(u) = -1, ll(u) = l, rl(u) = r;
        if (l == r) {
            sum(u) = a[l];
            lm(a[l],u) = mi(a[l],u) = rm(a[l],u) = 1;
            // lm(a[l] ^ 1,u) = mi(a[l] ^ 1,u) = rm(a[l] ^ 1,u) = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(u), l, mid, a);
        build(rs(u), mid + 1, r, a);
        pushup(u);
    }

    inline void modify(int u, int l, int r, int op) {
        pushdown(u);
        // puts("!");
        // if (L < l || r < R)
        //     return;
        if (l <= ll(u) && rl(u) <= r){
            if(op < 2){
                tag(u) = op;
                sum(u) = len(u) * (tag(u));
                mi(tag(u),u) = lm(tag(u),u) = rm(tag(u),u) = len(u);
                mi(tag(u) ^ 1,u) = lm(tag(u) ^ 1,u) = rm(tag(u) ^ 1,u) = 0;
            }else if(op == 2){
                sum(u) = len(u) - sum(u); 
                rev(u) ^= 1;
                swap(mi(0,u), mi(1,u)), swap(lm(0,u), lm(1,u)), swap(rm(0,u), rm(1,u));
            }
            return;
        }
        
        int mid = (ll(u) + rl(u)) >> 1;
        // if(l <= L && mid >= R) 
        if(l <= mid) modify(ls(u), l, r, op);
        // if(mid + 1 <= L && r >= R) 
        // else 
        if(r > mid) modify(rs(u), l, r, op);
        // else modify(ls(u), l, mid, op), modify(rs(u), mid + 1, r, op);
        pushup(u);
    }

    // inline int query(int u, int l, int r, int ql, int qr) {
    //     if (qr < l || r < ql)
    //         return 0;
    //     if (ql <= l && r <= qr)
    //         return sum(u);
    //     pushdown(u);
    //     int mid = (l + r) >> 1;
    //     return (query(ls(u), l, mid, ql, qr) + query(rs(u), mid + 1, r, ql, qr)) ;
    // }

inline int query(int u, int ql, int qr){
    if(ql <= ll(u) && rl(u) <= qr) return sum(u);
    pushdown(u);
    int mid = (ll(u) + rl(u)) >> 1, ans = 0;
    if(ql <= mid) ans += query(ls(u), ql, qr);
    if(qr > mid) ans += query(rs(u), ql, qr);
    return ans;
}

inline Segment_Tree length(int u, int l, int r){
    if(l <= ll(u) && rl(u) <= r) return tree[u];
    pushdown(u);
    int mid = (ll(u) + rl(u)) >> 1;
    if(r <= mid) return length(ls(u), l, r);
    if(l > mid) return length(rs(u), l, r);
    Segment_Tree ans, L = length(ls(u), l, r), R = length(rs(u), l, r);
    ans.sum = L.sum + R.sum;
    // de(ans.sum);
    for (int i = 0; i <= 1; i++){
        ans.lm[i] = L.lm[i];
        if(((L.sum == (L.rl - L.ll + 1)) && i) || (!L.sum && !i))
            ans.lm[i] += R.lm[i]; 
        ans.rm[i] = R.rm[i];
        if(((R.sum == (R.rl - R.ll + 1)) && i) || (!R.sum && !i))
            ans.rm[i] += L.rm[i]; 
        ans.mi[i] = L.rm[i] + R.lm[i]; 
        ans.mi[i] = std::max(ans.mi[i], std::max(L.mi[i], R.mi[i])); 
        ans.mi[i] = std::max(ans.mi[i], std::max(ans.lm[i], ans.rm[i])); 
    }
    // de(ans.mi[1]);
    return ans;
}

signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    build(1, 1, n, a);
    for (int i = 1; i <= m; i++){
        scanf("%lld%lld%lld", &op, &l1, &r1);
        // fuckyou();
        if(op == 0){
            modify(1, l1, r1, 0);
        }else if(op == 1){
            modify(1, l1, r1, 1);
        }else if(op == 2){
            modify(1, l1, r1, 2);
        }else if(op == 3){
            printf("%lld\n", query(1, l1, r1));
        }else if(op == 4){
            printf("%lld\n", length(1, l1, r1).mi[1]);
        }
    }
    return 0;
}