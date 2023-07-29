#include <cstdio>
#include <algorithm>
// g++ 2423.cpp -o /Users/xiexie/Desktop/cpp/output/2423 -Wall -Wextra -g3 
// ./2423 > out_2423.txt < in_2423.txt
using std::max;
using std::min;
//大根堆
using std::push_heap;
using std::pop_heap;
const int N = 1e6 + 5;
int n, len;
int small[N];
int big[N];
int sml, bl;
//小根堆
void ins(int val){
    big[++bl] = val;
    for (int t = bl; t != 1; t >>= 1){
        if (big[t >> 1] > big[t]){
            std::swap(big[t >> 1], big[t]);
        }else{break;}
    }
}
void del(){
    big[1] = big[bl--];
    for (int i = 1, son;; i = son){
        son = i * 2;
        if (son < bl && big[son] > big[son + 1]){
            son++;
        }
        if (son <= bl && big[i] > big[son]){
            std::swap(big[i],big[son]);
        }else{
            break;
        }
    }
}
// int bigmin = -2e31 + 1, smallmax = 2e31 - 1;
//大根堆
void insb(int val){
    small[++sml] = val;
    for (int t = sml; t != 1; t >>= 1){
        if (small[t >> 1] < small[t]){
            std::swap(small[t >> 1], small[t]);
        }else{break;}
    }
}
void delb(){
    small[1] = small[bl--];
    for (int i = 1, son;; i = son){
        son = i * 2;
        if (son < bl && small[son] < small[son + 1]){
            son++;
        }
        if (son <= bl && small[i] < small[son]){
            std::swap(small[i],small[son]);
        }else{
            break;
        }
    }
}
int bigmin = 2e31 - 1;//大的中最小的 big small
int smallmax = -2e31 + 1;//小的中最大的 small big
// int bigmin , smallmax;
inline int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时
        x = x * 10 + (ch - '0');  // 将新读入的数字’加’在 x 的后面
        // x 是 int 类型，char 类型的 ch 和 ’0’ 会被自动转为其对应的
        // ASCII 码，相当于将 ch 转化为对应数字
        // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
        ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}
int main(){
    // a>>1 向下取整 
    scanf("%d",&n);
    // for (int i = 1; i <= n; i++){
    //     small[i] = smallmax;
    //     big[i] = bigmin;
    // }
    // std::make_heap(small, small + 1);
    // std::make_heap(big, big + 1);
    int mid = 0;
    for (int i = 1; i <= n; i++){
        int ju = read();
        // int addto = 0;// 1 small 0 big
        if (ju < mid) {
            // addto = 1;
            // smallmax = min(smallmax, ju);
        small[++sml] = ju; 
        push_heap(small + 1, small + sml + 1);
        } else {
            // addto = 0;
            // bigmin = max(bigmin, ju);
        // big[++bl] = ju; 
        ins(ju);
        // std::push_heap(big + 1, big + bl + 1);
        }
        if(!(abs(sml - bl) == 1) && !(sml == bl)){
            if(sml > bl){
                // printf("small 2 big\n");
                // pop_heap(small + 1, small + sml + 1);
                bigmin = small[1];
                
                // printf("small ml : %d \n",small[sml - 1]);
                // ins(small[sml--]);
                ins(small[1]);
                pop_heap(small + 1, small + sml + 1);
                smallmax = small[1];
                sml--;
            }else{
                // printf("big 2 small\n");
                //删除大的里面最小的 加到小的中
                // small[++sml] = big[1];
                small[++sml] = big[1];
                push_heap(small + 1, small + sml + 1);
                smallmax = big[1];
                del();
                bigmin = big[1];
            }
        }else{
            // printf("dont move\n");
            // pop_heap(small + 1, small + sml + 1);
            bigmin = big[1];
            smallmax = small[1];
        }
        if(i & 1){/*奇数个数*/if(bl > sml){/*printf("odd bigmin\n");*/mid = bigmin;}else{/*printf("odd smallmax\n");*/mid = smallmax;}}
        else{/*偶数个数*//*printf("even\n");*/mid = (smallmax + bigmin) >> 1;}

        printf("%d\n",mid);

    //     printf("small: ");
    //     for (int i = 1; i <= sml; i++){
    //         printf("%d ",small[i]);
    //     }printf("\nbig: ");
    //     for (int i = 1; i <= bl; i++){
    //         printf("%d ",big[i]);
    //     }printf("\n");
    //     printf("smallmax: %d\n", smallmax);
    //     printf("bigmin: %d\n", bigmin);
    // printf("\n");
        // std::push_heap(list, list + i + 1);
        // if(i & 1){printf("%d\n", list[(i >> 1) + 1]);}
        // else{printf("%d\n",(list[(i >> 1) + 1] + list[i >> 1]) >> 1);}
    }
    return 0;
}

// int flag = 0;
        // while(!(abs(sml - bl) == 1) && !(sml == bl)){
        //     flag = 1;
        //     if(sml > bl){
        //         pop_heap(small, small + sml + 1);
        //         bigmin = small[sml];
        //         ins(small[sml--]);
        //         // small[sml] = 0;
        //     }else{
        //         small[++sml] = big[1];
        //         smallmax = big[1];
        //         del();
        //     }
        // }
        // if(!flag){
        //     pop_heap(small, small + sml + 1);
        //     bigmin = big[1];
        //     smallmax = small[sml];
        // }
//re

// if (ju < mid) {
//             addto = 1;
//             // smallmax = min(smallmax, ju);
//         small[++sml] = ju; 
//         std::push_heap(small, small + sml + 1);}
//         else {
//             addto = 0;
//             // bigmin = max(bigmin, ju);
//         big[++bl] = ju; 
//         std::push_heap(big, big + bl + 1);}
//         // if(i & 1){;}else{;}
//         if(!(abs(sml - bl) == 1) && !(sml == bl)){
//             if(addto){
//                 pop_heap(small, small + sml + 1);
//                 bigmin = small[sml];
//                 // printf("small ml : %d \n",small[sml - 1]);
//                 ins(small[sml--]);
//             }else{
//                 //删除大的里面最小的 加到小的中
//                 small[++sml] = big[1];
//                 smallmax = big[1];
//                 del();
//             }
//         }else{
//             pop_heap(small, small + sml + 1);
//             bigmin = big[1];
//             smallmax = small[sml];
//         }
//         if(i & 1){/*奇数个数*/if(bl > sml){mid = smallmax;}else{mid = bigmin;}}
//         else{/*偶数个数*/mid = (smallmax + bigmin) >> 1;}