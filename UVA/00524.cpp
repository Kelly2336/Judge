//Runtime Error

#include<stdio.h>
#include<string.h>
using namespace std;

int n;
int a[30];
int visit[30];
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
bool isp[60];

void dfs(int cur)
{
    if( cur==n && isp[a[0]+a[n-1]] )
    {
        for(int i=0;i<n-1;i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n-1]);
        return;
    }
    else
    {
        for(int i=2;i<=n;i++)
        {
            if(!visit[i] && isp[i+a[cur-1]])
            {
                a[cur]=i;
                visit[i]=1;
                dfs(cur+1);
                visit[i]=0;
            }
        }
    }
}

int main()
{
    memset(isp,0,sizeof(isp));
    for(int i=0;i<sizeof(prime);i++)isp[prime[i]]=true;

    memset(visit,0,sizeof(visit));

    int k=0;

    while(scanf("%d",&n)==1 && n)
    {
        printf("Case %d:\n",++k);
        a[0]=1;
        visit[1]=1;
        dfs(1);
        printf("\n");
    }

    return 0;
}
