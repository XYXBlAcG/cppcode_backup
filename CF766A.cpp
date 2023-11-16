#include <bits/stdc++.h>
using namespace std;
string a, b;
int main(){
    cin >> a >> b;
    if(a == b) puts("-1");
    else printf("%lu\n", std::max(a.size(), b.size()));
    return 0;
}