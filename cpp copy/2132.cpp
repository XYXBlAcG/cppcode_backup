#include <cstdio>
#include <iostream>

int accept[12]; 
// char word[12][25];
// char ans[24][25];
char start;
// char dragon[300] = {0};
int len = 0, n;
int lenf = 0;
int word1 = 0;
int word2 = 0;
// 

struct wor{
    char lett[25];
    int le;
}word[12];
int getlen(const wor& n){
    int x = 1;
    for (int i = 1; n.lett[i] >= 32; i++)x++;
    return x;
}
int lenlist[12];
// void heti(int r, int i, int z){
//     int drl = 0; for (; dragon[drl] != '0'; drl++);
//     for (int q = 1; q <= r; q++){
//         dragon[drl + q] = 
//     }
// }

void lian(int i, int z){
    // if (i > n){
        if (len > lenf){
            lenf = len;
            printf("%d\n",lenf);
        }
        // return;
    // }
    for (int q = 1; q <= n; q++){
        // lian(i,z);
        int a = q;
        int min = std::min(word[i].le,word[z].le);
        printf("min:%d\n",min);
        int same = 0;
                for (int r = 1; r <= min; r++){
                    printf("%c %c\n",word[i].lett[min - r + 1],word[z].lett[r]);
                    if (word[i].lett[min - r + 1] == word[z].lett[r]){
                        same++;
                    }else{
                        break;
                    }
                }
                printf("same:%d ",same);
                // printf("ined\n");
                    if (accept[i] == 0 || accept[z] == 0){
                        break;
                    }
                    if (same == min){
                        // printf("ined\n");
                        continue;
                    }else{
                        int tmp;
                        accept[i]--;
                        accept[z]--;
                        printf("same:%d ",same);
                        // len += (sizeof(word[i]) + sizeof(word[z]) - same);
                        len += word[z].le - same;
                        printf("len:%d\n",len);
                        lian(z, a);
                        len -= word[z].le - same;
                        // len -= (sizeof(word[i]) + sizeof(word[z]) - same);
                        accept[i]++;
                        accept[z]++;
                    }
    }

}
int main(){
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        scanf("%d",&accept[i]);
    }
    for (int i = 1; i <= n; i++){
        scanf("%s",word[i].lett);
        // word[i].le = sizeof(word[i].lett);
        word[i].le = getlen(word[i]);
        printf("%d\n",word[i].le);
    }
    std::cin >> start;
    for (int i = 1; i <= n; i++){
        lian(1,1);
    }
    printf("%d\n",lenf);
    return 0;
}