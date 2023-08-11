#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<climits>
#define LL long long
#define REP(i, x, y) for(int i = (x);i <= (y);i++)
using namespace std;
int RD(){
    int out = 0,flag = 1;char c = getchar();
    while(c < '0' || c >'9'){if(c == '-')flag = -1;c = getchar();}
    while(c >= '0' && c <= '9'){out = out * 10 + c - '0';c = getchar();}
    return flag * out;
    }
const int maxn = 200019;
int num, na;
int v[maxn];
#define lid (id << 1)
#define rid (id << 1) | 1
//int max(int a, int b){return a > b ? a : b;}//听说手写快？
struct seg_tree{
    int l, r;
    int sum;
    int lazy;//-1.NULL  0.全为0  1.全为1
	int rev;
    int max[2], lmax[2], rmax[2];
    }tree[maxn << 2];
void pushup(int id){
    tree[id].sum = tree[lid].sum + tree[rid].sum;
    REP(i, 0, 1){
        tree[id].lmax[i] = tree[lid].lmax[i];
        if(i == 1 && tree[lid].sum == tree[lid].r - tree[lid].l + 1)//左区间全满
            tree[id].lmax[i] += tree[rid].lmax[i];//可以跨越
        else if(i == 0 && tree[lid].sum == 0)//左区间全空
            tree[id].lmax[i] += tree[rid].lmax[i];
        
        tree[id].rmax[i] = tree[rid].rmax[i];
        if(i == 1 && tree[rid].sum == tree[rid].r - tree[rid].l + 1)
            tree[id].rmax[i] += tree[lid].rmax[i];
        else if(i == 0 && tree[rid].sum == 0)
            tree[id].rmax[i] += tree[lid].rmax[i];
        
        tree[id].max[i] = tree[lid].rmax[i] + tree[rid].lmax[i];//中间
        tree[id].max[i] = max(tree[id].max[i], tree[lid].max[i]);//继承子区间
        tree[id].max[i] = max(tree[id].max[i], tree[rid].max[i]);
        }
    }
void build(int id, int l, int r){
    tree[id].l = l, tree[id].r = r, tree[id].lazy = -1;
    if(l == r){
        tree[id].sum = v[l];
        tree[id].max[0] = tree[id].lmax[0] = tree[id].rmax[0] = v[l] == 0;
        tree[id].max[1] = tree[id].lmax[1] = tree[id].rmax[1] = v[l] == 1;
        return ;
        }
    int mid = (l + r) >> 1;
    build(lid, l, mid), build(rid, mid + 1, r);
    pushup(id);
    }
void pushdown(int id){
    if(tree[id].lazy != -1){//优先级最高
		tree[id].rev = 0;//清空标记
        int val = tree[id].lazy;
        tree[lid].sum = (tree[lid].r - tree[lid].l + 1) * val;
        tree[rid].sum = (tree[rid].r - tree[rid].l + 1) * val;
        
        tree[lid].lazy = tree[rid].lazy = val;
		tree[lid].rev = tree[rid].rev = 0;
        
        tree[lid].max[val] 
        = tree[lid].lmax[val] 
        = tree[lid].rmax[val] 
        = tree[lid].r - tree[lid].l + 1;
        tree[lid].max[val ^ 1] 
        = tree[lid].lmax[val ^ 1] 
        = tree[lid].rmax[val ^ 1] 
        = 0;
        
        tree[rid].max[val] 
        = tree[rid].lmax[val] 
        = tree[rid].rmax[val] 
        = tree[rid].r - tree[rid].l + 1;
        tree[rid].max[val ^ 1] 
        = tree[rid].lmax[val ^ 1] 
        = tree[rid].rmax[val ^ 1] 
        = 0;
		
		tree[id].lazy = -1;
        }
    if(tree[id].rev){
        tree[lid].sum = (tree[lid].r - tree[lid].l + 1) - tree[lid].sum;
        tree[rid].sum = (tree[rid].r - tree[rid].l + 1) - tree[rid].sum;
        
        if(tree[lid].lazy != -1)tree[lid].lazy ^= 1;//综合考虑优先级， 对其他标记的影响
		else tree[lid].rev ^= 1;
		if(tree[rid].lazy != -1)tree[rid].lazy ^= 1;
		else tree[rid].rev ^= 1;
        
        swap(tree[lid].max[0], tree[lid].max[1]);
        swap(tree[lid].lmax[0], tree[lid].lmax[1]);
        swap(tree[lid].rmax[0], tree[lid].rmax[1]);
        
        swap(tree[rid].max[0], tree[rid].max[1]);
        swap(tree[rid].lmax[0], tree[rid].lmax[1]);
        swap(tree[rid].rmax[0], tree[rid].rmax[1]);
		
		tree[id].rev = 0;
        }
    }
void update(int id, int val, int l, int r){
    pushdown(id);
    if(tree[id].l == l && tree[id].r == r){
        if(val == 0 || val == 1){
            tree[id].sum = (tree[id].r - tree[id].l + 1) * val;
            tree[id].lazy = val;
            tree[id].max[val] 
            = tree[id].lmax[val] 
            = tree[id].rmax[val] 
            = tree[id].r - tree[id].l + 1;
            tree[id].max[val ^ 1] 
            = tree[id].lmax[val ^ 1] 
            = tree[id].rmax[val ^ 1] 
            = 0;
            }
        else if(val == 2){
            tree[id].sum = (tree[id].r - tree[id].l + 1) - tree[id].sum;
            tree[id].rev ^= 1;
            swap(tree[id].max[0], tree[id].max[1]);
            swap(tree[id].lmax[0], tree[id].lmax[1]);
            swap(tree[id].rmax[0], tree[id].rmax[1]);
            }
        return ;
        }
    int mid = (tree[id].l + tree[id].r) >> 1;
    if(mid < l)update(rid, val, l, r);
    else if(mid >= r)update(lid, val, l, r);
    else update(lid, val, l, mid), update(rid, val, mid + 1, r);
    pushup(id);
    }
int query(int id, int l, int r){
    pushdown(id);
    if(tree[id].l == l && tree[id].r == r)return tree[id].sum;
    int mid = (tree[id].l + tree[id].r) >> 1;
    if(mid < l)return query(rid, l, r);
    else if(mid >= r)return query(lid, l, r);
    else return query(lid, l, mid) + query(rid, mid + 1, r);
    }
seg_tree Q_max(int id, int l, int r){
    pushdown(id);
    if(tree[id].l == l && tree[id].r == r)return tree[id];
    int mid = (tree[id].l + tree[id].r) >> 1;
    if(mid < l)return Q_max(rid, l, r);
    else if(mid >= r)return Q_max(lid, l, r);
    else{
        seg_tree ret, L = Q_max(lid, l, mid), R = Q_max(rid, mid + 1, r);
        ret.sum = L.sum + R.sum;
        REP(i, 0, 1){
            ret.lmax[i] = L.lmax[i];
            if(i == 1 && L.sum == L.r - L.l + 1)//左区间全满
                ret.lmax[i] += R.lmax[i];//可以跨越
            else if(i == 0 && L.sum == 0)//左区间全空
                ret.lmax[i] += R.lmax[i];
            
            ret.rmax[i] = R.rmax[i];
            if(i == 1 && R.sum == R.r - R.l + 1)
                ret.rmax[i] += L.rmax[i];
            else if(i == 0 && R.sum == 0)
                ret.rmax[i] += L.rmax[i];
            
            ret.max[i] = L.rmax[i] + R.lmax[i];//中间
            ret.max[i] = max(ret.max[i], L.max[i]);
            ret.max[i] = max(ret.max[i], R.max[i]);
            }
        return ret;
        }
    }
int main(){
    num = RD(), na = RD();
    REP(i, 1, num)v[i] = RD();
    build(1, 1, num);
    while(na--){
        int cmd = RD(), l = RD(), r = RD();l++, r++;
        if(cmd == 0)update(1, 0, l, r);
        else if(cmd == 1)update(1, 1, l, r);
        else if(cmd == 2)update(1, 2, l, r);
        else if(cmd == 3)printf("%d\n", query(1, l, r));
        else printf("%d\n", Q_max(1, l, r).max[1]);
        }
    return 0;
    }
