#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[10];
char s[20];
int main(){
    scanf("%s", s+1);
    for (int i=1;i<=6;++i){
        if (s[i]<65) a[i] = s[i]-'0';
        else a[i] = s[i]-'A'+10;
    }
    int r = a[1]*16+a[2];
    int g = a[3]*16+a[4];
    int b = a[5]*16+a[6]; printf("%02x%02x%02x",255-r,255-g,255-b); 
    return 0;
}