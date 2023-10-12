#include <cstdio>
#include <vector>
const int N = 1e5 + 5;
namespace 查询全局第k小{
    struct Q{
        int id, k;
    };
    int ans[N];
    int check(int x);
    void solve(int l, int r, std::vector<Q> q){
        int mid = (l + r) >> 1;
        std::vector<Q> q1, q2;
        if(l == r){
            for (auto v : q){
                ans[v.id] = mid; // 现在这个位置对应的 id 可以取到所枚举的 max.
            }
            return;
        }
        for (auto v : q){
            if(check(v.k) <= mid) q1.push_back(v); // 比中界小, push到左边.
            else v.k -= check(v.k), q2.push_back(v); // 比中界大, 减去多余, push到右边.
        }
        solve(l, mid, q1), solve(mid + 1, r, q2);
    }
}
namespace 查询区间第k小{
    
}