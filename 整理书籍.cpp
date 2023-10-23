#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
const int N = 5e5 + 5;
int n, t[N], mx;
struct FileIO{
    FileIO(){
        freopen("sort.in", "r", stdin);
        freopen("sort.out", "w", stdout);
    }
    ~FileIO(){
        fclose(stdin);
        fclose(stdout);
    }
}FileIO;
int main(){
    scanf("%d", &n);
    for (int i = 1, a; i <= n; i++){
        scanf("%d", &a);
        mx = std::max(t[a] = t[a - 1] + 1, mx);
    }
    printf("%d\n", n - mx);
    return 0;
}