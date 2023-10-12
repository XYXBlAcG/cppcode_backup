#include <cstdio>

const int N = 1e5 + 10;
int heap[N], sz = 0;
void push(int x)
{
    int i = sz++;
    while (i > 0){
        int p = (i - 1) / 2;
        if (heap[p] <= x)
            break;
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = x;
}
int pop()
{
    int ret = heap[0];
    int x = heap[--sz];
    heap[sz] = 0;
    int i = 0;
    while (i * 2 + 1 < sz)
    {
        int a = i * 2 + 1, b = i * 2 + 2;
        if (b < sz && heap[b] < heap[a])
            a = b;
        if (heap[a] >= x)
            break;
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}
int main()
{
    int temp, n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
        push(temp);
    }
    for (int i = 1; i <= m; i++)
    {
        int op = 0, x = 0;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            push(x);
        }
        else
        {
            printf("%d\n", pop());
        }
    }
    return 0;
}

int vis[N], pri[N], cnt;

void init(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            pri[cnt++] = i;
        }
        for (int j = 0; j < cnt; ++j) {
            if (1ll * i * pri[j] > n) break;
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) {
                break;
            }
        }
    }
}
