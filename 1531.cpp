//wait...
#include <cstdio>
#include <cmath>
int x, y;
int online = 0;
int chess[8][8];
int nodo = 0;
int next = 0;
void fnote(int dir, /*int step,*/ int x1, int y1){//dir 0up 1up right 2right
    if (dir == 0){
        
    }
}
// void line(int x1, int y1, int x2 ,int y2){
//     if (x1 == x2){
//         online = 1;
//     }else if (y1 == y2){
//         online = 1;
//     }else if ((x1 + y1) == (x2 + y2)){
//         online = 1;
//     }else if ((x1 - y1) == (x2 - y2)){
//         online = 1;
//     }else{
//         online = 0;
//     }
// }
// void judge_between(int x1, int y1, int x2, int y2){
//     if (x1 == x2){
//         if(y1 > y2){
//             nodo = 0;
//             for (int i = 1; i <= y1 - y2; i++){
//                 if (chess[x1][y2+i] == -1){
//                     nodo++;
//                 }
//             }
//             if (nodo == 0){
//                 next = 1;
//             }else{
//                 next = 0;
//             }
//         }else{
//             nodo = 0;
//             for (int i = 1; i <= y2 - y1; i++){
//                 if (chess[x1][y1+i] == -1){
//                     nodo++;
//                 }
//             }
//             if (nodo == 0){
//                 next = 1;
//             }else{
//                 next = 0;
//             }
//         }
//     }else if(y1 == y2){
//         if(x1 > x2){
//             nodo = 0;
//             for (int i = 1; i <= x1 - x2; i++){
//                 if (chess[x2+i][y1] == -1){
//                     nodo++;
//                 }
//             }
//             if (nodo == 0){
//                 next = 1;
//             }else{
//                 next = 0;
//             }
//         }else{
//             nodo = 0;
//             for (int i = 1; i <= x2 - x1; i++){
//                 if (chess[x1+i][y1] == -1){
//                     nodo++;
//                 }
//             }
//             if (nodo == 0){
//                 next = 1;
//             }else{
//                 next = 0;
//             }
//         }
//     }else if((x1 + y1) == (x2 + y2) || (x1 - y1) == (x2 - y2)){
//         if (x1 > x2){
            
//         }
//     }
// }
int main(){
    int n;
    int list[210];
    
    for (int i = 1; i <= 8; i++){
        for (int x = 1; x <= 8; x++){
            chess[i][x] = -1;
        }
    }
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &list[i]);
    }

    return 0;
}