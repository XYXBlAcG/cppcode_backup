#include<bits/stdc++.h>
#define REP(i,first,last) for(int i=first;i<=last;++i)
#define DOW(i,first,last) for(int i=first;i>=last;--i)
using namespace std;
const int MAXN=1e5+5;
const int SQRT_MAXN=233;
int n;
int len,len_;//记录块长
int id[MAXN];//记录每个点所属的块
int l[MAXN],r[MAXN];//记录每个块的区间
long long lazy[SQRT_MAXN];//记录标记
long long arr[MAXN];//记录原序列
long long sor[MAXN];//记录排完序的序列
void Sort(int id)//排序操作
{
    REP(i,l[id],r[id])
    {
        sor[i]=arr[i];
    }
    sort(sor+l[id],sor+r[id]+1);
}
void Updata(int left,int right,long long add)//修改操作
{
    if(id[left]==id[right])//在同一个块就暴力修改然后重新排序
    {
        REP(i,left,right)
        {
            arr[i]+=add;
        }
        Sort(id[left]);
        return;
    }
    REP(i,id[left]+1,id[right]-1)//对于中间的块直接修改标记就可以了
    {
        lazy[i]+=add;
    }
    //对于两边不完整的块保留修改后排序
    REP(i,left,r[id[left]])
    {
        arr[i]+=add;
    }
    Sort(id[left]);
    REP(i,l[id[right]],right)
    {
        arr[i]+=add;
    }
    Sort(id[right]);
}
int Smaller(int id,long long x)//二分
{
    int left=l[id];//二分的范围
    int right=r[id];
    int answer=-1;
    int middle;
    while(left<=right)
    {
        middle=(left+right)>>1;
        if(sor[middle]+lazy[id]/*需要加上标记*/<x)
        {
            answer=middle;
            left=middle+1;
        }
        else
        {
            right=middle-1;
        }
    }
    if(answer==-1)//可能会没有答案,即全部大于等于
    {
        return 0;
    }
    return answer-l[id]+1;
}
int Query(int left,int right,long long x)//查询操作
{
    if(right-left<len_)//对于小范围的数据,直接暴力查询
    {
        int result=0;
        REP(i,left,right)
        {
            if(arr[i]+lazy[id[i]]<x)
            {
                result++;
            }
        }
        return result;
    }
    int result=0;
    REP(i,id[left]+1,id[right]-1)//对于完整的快二分查询
    {
        result+=Smaller(i,x);
    }
    //对于不完整的块直接暴力查询
    REP(i,left,r[id[left]])
    {
        if(arr[i]+lazy[id[left]]<x)
        {
            result++;
        }
    }
    REP(i,l[id[right]],right)
    {
        if(arr[i]+lazy[id[right]]<x)
        {
            result++;
        }
    }
    return result;
}
int main()
{
    scanf("%d",&n);
    REP(i,1,n)
    {
        scanf("%lld",&arr[i]);
    }
    len=sqrt(n);//预处理
    len_=len*3;
    id[1]=0;
    l[0]=1;
    REP(i,2,n)
    {
        id[i]=(i-1)/len;
        if(id[i]^id[i-1])
        {
            l[id[i]]=i;
            r[id[i-1]]=i-1;
        }
    }
    r[id[n]]=n;
    REP(i,0,id[n])
    {
        Sort(i);
    }
    int opt,left,right;
    long long x;
    REP(i,1,n)
    {
        scanf("%d%d%d%lld",&opt,&left,&right,&x);
        if(opt==0)
        {
            Updata(left,right,x);
        }
        if(opt==1)
        {
            printf("%d %d %lld %d\n",left, right, x*x,Query(left,right,x*x));
        }
        // debug();
    }
    return 0;
}