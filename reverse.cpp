#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
const int N = 1e5 + 5;
std::wstring str;
wchar_t ch[N];
void read(std::wstring& x){
    scanf("%s", ch), x = ch;
}
int main(){
    read(str);
    std::reverse(str.begin(), str.end());
    
    return 0;
}