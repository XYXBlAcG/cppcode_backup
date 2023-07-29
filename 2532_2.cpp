#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 1e6 + 10;
struct Node
{
    int l;
    int r;
    int idx;
}ask[N];
// 在区间 [l1, x] 中查找最大的元素
int findMaxInSmall(const std::vector<int>& a, int l1, int x) {
    int l = l1, r = x;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (a[mid] >= a[l1]) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return a[l];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // 使用 std::vector 定义动态数组
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    std::vector<int> ans(m + 1);
    std::vector<Node> ask(m + 1);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &ask[i].l, &ask[i].r);
        ask[i].idx = i;
    }

    // 按照右端点排序
    std::sort(ask.begin() + 1, ask.end(), [](const Node& a, const Node& b) {
        return a.r < b.r;
    });

    for (int i = 1; i <= m; i++) {
        ans[ask[i].idx] = findMaxInSmall(a, ask[i].l, ask[i].r);
    }

    // 输出结果
    for (int i = 1; i <= m; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
