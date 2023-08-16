#include <cstdio>
#include <algorithm>
#include <iostream>
#define int long long
#define l(x) t[x].l
#define r(x) t[x].r
#define lm(x) t[x].lm
#define rm(x) t[x].rm
#define mi(x) t[x].mi
// #define sum(x) t[x].sum
// #define val(x) t[x].val
// #define ll(x) t[x].ll
// #define rr(x) t[x].rr
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
#define sl ls(u)
#define sr rs(u)
#define len(x) r(x) - l(x) + 1
#define a(x) a[x]
#define de(x) std::cout << " = " << x << std::endl
const int N = 1e5 + 5;
int n, m, a[N], LL, RR;
struct Tree{
    int l, r, lm, rm, mi; 
}t[N << 2];
void debug(int u, int l, int r){
	printf("%lld %lld %lld %lld %lld\n", t[u].l, t[u].r, t[u].lm, t[u].rm, t[u].mi);
	if(l == r) return;
	int mid = (l + r) >> 1;
	debug(u << 1, l, mid);
	debug(u << 1 | 1, mid + 1, r);
    
}
void pushup(int u){
    // sum(u) = sum(sl) + sum(sr); 
    bool tmp = (a(l(sr)) > a(r(sl)));
    lm(u) = lm(sl);
    rm(u) = rm(sr);
    // lm(u) = len(u);
    // int flag = 0;
   
    if((len(sl) == mi(sl))){
        // flag = 1;
        // mi(u) = mi(sl);
        // lm(u) += lm(sr) + 1;
        lm(u) = len(sl) + lm(sr) * tmp;
        // ll(u) = ll(sl);
        // rr(u) = rr(sl);
    }
    
    // rm(u) = len(u);
    if((len(sr) == mi(sr))) {
        // flag = 1;
        // mi(u) = mi(sr);
        // rm(u) += rm(sl) + 1;
        rm(u) = len(sr) + rm(sl) * tmp;
        // ll(u) = ll(sr);
        // rr(u) = rr(sr);
    }
    if(mi(sl) >= mi(sr) && (mi(sl) >= (rm(sl) + lm(sr)) * (tmp))){
        mi(u) = mi(sl);
    }else if(mi(sr) >= mi(sl) && (mi(sr) >= (rm(sl) + lm(sr)) * (tmp))){
        mi(u) = mi(sr);
    }else{
        mi(u) = rm(sl) + lm(sr);
    }
    // mi(u) = std::max(mi(u), mi(sl));
    // mi(u) = std::max(mi(u), mi(sr));
    // mi(u) = std::max(mi(u), lm(u));
    // mi(u) = std::max(mi(u), rm(u));

    // if((a(l(sl)) < a(l(sr)))) mi(u) = std::max(mi(u), rm(sl) + lm(sr) );

    // if(!flag) ll(u) = ll(sl); rr(u) = rr(sr);
    // if(!flag) 
    // de(u), de(sum(u)), de(len(u)), de(lm(u)), de(rm(u)), de(mi(u)), de(ll(u)), de(rr(u));
    // de(lm(u)), de(rm(u)), de(mi(u));
    // de(lm(sl)), de(rm(sl)), de(mi(sl));
    // de(lm(sr)), de(rm(sr)), de(mi(sr));
}
void modify(int u, int l, int r, int id, int v){
    // if(l > id || r < id) return;
    // if(l >= id && r <= id){
    //     // val(u) = v;
    //     // ll(u) = rr(u) = v;
    //     return;
    // }
    if(l > RR || r < LL) return;
    if(l >= LL && r <= RR){
        // val(u) = v;
        // ll(u) = rr(u) = v;
        return;
    }
    int mid = (l + r) >> 1;
    modify(sl, l, mid, id, v);
    modify(sr, mid + 1, r, id, v);
    pushup(u);
    // printf("modify "), de(mi(u));
    // printf("modify "), de(mi(sl));
    // printf("modify "), de(mi(sr));
}
void build(int u, int l, int r){
    l(u) = l, r(u) = r;
    if(l == r){
        // sum(u) = 1;
        l(u) = l, r(u) = r;
        lm(u) = rm(u) = mi(u) = 1;
        // val(u) = 1;
        // ll(u) = l; rr(u) = r;
        // de(ll(u)), de(rr(u)), de(a[u]);
        return;
    }
    int mid = (l + r) >> 1;
    // l(u) = l, r(u) = r;
    build(sl, l, mid);
    build(sr, mid + 1, r);
    // l(u) = l, r(u) = r;
    pushup(u);
}
int query(int u, int l, int r){
    // if(l > R || r < L){
    //     printf("query 0\n");
    //     return 0;
    // }
    // if(l >= L && r <= R){
    //     printf("query "), de(mi(u));
    //     return mi(u);
    // }
    if(l > RR || r < LL){
        // printf("query 0\n");
        return 0;
    }
    if(l >= LL && r <= RR){
        // printf("query "), de(mi(u));
        return mi(u);
    }
    int mid = (l + r) >> 1;
    // return std::max(std::max(query(v<<1,l,mid),\
    // query(v<<1|1,mid+1,r)),\
    // (std::min(rm(ls(v)),r(ls(v))-LL+1)\
    // +std::min(lm(rs(v)),RR-l(rs(v))+1))\
    // *(a[r(ls(v))]<a[l(rs(v))]));
    return std::max(std::max(query(u << 1, l, mid), \
    query(u << 1 | 1, mid + 1, r)), \
    (std::min(rm(u << 1), r(u << 1) - LL + 1)\
    +std::min(lm(u << 1 | 1), RR - l(u << 1 | 1) + 1)) \
    * (a(r(u << 1)) < a(l(u << 1 | 1))));
}

int query_copy(int l,int r,int v){
	if(l>RR||LL>r){printf("query 0\n");return 0;}
	if(LL<=l&&r<=RR){
		printf("query "), de(mi(v));
		return mi(v);}
	int mid=(l+r)>>1;
//	printf("v=%d l=%d r=%d spl=%d\n",v,l,r,(std::min(tree[v<<1].rm,tree[v<<1].r-L+1)+std::min(tree[v<<1|1].lm,R-tree[v<<1|1].l+1))*(a[tree[v<<1].r]<a[tree[v<<1|1].l]));
	return std::max(std::max(query(l,mid,v<<1),\
    query(mid+1,r,v<<1|1)),\
    (std::min(rm(ls(v)),r(ls(v))-LL+1)\
    +std::min(lm(rs(v)),RR-l(rs(v))+1))\
    *(a[r(ls(v))]<a[l(rs(v))]));
}


signed main(){
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%lld", a + i);
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++){
        int op, v, c, l, r;
        scanf("%lld", &op);
        if(!op){
            scanf("%lld%lld", &v, &c);
            a[v] = c;
            LL = RR = v;
            modify(1, 1, n, v, c);
    //         debug(1, 1, n);
    //         for (int i = 1; i <= n; i++){
    //     printf("%lld ", a[i]);
    // }putchar('\n');
        }else{
            scanf("%lld%lld", &l, &r);
            LL = l, RR = r;
            printf("%lld\n", query(1, 1, n));
    //         debug(1, 1, n);
    //         for (int i = 1; i <= n; i++){
    //     printf("%lld ", a[i]);
    // }putchar('\n');
        }
    }
    return 0;
}