#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using std::swap;
double in[120][5];
int cnt = 1;
int t, ans;
int res[120] = {0};
std::vector<int> result;

int read(){
    char c = getchar();
    if(c >= '2' && c <= '9') return (c - '0');
    if(c == 'O') return 10;
    if(c == 'A') return 1;
    if(c == 'J') return 11;
    if(c == 'Q') return 12;
    if(c == 'K') return 13;
}
void suan(int in2){
    if (ans == 1){
        return;
    }
    if (in2 == 1){
        if(in[cnt][1]  >= 24 - 1e-5 && in[cnt][1] <= 24 + 1e-5){
            ans = 1;
        }
        return;
    }
    for (int i = in2; i >= 1; i--){
        swap(in[cnt][i],in[cnt][in2]);
        for (int z = in2 - 1; z >= 1; z--){
            swap(in[cnt][z],in[cnt][in2 - 1]);
            //+
            double tmp = in[cnt][in2 - 1];
            in[cnt][in2 - 1] = tmp + in[cnt][in2];
            suan(in2 - 1);
            //-
            in[cnt][in2 - 1] = tmp - in[cnt][in2];
            suan(in2 - 1);
            //*
            in[cnt][in2 - 1] = tmp * in[cnt][in2];
            suan(in2 - 1);
            ///
            if (in[cnt][in2] <= -1e-5 || in[cnt][in2] >= 1e-5){
                in[cnt][in2 - 1] = tmp / in[cnt][in2];
                suan(in2 - 1); 
            }
            in[cnt][in2 - 1] = tmp;
            swap(in[cnt][z],in[cnt][in2 - 1]);
            
        }
        swap(in[cnt][i],in[cnt][in2]);
    }
}
int main(){
    
    scanf("%d",&t);
    for (cnt = 1; cnt <= t; cnt++){
        getchar();
        in[cnt][1] = read();
        in[cnt][2] = read();
        in[cnt][3] = read();
        in[cnt][4] = read();
        suan(4);
        if (ans == 1){
            res[cnt] = 1;
        }else{
            res[cnt] = 0;
        }
        ans = 0;
    }
    for (int i = 1; i <= t; i++){
        printf("%s ", res[i] ? "true" : "false");
        
        // if (i % 10 == 0){
        //     printf("\n");
        // }
    }
    return 0;
}