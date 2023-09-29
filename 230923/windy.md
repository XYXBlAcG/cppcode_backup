# windy 数

定义: $f(k,x)$ 表示有 $k$ 个位可以任意取值，最高位的上一位为 $x$ 方案数。
$$
f(k,x)=\sum\limits^{9}_{y=0}[|x-y|>1]f(k-1,y)
$$

$$
ans=\sum\limits^{n-1}_{i=1}\sum\limits^{9}_{x=1}f(i-1,x)+\sum\limits^{n}_{i=1}[{\bigwedge\limits_{k=1}^{i-1}(|a_k-a_{k+1}|>1) } ]\sum\limits^{a_i-(i=n)}_{x=[i=1]}[|a_{i-1}-x|>1]f(n-i,x)
$$

边界: $f(0,x)=1$

![windy](C:\Users\admin\Desktop\windy.png)
