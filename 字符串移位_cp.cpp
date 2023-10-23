#include <bits/stdc++.h>
const int N = 300005;
std::mt19937 rnd(251);
int n, Len, rt, pnode;
char buff[N];
struct Node {
    int ls, rs, sz, val, add;
} D[N];
int newD(int val) { return D[++pnode] = { 0, 0, 1, val, 0 }, pnode; }
int cpyD(int v) { return !v ? 0 : (D[++pnode] = D[v], pnode); }
void upd(int v, int t) { (D[v].val += t) %= 26, (D[v].add += t) %= 26; }
void pushdown(int v) {
    D[v].ls = cpyD(D[v].ls), D[v].rs = cpyD(D[v].rs);
    upd(D[v].ls, D[v].add), upd(D[v].rs, D[v].add), D[v].add = 0;
}
void pushup(int v) { D[v].sz = D[D[v].ls].sz + D[D[v].rs].sz + 1; }
void split(int v, int sz, int& l, int& r) {
    if (!v)
        return l = r = 0, void();
    pushdown(v);
    if (sz <= D[D[v].ls].sz)
        return r = cpyD(v), split(D[v].ls, sz, l, D[r].ls), pushup(r);
    l = cpyD(v), split(D[v].rs, sz - D[D[v].ls].sz - 1, D[l].rs, r), pushup(l);
}
int merge(int l, int r) {
    if (!l || !r)
        return l | r;
    int v;
    if (rnd() % (D[l].sz + D[r].sz) < 1u * D[l].sz)
        pushdown(l), D[v = cpyD(l)].rs = merge(D[l].rs, r);
    else
        pushdown(r), D[v = cpyD(r)].ls = merge(l, D[r].ls);
    return pushup(v), v;
}
void print(int v) {
    if (!v)
        return;
    pushdown(v), print(D[v].ls), putchar(D[v].val + 'a'), print(D[v].rs);
}

int main() {
    // freopen("string.in", "r", stdin), freopen("string.out", "w", stdout);
    scanf("%s%d", buff + 1, &n), Len = strlen(buff + 1);
    for (int i = 1; i <= Len; i++) rt = merge(rt, newD(buff[i] - 'a'));
    for (int i = 1, opt, p, l, r, x, y, z, a, b; i <= n; i++) {
        scanf("%d", &opt);
        if (opt == 1)
            scanf("%d%d%d", &p, &l, &r), split(rt, r, y, z), split(y, l - 1, x, y), split(rt, p, a, b),
                rt = merge(a, merge(y, b));
        else if (opt == 2)
            scanf("%d%d", &l, &r), split(rt, r, y, z), split(y, l - 1, x, y), rt = merge(x, z);
        else
            scanf("%d%d", &l, &r), split(rt, r, y, z), split(y, l - 1, x, y), upd(y, 1),
                rt = merge(x, merge(y, z));
        printf("i = %d\n", i);
        print(rt);
        putchar('\n');
    }
    return print(rt), fclose(stdin), fclose(stdout), 0;
}