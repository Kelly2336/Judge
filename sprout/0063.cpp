//Lotto
#include<stdio.h>
#include<string.h>
using namespace std;
int num[15];
int ans[6];
bool visit[15];
int k;

void solve(int cur,int i)
{
    if(cur==6)
    {
        for(int j=0; j<5; j++)
        {
            printf("%d ",num[ans[j]]);
        }
        printf("%d\n",num[ans[5]]);
        return;
    }
    if(cur+k-i<6)return;
    for(; i<k; i++)
    {
        if(!visit[i])
        {
            visit[i]=true;
            ans[cur]=i;
            solve(cur+1,i+1);
            visit[i]=false;
        }
    }
}

int main()
{
    int c=0;
    while(scanf("%d",&k)==1)
    {
        if(!k)break;
        if(c!=0)printf("\n");
        c++;
        for(int i=0; i<k; i++)
        {
            scanf("%d",&num[i]);
        }
        memset(visit,0,sizeof(visit));
        solve(0,0);
        //printf("\n");
    }
    return 0;
}
