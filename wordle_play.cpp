#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <random>
#include <ctime>
using std::ifstream;
using std::string;
using std::mt19937;
using std::cin;
using std::cout;
const int N = 6e3+10;
int n = 5757;
char word_bank[N][10], user[10], crt[10], ano[10];
mt19937 frand((unsigned)time(0));

bool finds(char a){
    for(int i = 1; i <= 5; i++)if(crt[i] == a)return 1;
    return 0;
}

int main(){
    ifstream fin("sgb-words.txt");
    for(int i = 1; i <= n; i++){
        fin.getline(word_bank[i] + 1, 6);
    }
    fin.close();
    while(1){
        int tmp = (int)(frand() % (long long)n + 1ll);
        for(int i = 1; i <= 5; i++)crt[i] = word_bank[tmp][i];
        bool right = 0;
        int i = 6;
        for(; i >= 1; i--){
            right = 0;
            if(i > 3){
                printf("Please enter a word with five letters, you now have %d chances.\n", i);
            }else{
                printf("Please enter a word with five letters, you now have only %d chances.\n", i);
            }
            scanf("%s", user+1);
            bool find = 0;
            for(int j = 1; j <= 5757; j++){
                find = 1;
                for(int k = 1; k <= 5; k++){
                    if(user[k] != word_bank[j][k])find = 0;
                }
                if(find)break;
            }
            if(!find){
                printf("You have just entered an non-existent word, please try again.");
                i++;
                continue;
            }
            for(int i = 1; i <= 5; i++){
                if(user[i] == crt[i])printf("Y");
                else if(finds(user[i])){printf("P");right = 1;}
                else {printf("N");right = 1;}
            }
            printf("\n");
            if(!right)break;
        }
        if(!right){
            if(i > 3){
                printf("Wow, you have found the answer in just %d steps, that's really amazing! Do you want to play again?\n", 6-i+1);
            }else{
                printf("You have found the answer in %d steps. Do you want to play again?\n", 6-i+1);
            }
        }else{
            printf("It's a pity that you didn't find the correct words in six chances, the correct words is %s.", crt+1);
            printf("Do you want to try again?\n");
        }
        printf(" If you want, please enter Y or N: ");
        scanf("%s", ano+1);
        if(ano[1] == 'N'){
            printf("Thanks for playing this game, goodbye!");
            system("clear");
            return 0;
        }
        system("clear");
    }
    return 0;
}
