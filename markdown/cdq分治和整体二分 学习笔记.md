# cdq分治和整体二分 学习笔记

Author：QWQ_XYX.

cdq分治是一种分治，是离线算法。

具体做法：

常规做法：

1. 首先找到区间中点 $mid$ .
2. 之后首先对于区间 $[l..mid]$ 进行操作。
3. 对于区间 $[mid+1..r]$ 进行操作。
4. 进行转移和更新，从 $[l..mid]$ 到 $[mid+1..r]$ .
5. 递归地进行处理。

接下来我将会引用一段代码进行讲解。

题面：

有 $ n $ 个元素，第 $ i $ 个元素有 $ a_i,b_i,c_i $ 三个属性，设 $ f(i) $ 表示满足 $ a_j \leq a_i $ 且 $ b_j \leq b_i $ 且 $ c_j \leq c_i $ 且 $ j \ne i $ 的 $j$ 的数量。

对于 $ d \in [0, n) $，求 $ f(i) = d $ 的数量。

第一行两个整数 $ n,k $，表示元素数量和最大属性值。

接下来 $ n $ 行，每行三个整数 $ a_i ,b_i,c_i $，分别表示三个属性值。

$ n $ 行，第 $ d + 1 $ 行表示 $ f(i) = d $ 的 $ i $ 的数量。

### 样例输入 #1

```
10 3
3 3 3
2 3 3
2 3 1
3 1 1
3 1 2
1 3 1
1 1 2
1 2 2
1 3 2
1 2 1
```

### 样例输出 #1

```
3
1
3
0
1
0
1
0
0
1
```

## 提示

$ 1 \leq n \leq 10^5$，$1 \leq a_i, b_i, c_i \le k \leq 2 \times 10^5 $。



$code:$

```cpp
#include <cstdio>
#include <algorithm>
const int N = 1e5 + 5;
int n, k, len, res[N];
struct Node{
    int a, b, c, cnt, ans;
    bool operator!=(const Node az) const{
        return (az.a != a) || (az.b != b) || (az.c != c); // 进行一个去重
    }
}d1[N], d2[N];
bool cmp1(Node a, Node b){
    if(a.a != b.a) return a.a < b.a;
    if(a.b != b.b) return a.b < b.b;
    return a.c < b.c;
}
bool cmp2(Node a, Node b){
    if(a.b != b.b) return a.b < b.b;
    return a.c < b.c;
}
struct Tree{ // 树状数组
    int node[N << 1];
    int lowbit(int u){return u & -u;}
    void add(int u, int v){
        for (; u <= k; u += lowbit(u)) node[u] += v;
    }
    int get(int u){
        int ans = 0;
        for (; u; u -= lowbit(u)) ans += node[u];
        return ans;
    }
}tree;
void solve(int l, int r){
    if(l >= r) return;
    int mid = (l + r) >> 1;
    int i = l, j = mid + 1;
    solve(l, mid), solve(mid + 1, r);
    std::sort(d2 + l, d2 + mid + 1, cmp2);
    std::sort(d2 + mid + 1, d2 + r + 1, cmp2);
		// 排序，对于左右两个区间保证其是有序的.
  	// the following is merge_sort.
    for (; j <= r; j++){
        for (; i <= mid && d2[i].b <= d2[j].b; i++)
            tree.add(d2[i].c, d2[i].cnt);
        d2[j].ans += tree.get(d2[j].c);
    }
  	// 将树状数组清空.
    for (int o = l; o < i; o++) tree.add(d2[o].c, -d2[o].cnt);
}
int main(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &d1[i].a, &d1[i].b, &d1[i].c);
    std::sort(d1 + 1, d1 + n + 1, cmp1);
  	// 离散化
    for (int i = 1, t = 0; i <= n; i++){
        ++t;
        if(d1[i + 1] != d1[i]) d2[++len] = {d1[i].a, d1[i].b, d1[i].c, t, 0}, t = 0;
    }
    solve(1, len);
    for (int i = 1; i <= len; i++) // cal ans
        res[d2[i].ans + d2[i].cnt] += d2[i].cnt;
    for (int i = 1; i <= n; i++) printf("%d\n", res[i]);
    return 0;
}
```

