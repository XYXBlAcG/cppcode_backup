#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
const int N = 1e6 + 5;
char str1[N], str2[N]; int l1, l2;
std::string cmp1, cmp2;
int get(char *a){
    int n = strlen(a), i = 0, j = 1, k = 0;
    while(i < n && j < n && k < n){
        if(a[(i + k) % n] == a[(j + k) % n]) k++;
        else{
            a[(i + k) % n] > a[(j + k) % n] ? i += k + 1 : j += k + 1;
            if(i == j) j++;
            k = 0;
        }
    }
    return std::min(i, j);
}
int main(){
    scanf("%s%s", str1, str2);
    l1 = strlen(str1), l2 = strlen(str2);
    int _1 = get(str1), _2 = get(str2);
    for (int i = _1; i < _1 + l1; i++)
        cmp1 += (str1[i % l1]);
    for (int i = _2; i < _2 + l2; i++)
        cmp2 += (str2[i % l2]);
    if(cmp1 != cmp2) puts("No");
    else{
        puts("Yes");
        for (auto v : cmp2)
            printf("%d", v - '0');
    }
    return 0;
}