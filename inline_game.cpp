#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <istream>
using std::string;
namespace xyx{
    const int INLINE_GAME_DEFINE_N = 1e6 + 5;
    std::ifstream ain("act.db");
    std::ifstream pin("pwd.db");

    struct Account{
        string account, pwd, userKey, computerKey;
        Account(string a = "", string b = "", string c = "", string d = ""){
            account = a, pwd = b, userKey = c, computerKey = d;
        }
    };
    int acnt = 0, pcnt = 0;
    string act[INLINE_GAME_DEFINE_N], pwd[INLINE_GAME_DEFINE_N];
    bool cmp(Account a, Account b){
        return a.account < b.account;
    }
    std::vector<Account> Acc;
    void addaccount(Account acc){
        Acc.emplace_back(acc);
    }
    char rd[10005];
    void read(string& str){
        scanf("%s", rd), str = rd;
    }
    void readFile(){
        acnt = pcnt = 1;
        while (getline(ain, act[acnt])) acnt++;
        while (getline(pin, pwd[pcnt])) pcnt++;
        Acc.clear();
        for (int i = 1; i <= acnt; i++)
            addaccount((Account){act[i], pwd[i], "", ""});
        std::sort(Acc.begin(), Acc.end(), cmp);
    }
    void writeFile(){
        std::ofstream aout("act.db");
        std::ofstream pout("pwd.db");
        for (auto v : Acc){
            aout << v.account << '\n';
            pout << v.pwd << '\n';
        }
    }
    void Start(void){
        // do something.
    }
    int findAcc(Account acc){
        return std::lower_bound(Acc.begin(), Acc.end(), acc, cmp) - Acc.begin();
    }
    Account runCommand();
    Account toResigter();
    Account toLogin(){
        puts("Login.");
        puts("input your account and password. used space to split the two string.");
        Account guest;
        read(guest.account), read(guest.pwd);
        int finder = findAcc(guest);
        while(finder == Acc.end() - Acc.begin()){
            puts("No account founded. Try again. Type 'quit' to quit.");
            read(guest.account);
            if(guest.account == "quit") {runCommand(); return {};}
            read(guest.pwd);
            finder = findAcc(guest);
        }
        while(Acc[finder].pwd != guest.pwd){
            puts("Find the account but the wrong pwd. Type 'quit' to quit.");
            puts("To reinput the account, plz enter 'login'.");
            read(guest.pwd);
            if(guest.pwd == "quit"){runCommand(); return {};}
            if(guest.pwd == "login"){return toLogin();}
        }
        puts("Successful log in!");
        return guest;
    }
    Account toResigter(){
        puts("Resigter.");
        puts("input your account and password. used space to split the two string.");
        Account guest;
        read(guest.account), read(guest.pwd);
        int finder = findAcc(guest);
        while(finder != Acc.end() - Acc.begin()){
            puts("Account name already exist.");
            read(guest.account), read(guest.pwd);
            finder = findAcc(guest);
        }
        Acc.push_back(guest);
        writeFile();
        return guest;
    }
    void Admin(){
        puts("-----start------");
        for (auto v : Acc){
            printf("account = %s, pwd = %s\n", v.account.c_str(), v.pwd.c_str());
        }
        puts("-----end------");
    }
    void Quit(){
        puts("Goodbye!");
        Start();
    }
    Account runCommand(){
        readFile();
        puts("Start page.");
        puts("Please choose 'login' or 'reg'.");
        puts("Type 'quit' to quit.");
        string comd = "";
        read(comd);
        while(comd != "reg" && comd != "login" && comd != "quit" && comd != "loadadmin"){
            puts("Fail to load this command.");
            puts("command must be 'reg' or 'login'");
            read(comd);
        }
        Account guest;
        if(comd == "reg"){
            guest = toResigter();
            return guest;
        }else if(comd == "login"){
            guest = toLogin();
            return guest;
        }else if(comd == "loadadmin"){
            Admin();
            return guest;
        }
        Quit();
        return guest;
    }
}