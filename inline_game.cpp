#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <istream>
using std::string;
const int N = 1e6 + 5;
struct Account{
    string account, pwd, userKey, computerKey;
    Account(){
        account = pwd = userKey = computerKey = "";
    }
};
int cnt = 0;
string FileInfo[N];
bool cmp(Account a, Account b){
    return a.account < b.account;
}
std::vector<Account> Acc;
void addaccount(Account acc){
    Acc.push_back(acc);
    
}
char rd[10005];
void read(string& str){
    scanf("%s", rd), str = rd;
}
void readFile(){
    cnt = 1;
    std::ifstream fin("actinfo.database");
    while (getline(fin, FileInfo[cnt])) cnt++;
    for (int i = 1; i <= cnt; i++){
        
    }
}
void toResigter();
void toLogin(){
    Account guest;
    read(guest.account), read(guest.pwd);
    
}
void toResigter(){
    Account guest;
    read(guest.account), read(guest.pwd);
    
}
void runCommand(){
    string comd = "";
    read(comd);
    while(comd != "reg" && comd != "login"){
        puts("Fail to load this command.");
        puts("command must be 'reg' or 'login'");
        read(comd);
    }
    if(comd == "reg"){
        toResigter();
    }else{
        toLogin();
    }
}