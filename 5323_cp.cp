#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ull unsigned long long
#define inf 0x7fffffff
using namespace std;
const int N=3e5+10;
const int base=131;

ull h[N],p[N];
char str[N];
int sa[N];  ///sa[i]:下标从i开始的后缀
int n;  ///字符串长度

ull get(int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}

///二分下标从s1开始的子串和s2开始的子串的最长公共前缀
int get_max_common_prefix(int s1,int s2)
{
    int l=0,r=min(n-s1+1,n-s2+1);  ///边界r为二者长度的最小值
    while(l<r)
    {
        int mid=l+r+1>>1;
        if(get(s1,s1+mid-1)!=get(s2,s2+mid-1)) r=mid-1;
        else l=mid;
    }
    return l;
}

///比较下标从s1开始的后缀和s2开始的后缀的字典序
bool cmp(int s1,int s2)
{
    int l=get_max_common_prefix(s1,s2);
    int v1=s1+l>n ? -inf : str[s1+l];  ///先判断长度是否超过子串本身，若超过，则把最小值赋给该子串
    int v2=s2+l>n ? -inf : str[s2+l];
    return v1<v2;
}

int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);

    p[0]=1;  ///不能记p[0]初值！！
    for(int i=1;i<=n;i++)
    {
        h[i]=h[i-1]*base+str[i]-'a'+1;
        p[i]=p[i-1]*base;
        sa[i]=i;  ///下标
    }

    sort(sa+1,sa+1+n,cmp);

    for(int i=1;i<=n;i++) printf("%d ",sa[i]-1);   ///别忘了减1
    puts("");

    printf("0 ");  ///第一个子串与前一项最长公共前缀长度为0
    for(int i=2;i<=n;i++)
        printf("%d ",get_max_common_prefix(sa[i-1],sa[i]));

    return 0;
}

