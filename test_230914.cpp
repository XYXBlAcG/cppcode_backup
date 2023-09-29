#include <cstdio>
#include <limits>
#include <bit>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>
#define p(...) printf(__VA_ARGS__)
using std::cin;
using std::endl;
using std::cout;
// struct Node{
//     int a, b, c;
//     Node(){a = b = c = 1;printf("set!\n");}
//     ~Node(){printf("end!\n");}
// }node;
// template <typename T>
// T myabs(T a){
//     return (a < 0) ? -a : a;
// }

// std::bitset<10000> az;
int main(){
    std::string a, b;
    scanf(" %s", &a);
    scanf("%s", &b);
    printf("%s\n%s\n", a.c_str(), b.c_str());
    // int list[5] = {1, 2, 3, 4, 5}, *ptr = list;
    // for (int i = 0; i < 5; i++){
    //     printf("list[%d] = {%d, %d}\n", i, ptr, *ptr);
    //     ptr++;
    // }
    // char data[4];
    // *(int*)data = 114514;
    // cout << *(int*)data << endl;
    // *(float*)data = 1919.810;
    // cout << *(float*)data << endl;
    // az.set();
    // printf("%d\n", az[1]);
    // double a = -1145141919810.114;
    // printf("%lf %lf\n", myabs(a), fabs(a));
    // std::vector<int> a{3, 6, 1, 7, 2, 8, 9, 10};
    // std::vector<int>::iterator ans = std::max_element(a.begin(), a.end());
    // printf("%ld\n", std::distance(a.begin(), ans));
    // printf("%d %d %d\n", node.a, node.b, node.c);
    // long long tmp = 1145141919810;
    // printf("%d %d\n", __builtin_popcount(tmp), __builtin_popcountll(tmp));
    // p("1\n");
    // std::cout << char(1 + 'A') << std::endl;
    // printf("%d\n", INT_MAX);
    return 0;
}