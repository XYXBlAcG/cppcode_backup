#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000000;

int phi[MAXN + 1];
vector<int> primes;

void euler_sieve(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == 0) {
            phi[i] = i - 1;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] * i <= n; j++) {
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            else {
                phi[i * primes[j]] = phi[i] * (primes[j] - 1);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    euler_sieve(n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += phi[i];
    }
    cout << ans / 2 << endl;
    return 0;
}