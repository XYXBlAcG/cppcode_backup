#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#define nd(u, v) node[u].ch[v]
#define ll(u) seg[u].l
#define rr(u) seg[u].r
#define nd2(u, v) node2[u].ch[v]
using std::cin;
using std::cout;
using std::string;
using std::max;
using std::min;
const int N = 4e6 + 5;
int n, m, cnt, ans, num[N], rt[N];
struct Node{
    int ch[27];
}node[N], node2[N];
struct Seg{
    int l, r;
}seg[N];
string strl[N], s1, s2;
struct Tree{
    void insert(string str, int pos){
        int p = 0;
        for (auto v : str){
            int c = v - 'a';
            if(!nd(p, c)) nd(p, c) = ++cnt, seg[cnt] = {pos, pos};
            else seg[nd(p, c)] = {min(ll(nd(p, c)), pos), max(rr(nd(p, c)), pos)};
            p = nd(p, c);
            // printf("l = %d, r = %d\n", ll(p), rr(p));
        }
    }
    Seg query(string str){
        int p = 0;
        for (auto v : str){
            int c = v - 'a';
            if(!nd(p, c)) return {-1, -1};
            p = nd(p, c);
        }
        return seg[p];
    }
}tree;
struct Tree2{
    void insert(string str, int cur, int las){
        for (auto v : str){
            nd2(cur, v - 'a') = ++cnt;
            for (int i = 0; i < 26; i++)
                if(i != v - 'a') nd2(cur, i) = nd2(las, i);
            num[nd2(cur, v - 'a')] = num[nd2(las, v - 'a')] + 1; 
            cur = nd2(cur, v - 'a'), las = nd2(las, v - 'a');
        }
    }
    int query(string str, int pos){
        for (auto v : str){
            if(!nd2(pos, v - 'a'))  return -1;
            pos = nd2(pos, v - 'a');
        }
        return num[pos];
    }
}tree2;
int main(){
    std::ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> strl[i];
    std::sort(strl + 1, strl + 1 + n);
    for (int i = 1; i <= n; i++){
        tree.insert(strl[i], i);
        std::reverse(strl[i].begin(), strl[i].end());
        // cout << "strl " << strl[i] << '\n';
    }
    // for (int i = 1; i <= n; i++){
    //     printf("seg %d = %d %d\n", i, ll(i), rr(i));
    // }
    for (int i = 1; i <= n; i++) tree2.insert(strl[i], rt[i] = ++cnt, rt[i - 1]);
    cin >> m;
    for (int i = 1; i <= m; i++){
        cin >> s1 >> s2;
        for (auto& v : s1) (((v -= 'a') += ans) %= 26) += 'a';
        for (auto& v : s2) (((v -= 'a') += ans) %= 26) += 'a';
        std::reverse(s2.begin(), s2.end());
        Seg se = tree.query(s1);
        if(se.l == -1) cout << "0\n", ans = 0;
        else{
            int l = tree2.query(s2, rt[se.l - 1]), r = tree2.query(s2, rt[se.r]);
            if(r == -1) cout << "0\n", ans = 0;
            else if(l == -1) cout << (ans = r) << '\n';
            else cout << (ans = (r - l)) << '\n';
        }
    }

    return 0;
}