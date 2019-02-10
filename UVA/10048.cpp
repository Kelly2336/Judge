//Floyd-Warshall
#include<stdio.h>
#include<iostream>
#define INF 10000000
using namespace std;
int d[105][105];
int main()
{
    int C,S,Q,cas=0;
    while(1)
    {
        scanf("%d%d%d",&C,&S,&Q);
        if(!C&&!S&&!Q)break;
        for(int i=1;i<=C;i++)
        {
            for(int j=1;j<=C;j++)
                d[i][j]=INF;
            d[i][i]=0;
        }
        int c1,c2,dd;
        while(S--)
        {
            scanf("%d%d%d",&c1,&c2,&dd);
            d[c1][c2]=dd;
            d[c2][c1]=dd;
        }
        for(int k=1;k<=C;k++)
        {
            for(int i=1;i<=C;i++)
            {
                for(int j=1;j<=C;j++)
                {
                    d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
                }
            }
        }
        if(cas)printf("\n");
        cas++;
        printf("Case #%d\n",cas);
        while(Q--)
        {
            scanf("%d%d",&c1,&c2);
            if(d[c1][c2]!=INF)printf("%d\n",d[c1][c2]);
            else printf("no path\n");
        }
    }
    return 0;
}
