#include <cstdio>
#include <map>
std::map<int, int> fuck;
int main(){
    fuck[114513] = 1;
    printf("%d\n", fuck.find(114514) == fuck.end());
    return 0;
}