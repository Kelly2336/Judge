#include<stdio.h>
#include<cstring>
using namespace std;
int m,n;
char a[105][105];
int idx[105][105];
void dfs(int i,int j,int id)
{
    if(i<0||i>=m||j<0||j>=n)return;
    if(idx[i][j]==0&&a[i][j]=='@')
    {
        idx[i][j]=id;
        for(int x=-1;x<=1;x++)
        {
            for(int y=-1;y<=1;y++)
            {
                if(x!=0||y!=0)
                {
                    dfs(i+x,j+y,id);
                }
            }
        }
    }
}
int main()
{
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(m==0&&n==0)break;
        for(int i=0; i<m; i++)
        {
            scanf("%s",a[i]);
        }
        memset(idx,0,sizeof(idx));
        int ans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(idx[i][j]==0&&a[i][j]=='@')
                {
                    dfs(i,j,++ans);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
