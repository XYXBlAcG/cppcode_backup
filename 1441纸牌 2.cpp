//unfinished
#include <cstdio>
int check = 1;
int cishu[100];
int small = 100000;
int fan[1000010];
int atmp[1000010];
void judge(int in1, int in2){
    if (in1 < in2){
        if (small > in1){
        small = in1;
        }
    }else{
        if (small > in2){
        small = in2;
        }
    }
}
void fanzhuan(int in[],int cardlen){
    for (int i = 1; i <= cardlen; i++){
        fan[cardlen - i + 1] = in[i];
    }
}
//try1:正序排列
void try1(int card[],int cardlen){
    int tmp = 0;
    cishu[1] = 0;
    for (int i = 1; i <= cardlen - 1; i++){
        if (card[i] != i){
            tmp = i - card[i];
            card[i] = i;
            card[i + 1] -= tmp;
            cishu[1]++;
        }
    }
}
//try5:正序排列
void try5(int card[],int cardlen){
    int tmp = 0;
    cishu[2] = 0;
    for (int i = 1; i <= cardlen - 1; i++){
        if (card[i] != i){
            tmp = i - card[i];
            card[i] = i;
            card[i + 1] -= tmp;
            cishu[2]++;
        }
    }
}
//try3:正序的倒
// void try3(int card[],int cardlen){
//     int tmp = 0;
//     cishu[3] = 0;
//     for (int i = cardlen; i > 1; i--){
//         if (card[i] != i){
//             tmp = i - card[i];
//             card[i] = i;
//             card[i - 1] -= tmp;
//             cishu[3]++;
//         }
//     }
// }
//try2:倒序排列
// void try2(int card[], int cardlen){
//     int tmp = 0;
//     cishu[2] = 0;
//     for (int i = 1; i <= cardlen - 1; i++){
//         if (card[i] != (cardlen + 1 - i)){
//             tmp = cardlen + 1 - i - card[i];
//             card[i] = cardlen + 1 - i;
//             card[i + 1] -= tmp;
//             cishu[2]++;
//         }
//     }
// }
//try4:倒序的倒
// void try4(int card[],int cardlen){
//     int tmp = 0;
//     cishu[4] = 0;
//     for (int i = cardlen; i > 1; i--){
//         if (card[i] != (cardlen + 1 - i)){
//             tmp = cardlen + 1 - i - card[i];
//             card[i] = cardlen + 1 - i;
//             card[i - 1] -= tmp;
//             cishu[4]++;
//         }
//     }
// }
//做！
void dothis(int card[],int cardlen){
    try1(card, cardlen);
    fanzhuan(atmp, cardlen);
    try5(fan, cardlen);
    // try2(card, cardlen);
    // try3(card, cardlen);
    // try4(card, cardlen);
}

//检查操作
void checkact(int num, int id, int len){
    if (num != id){
        // check[id] = 1;
        check = 1;
    }else if (num != id + 1 - len){
        check = 1;
    }else{
        check = 0;
    }
}
int main(){
    //平均数
    //求和
    int n;
    scanf("%d",&n);
    int a[1000010];
    // int lencard = 0;
    int sum = 0, ava = 0, sign = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        // lencard++;
    }
    for (int i = 1; i <= n; i++){
        atmp[i] = a[i];
    }
    for (int i = 1; i <= n; i++){
        sum += a[i];
    }
    for (int i = 1; i <= n; i++){
        ava += i;
    }
    if (ava != sum){
        printf("-1");
        sign = -1;
    }
    if (sign != -1){
        // printf("%d", )
        // for (int i = 0; check == 1; i++){

        // }
        dothis(a, n);
        if (cishu[1] > cishu[2]){
            printf("%d", cishu[2]);
        }else{
            printf("%d", cishu[1]);
        }
        // for (int i = 1; i < 4; i++){
        //     judge(cishu[i], cishu[i + 1]);
        // }
        // printf("%d",small);
    }
    printf("\n");
    
    return 0;
}