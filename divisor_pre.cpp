#include <cstdio>
#include <vector>
#include <time.h>
using std::vector;
const int M = 10;
vector<int> breakdown(int N) {
    vector<int> result;
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {  
            // while (N % i == 0) N /= i;
            if(i * i != N){
                result.push_back(N / i);
            }
            result.push_back(i);
        }
    }
    if (N != 1) {  
        result.push_back(N);
    }
    result.push_back(1);
    return result;
}
vector<int> tmp, ans[M];
int n, k;
clock_t st, ed;
bool dfs(int sum, int id, int j){ // 和是多少，当前是第几个数字，已经用了几个数字
    // printf("sum = %d, id = %d, j = %d\n", sum, id, j);
    if(id >= (int)tmp.size()) return 0;
    if(sum > n) return 0;
    if(sum == n) {
        return (k == j);
    }
    // if(sum == n && k == j) return 1;
    return dfs(sum + tmp[id], id, j + 1) || \
    dfs(sum, id + 1, j);
}
int main(){
    // tmp = breakdown(5);
    // for (auto v : tmp){
    //     printf("%d ", v);
    // }
    // return 0;
    for (int i = 2; i <= 7; i++){
        for (int j = 1; j <= 300; j++){
            // printf("正在处理: %d %d\n", i, j);
            bool fl = 0;
            for (auto v : ans[i]){
                if(j % v == 0) {fl = 1; break;}
            }
            if(fl) continue;
            st = clock();
            tmp.clear();
            tmp = breakdown(j);
            n = j, k = i;
            if(dfs(0, 0, 0)) ans[i].push_back(j);
            ed = clock();
            printf("处理 %d %d, 耗时: %lf 秒\n", i, j, (double)(ed - st) / (double)10000);
        }
    }
    puts("success!");
    for (int i = 2; i <= 7; i++){
        // printf("ans[%d]有以下数字:\n", i);
        // for (auto v : ans[i]){
        //     printf(" %d,", v);
        // }
        for (int j = 0; j < ans[i].size(); j++){
            printf("inv[%d][%d] = %d, ", i, j + 1, ans[i][j]);
        }
        putchar('\n');
        // printf("}\n");
    }
    return 0;
}