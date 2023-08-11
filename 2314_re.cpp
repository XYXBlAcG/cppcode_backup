#include <cstdio>
const int N = 1e6 + 5;
int op[N];
int sta[N], pst, sta2[N], pst2;
int main(){
    int cnt = 0;
    for (char c = getchar(); c > 32; c = getchar()) op[++cnt] = c;
    for (int i = 1; i <= cnt; i++){
        if((op[i] >= 97 && op[i] <= 122) || (op[i] >= 65 && op[i] <= 90))
            sta[++pst] = op[i];
        else if(op[i] == '['){
            if(!pst) continue;
            sta2[++pst2] = sta[pst--];
        }else if(op[i] == ']'){
            if(!pst2) continue;
            sta[++pst] = sta2[pst2--];
        }else if(op[i] == '}'){
            if(!pst) continue;
            sta[pst--] = 0;
        }
    }
    for (int i = 1; i <= pst; i++)
        printf("%c", sta[i]);
    for (int i = pst2; i ; i--)
        printf("%c", sta2[i]);
    return 0;
}