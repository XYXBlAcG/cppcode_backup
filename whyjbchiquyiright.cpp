#include <cstdio>  
#include <algorithm>  
#include <cstring>  
#define MAX 100005  
#define LL long long  
#define INF 0x3f3f3f3f  
  
using namespace std;  
LL a[100010];  
int n, t, ans = INF;  
LL sum, s;  
  
int main()  
{  
    scanf("%d", &t);  
    while (t--){  
        scanf("%d %lld", &n, &s);  
        for (int i = 0; i < n; i++) scanf("%lld", a+i);  
        int st = 0, en = 0;  
        ans = INF; sum = 0;  
        while (1){  
            while (en<n && sum<s) sum += a[en++];  
            if (sum < s) break;  
            ans = min(ans, en-st);  
            sum -= a[st++];  
        }  
        if (ans == INF) ans = 0;  
        printf("%d\n", ans);  
    }  
    return 0;  
}