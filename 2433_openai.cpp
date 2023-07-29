#include <cstdio>
#include <algorithm>
using std::push_heap;
using std::pop_heap;

const int N = 1e6 + 5;

struct Node
{
    int val, add, idx, nv;
} item[N];

struct Note
{
    int val, idx;
} heap[N];
int lenh;

int addd[N];
int res[N], ansl;

bool cmp(const Node& a, const Node& b){
    return a.val < b.val;
}

bool cmpn(const Note& a, const Note& b){
    return a.val > b.val;
}

bool cmpf(const Note& a, const Note& b){
    if(a.val == b.val) return a.idx > b.idx;
    return a.val < b.val;
}

bool cmp3(const Node& a, const Node& b){
    return a.idx < b.idx;
}

int cnt[N];

int n;

inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时
        x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
        ch = getchar();  // 继续读入
    }
    return x * w;  // 数字 * 正负号 = 实际数值
}

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        item[i].val = read();
        item[i].add = read();
        item[i].idx = i;
    }

    std::sort(item + 1, item + n + 1, cmp);

    int tmp = 0;
    for (int i = 1; i <= n; i++){
        addd[i] = item[i].val;
        if(item[i].val != item[i - 1].val){
            tmp++;
        }
        res[item[i].idx] = tmp; 
    }

    int len = 0;
    std::sort(item + 1, item + n + 1, cmp3);

    for (int i = 1; i <= n; i++){
        cnt[res[i]] += item[i].add;
        heap[++lenh] = (Note){cnt[res[i]] , res[i]};
        push_heap(heap + 1, heap + lenh + 1, cmpf);
        for(;lenh && heap[1].val != cnt[res[i]]; pop_heap(heap + 1, heap + (lenh--) + 1, cmpf));
        printf("%d\n", heap[1].val);
    }

    return 0;
}
