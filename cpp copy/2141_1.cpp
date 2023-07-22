
#include<iostream>
#include<algorithm>  
#include<vector>  
using namespace std;  
bool next(vector<int> &v)//注意是引用   
{  
    int i;  
    for(i=v.size()-1;i>=1;i--)  
    {//从数组后面往前找到第一个比后面的数小的地方   
        if(v[i-1]<v[i])   
            break;  
    }  
    if(i==0)//整个数组都是逆序，说明是已是排列最后一个   
        return false;//没有下一个   
    else  
    {  
        int t=v[i-1],pos=i;  
        for(int j=i;j<v.size();j++)  
        {  
            if(v[j]>t && v[j]<=v[pos])//再往后找比v[i-1]大的数中最小的一个 //2014.10.1把<改成<=,否则输入有重复数字时会出现bug
                pos=j;  
        }  
        v[i-1]=v[pos];  
        v[pos]=t;//交换   
		//sort(v.begin()+i,v.end());//从小到达排序
		reverse(v.begin()+i,v.end());//此时正好逆序，只需反转即可从小到达排序 
        return true;//还有下一个   
    }  
}  
void printVctor(vector<int> v)  
{  
    for(int i=0;i<v.size();++i)  
        cout<<v[i]<<" ";  
    cout<<endl;  
}  
int main()  
{  
    int n = 0;
    scanf("%d",&n);
    int a[n+5];  
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    vector<int> v(a,a+n);  
    do  
    {  
        printVctor(v);  
    }while(next(v));  
    return 0;  
}
