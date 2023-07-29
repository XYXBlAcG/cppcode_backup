#include<iostream>
using namespace std;
int data[100];
int p=0;
int num=0; 
int x;
void resolve(int n,int min){
    if(n<2){
        num++;
        return ;
    }
    for(int i=min;i<=n;i++){
        if(n%i==0){
            resolve(n/i,i);    
        }
    }
}
int main()
{
        while(cin>>x)
        {
            resolve(x,2);
            printf("%d\n",num);
        }
}