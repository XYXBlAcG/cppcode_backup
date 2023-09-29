#include <cstdio>
#include <string>
#include <iostream>
std::string sss;
int n, m;
signed main(){
    scanf("%d%d", &n, &m);
    std::cin >> sss;
    for (int i = 1; i <= m; i++){
        int op, x, l1, r1, l2, r2;
        char c;
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &x);
            std::cin >> c;
            sss[x - 1] = c;
        }else{
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
            std::string a = sss.substr(l1 - 1, r1 - l1 + 1);
            std::string b = sss.substr(l2 - 1, r2 - l2 + 1);
            if(a == b) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}