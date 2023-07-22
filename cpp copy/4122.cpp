// #include <cstdio>
// #include <algorithm>
// #include <vector>
// #include <cmath>
// #include <cstring>
// using std::vector;
// typedef long long ll; 
// const int M = 1e4 + 5;
// ll n;
// ll f[M];
// vector<ll> yin;
// bool isPrime(ll num){
//     if(num < 2) return 0;
//     for (int i = 2; i * i <= num; i++){
//         if(i != 0 && num % i == 0) return 0;
//     }return 1;
// }
// // int bin(ll num){
// //     // num -> subtitle
// //     if(num < yin[0]) return -1;
// //     int l = 0, r = yin.size() - 1, mid;
// //     while(l < r){
// //         mid = (l + r + 1) >> 1; 
// //         if(yin[mid] <= num) l = mid;
// //         else r = mid - 1;
// //     }
// //     return l;
// // }
// int bin(ll num){
//     // num -> subtitle
//     if(num <= 1) return -1;
//     int l = 0, r = yin.size() - 1, mid;
//     while(l < r){
//         mid = (l + r + 1) >> 1; 
//         if(yin[mid] <= num) l = mid;
//         else r = mid - 1;
//     }
//     printf("%d -> %lld, yin[%d] = %lld\n", l, num, l, yin[l]);
//     return l;
// }
// ll ans = 0;
// vector<ll> get_factors(ll n) {
//     vector<ll> factors;
//     vector<ll> factor(n + 1, 0);
//     for (int i = 2; i <= n; i++) {
//         if (factor[i] == 0) {
//             for (int j = i * i; j <= n; j += i) {
//                 if (factor[j] == 0) {
//                     factor[j] = i;
//                 }
//             }
//         }
//     }
//     int i = 2;
//     while (i * i < n) {
//         if (n % i == 0) {
//             factors.push_back(i);
//             factors.push_back(n / i);
//         }
//         i++;
//     }
//     if (i * i == n) {
//         factors.push_back(i);
//     }
//     factors.push_back(n);
//     return factors;
// }
// int main(){
//     while(scanf("%lld",&n) != EOF){
//         // ans = 0;
//         if(isPrime(n)) {printf("0\n"); continue;}
//         yin = get_factors(n);
//         std::sort(yin.begin(), yin.end());
//         for (int i = 0; i < yin.size(); i++) {
//             printf("%lld ", yin[i]);
//         }printf("\n");
//         printf("size:%d\n", (int)yin.size());
//         // resolve((int)yin.size() - 1, 0);
//         f[0] = 1;
//         for (int i = 0; i < yin.size(); i++){
//             for (int j = i; j < yin.size(); j++){
//                 f[j] += (yin[i] && yin[j] % yin[i] == 0 ? f[bin(yin[j] / yin[i])] : 0);
//             }
//         }
//         printf("%lld\n", f[(int)yin.size() - 1]);
//     }
//     return 0;
// }

