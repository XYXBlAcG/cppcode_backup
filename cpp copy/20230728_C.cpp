#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
typedef long long ll;
const int N = 10;
ll n, m, k, mxsize;
std::string str[N];
int main(){
    // freopen("dna.in", "r", stdin);
    // freopen("dna.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= n; i++){
        std::cin >> str[i];
        str[i] += str[i];
        mxsize = std::max((ll)str[i].size(), mxsize);
    }
    // for (int i = 1; i <= n; i++){
    //     std::cout << str[i] << std::endl;
    // }
    for (int i = 1; i <= mxsize; i++){
        for (int j = 1; j <= mxsize; j++){
            
        }
    }
    printf("%lld\n", m);

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}