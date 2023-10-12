#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <random>
#include <ctime>
#include <iostream>
// struct FileIO{
//     FileIO(){
//         freopen("in.in", "r", stdin);
//         freopen("out.out", "w", stdout);
//     }
//     ~FileIO(){
//         fclose(stdin);
//         fclose(stdout);
//     }
// };
time_t st, ed;
int main(){
    int cishu = 10;
    int cnt = 0;
    while(cishu) {
        cnt++;
        #ifdef _WIN32
            system("gen.exe > gen.out");
            st = clock();
            system("my.exe < gen.out > my.out");
            ed = clock();
            system("good.exe < gen.out > good.out");
            if(system("fc /W my.out good.out")){
                puts("WA.");
                exit(0);
            }else{
                printf("AC. in %.0lf ms.\n", double(ed - st));
            }
        #else
            system("gen > gen.out");
            st = clock();
            system("my < gen.out > my.out");
            ed = clock();
            system("good < gen.out > good.out");
            if(system("diff -w my.out good.out")){
                puts("WA.");
                exit(0);
            }else{
                printf("AC. in %.0lf ms.\n", double(ed - st));
            }
        #endif
        cishu--;
    }
    
}