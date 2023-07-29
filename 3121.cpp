#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using std::cin;
const int N = 2e5 + 5;
int n, vis[N], ans;
std::vector<int> st[N];
// std::vector<std::string> charlist;
std::string charlist[N]; int cnt;
void dfs(int u){
    vis[u] = 1;
    for(int i = 0; i < st[u].size(); i++){
        int v = st[u][i];
        if(!vis[v]){
            dfs(v);
        }
    }
}
bool cmp(std::string a, std::string b){
    return a < b;
}
int main(){
    scanf("%d ", &n);
    while(cnt < n){
        cin >> charlist[++cnt];
        // charlist.push_back(a);
    }
    std::sort(charlist, charlist + cnt + 1, cmp);
    for (int f = 1; f <= cnt; f++){
        // std::string a;
        int flag2 = 0;
        int i = 0;
        // for (char c = getchar(); c > 32 && c < 127; c = getchar()){
        for (char c = charlist[f][i]; i < charlist[f].size(); c = charlist[f][++i]){
            if(f){ 
                int flag = 0, o = f - 1;
                for(int j = 0; j < charlist[o].size(); j++){
                    if(charlist[o][j] == c){
                        st[f].push_back(o);
                        st[o].push_back(f);
                        flag = 1;
                        break;
                    }
                    if(j == charlist[o].size() - 1 && !flag){
                        if(o == 1){
                            flag = 1;
                            break;
                        }
                        o--; j = 0;
                    }
                }
                if(flag) break;
            }
            // flag = 1;
        }
        // if(flag != 2){
        //     // charlist.push_back(a);
        // } 
    }
    

    for (int i = 1; i <= cnt; i++){
        if(!vis[i] && st[i].size()) { 
            dfs(i); ans++;
            // dfs(i);
            // if(st[i].size())
            // {dfs(i); ans++;}
        }
    }
    for (int i = 1; i <= cnt; i++){
        if(!vis[i]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}

// if(c < 32 && !flag) {
//     flag = 2;
//     // n++;
//     break;
// }
// else a.push_back(c);

// for (int i = 0; i < charlist.size(); i++){
//     printf("%s\n", charlist[i].c_str());
// }
// printf("!");
// for (int i = 0; i < charlist.size(); i++){
//     // printf("size:%ld \n", st[i].size());
//     for(int j = 0; j < st[i].size(); j++){
//         // printf("%d %d\n", i, j);
//     }
//     // printf("\n");
// }

// for (int o = f; o > 0; o--){
//     // if(st[o][o - 1] && st[f][o]) continue;
//     for(int j = 0; j < charlist[o - 1].size(); j++){
//         if(charlist[f - 1][j] == c) {
//             st[f].push_back(o - 1);
//             st[o - 1].push_back(f);
//             flag2 = 1;
//             break;
//         }
//     }
// }

// for (int i = 1; i <= cnt; i++){
//     printf("%s\n", charlist[i].c_str());
// }
// for (int i = 1; i <= cnt; i++){
//     // printf("size:%ld \n", st[i].size());
//     for(int j = 0; j < st[i].size(); j++){
//         printf("%d %d\n", i, j);
//     }
//     printf("\n");
// }