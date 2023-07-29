#include <cstdio>
#include <algorithm>
using std::max;
const int N = 2005;
int map[N][N];
int mnow[N];
int mup[N];
int dan[N];
int lef[N];
// int map2[N * N];
int n, m;
int dlen;
int max1;
int ansx, ansy, nowi;
void ins(int i){
    // for (int j = 1; j <= m + 1; j++){
            for (; mnow[dan[dlen]] >= mnow[i] && dlen > 0; dlen--){
                 max1 = std::max(max1, mnow[dan[dlen]] * (i - lef[dan[dlen]] - 1));
            }
            lef[i] = dan[dlen];
            dan[++dlen] = i;
        // }
}
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        getchar();
        for(int j = 1; j <= m; j++){
			char ch = getchar();
			map[i][j] = (int)ch - '0';
		}
    }
    for (int i = 1; i <= n; i++){
                //1
        for (int j = 1; j <= m; j++){
            if(i != 1 && map[i][j] != map[i - 1][j]){
                mnow[j] = mup[j] + 1;
            }else if(i == 1){
                mnow[j] = 1;
            }else{
                mnow[j] = 1;
            }
        }
        //2
        mnow[0] = -1; dan[0] = 0;
        for(int j = 1; j <= m + 1; j++){
            if(j != 1 && map[i][j] == map[i][j - 1]){
                for(;dlen>=1;dlen--){
                    max1 = std::max(max1, mnow[dan[dlen]] * (j - lef[dan[dlen]] - 1));
                }
                dan[0] = j - 1;
                dlen = 0;
                //lef[j] = dan[dlen];
                // printf("a:%d \n",mnow[j]);
            }
            //mnow[j] = (map[i][j] != map[i - 1][j] ? mup[j] + 1 : 1);
            ins(j);
            // printf("b:%d \n",mnow[j]);
            
        }
        
        //3
        dlen = 0;
        for (int j = 1; j <= m; j++){
            mup[j] = mnow[j];
            lef[j] = 0;
            dan[j] = 0;
            mnow[j] = 0;
        }
    }
    // printf("x:%d y:%d\n", ansx, ansy);
    printf("%d\n", max1);
    return 0;
}

//output map
// for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){
    //         printf("%d", map[i][j]);
    //     }printf("\n");
    // }