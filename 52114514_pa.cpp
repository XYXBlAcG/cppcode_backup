#include <iostream>
#include <algorithm>
#define _ 103
#define __ 203
#define A (i<<1)-1
#define B (i<<1)
using namespace std;
int n, x, y, z, r;
int mx, X1[_], X2[_], X[__];
int my, Y1[_], Y2[_], Y[__];
int mz, Z1[_], Z2[_], Z[__];
int arr[__][__][__];
long long ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> z >> r;
        X[A] = X1[i] = x-r;
        X[B] = X2[i] = x+r;
        Y[A] = Y1[i] = y-r;
        Y[B] = Y2[i] = y+r;
        Z[A] = Z1[i] = z-r;
        Z[B] = Z2[i] = z+r;
    }
    sort(X+1, X+(n<<1)+1);
    sort(Y+1, Y+(n<<1)+1);
    sort(Z+1, Z+(n<<1)+1);
    mx = unique(X+1, X+(n<<1)+1)-X-1;
    my = unique(Y+1, Y+(n<<1)+1)-Y-1;
    mz = unique(Z+1, Z+(n<<1)+1)-Z-1;
    for (int i = 1; i <= n; i++) {
        X1[i] = lower_bound(X+1, X+mx+1, X1[i])-X;
        X2[i] = lower_bound(X+1, X+mx+1, X2[i])-X;
        Y1[i] = lower_bound(Y+1, Y+my+1, Y1[i])-Y;
        Y2[i] = lower_bound(Y+1, Y+my+1, Y2[i])-Y;
        Z1[i] = lower_bound(Z+1, Z+mz+1, Z1[i])-Z;
        Z2[i] = lower_bound(Z+1, Z+mz+1, Z2[i])-Z;
        arr[X1[i]][Y1[i]][Z1[i]]++;
        arr[X2[i]][Y1[i]][Z1[i]]--;
        arr[X1[i]][Y2[i]][Z1[i]]--;
        arr[X1[i]][Y1[i]][Z2[i]]--;
        arr[X1[i]][Y2[i]][Z2[i]]++;
        arr[X2[i]][Y1[i]][Z2[i]]++;
        arr[X2[i]][Y2[i]][Z1[i]]++;
        arr[X2[i]][Y2[i]][Z2[i]]--;
    }
    for (x = 1; x < mx; x++) {
        for (y = 1; y < my; y++) {
            for (z = 1; z < mz; z++) {
                arr[x][y][z] += arr[x-1][y][z] + arr[x][y-1][z] + arr[x][y][z-1]
                - arr[x][y-1][z-1] - arr[x-1][y][z-1] - arr[x-1][y-1][z] + arr[x-1][y-1][z-1];
                if (arr[x][y][z]) {
                    ans += (long long)(X[x+1]-X[x])*(Y[y+1]-Y[y])*(Z[z+1]-Z[z]);
                    printf("%lld\n", ans);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
