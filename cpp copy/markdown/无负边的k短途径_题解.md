## 题目描述

给 $n$ 个点 $m$ 条边的带权有向图，再给定起点 $s\;=\;1$ 。求 $s$ 到每个点的所有途径中，总长度最短的 $k$ 条的长度。



解题思路：

使用$Dijkstra$解决，但是稍作改动。

使用$std::push\_heap$和$std::pop\_heap$解决，不能使用优先队列。

给出核心代码：

```c++
void dijkstra(int s) {
  	// 加入开始点
    q[++lq] = (node){ 0, s };
  	// 加入堆
    push_heap(q + 1, q + lq + 1, cmp);
    while (lq) {
      	// 取出堆顶
        ll u = q[1].u, ddist = q[1].dis;
        pop_heap(q + 1, q + (lq--) + 1, cmp);
        if (cnt[u] > k) // 减少时间防止重复计算
            continue;
        ans[u][++cnt[u]] = ddist; // 更新答案
        for (auto ed : st[u]) {
            ll v = ed.v, w = ed.w;
            q[++lq] = (node){ (ddist + w), v };
          	// 将所有可能情况全部加入堆
            push_heap(q + 1, q + lq + 1, cmp);
        }
    }
}
```

$the\;end\sim$