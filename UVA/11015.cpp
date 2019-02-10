//Floyd-Warshall
//APSP
#include<stdio.h>
using namespace std;
int main()
{
    int N,M,T=1;
    char name[25][12];
    int dis[25][25];
    while(1)
    {
        scanf("%d%d",&N,&M);
        if(!N)break;
        for(int i=1;i<=N;i++)
            scanf("%s",name[i]);
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
                dis[i][j]=-1;
            dis[i][i]=0;
        }
        int I,J,K;
        while(M--)
        {
            scanf("%d%d%d",&I,&J,&K);
            dis[I][J]=K;
            dis[J][I]=K;
        }
        for(int k=1;k<=N;k++)
        {
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=N;j++)
                {
                    int dd=dis[i][k]+dis[k][j];
                    if(dis[i][k]!=-1&&dis[k][j]!=-1)
                        if(dis[i][j]==-1||dd<dis[i][j])
                            dis[i][j]=dd;
                }
            }
        }
        int MIN=50000000;
        int ans=0;
        for(int i=1;i<=N;i++)
        {
            int sum=0;
            for(int j=1;j<=N;j++)
            {
                if(dis[i][j]==-1)
                {
                    sum=-1;
                    break;
                }
                else sum+=dis[i][j];
            }
            if(sum!=-1&&sum<MIN)
            {
                MIN=sum;
                ans=i;
            }
        }
        printf("Case #%d : %s\n",T,name[ans]);
        T++;
    }
    return 0;
}
