#include <cstdio>
#include <algorithm>
using std::min;
#define fo(i,j,k) for(i=j;i<=k;i++)
int sg[105][105],vis[10005],cnt;
inline void init()
{
    int i,j,k;
    fo(i,0,100) if(i)
      fo(j,0,100) if(j && i!=j)
      {
          if(i==2 && j==1) continue;
          if(i==1 && j==2) continue;
          fo(k,0,i-1) vis[sg[k][j]]=cnt;
          fo(k,0,j-1) vis[sg[i][k]]=cnt;
          fo(k,1,min(i,j)) vis[sg[i-k][j-k]]=cnt;
          for(k=0;;k++) if(vis[k]!=cnt)
          {
              sg[i][j]=k;break;
          }
      }
}
int main(){
    init();
    for(int i = 0; i <= 99; i++){
        for(int j = 0; j <= 99; j++){
            printf("%d ", sg[i][j]);
        }printf("\n");
    }
    return 0;
}