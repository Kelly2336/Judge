#include<stdio.h>
int main()
{
    int t=0;
    while(1)
    {
        t++;
        int n;
        scanf("%d",&n);
        if(n==0)break;
        printf("Game %d:\n",t);
        int ans[1010];
        for(int i=0;i<n;i++)scanf("%d",&ans[i]);
        while(1)
        {
            int g[1010];
            int A=0,B=0;
            for(int i=0;i<n;i++)
            {
                scanf("%d",&g[i]);
                if(ans[i]==g[i])A++;
            }
            if(g[0]==0)break;

            for(int i=1;i<=9;i++)
            {
                int ai=0,gi=0;
                for(int j=0;j<n;j++)
                {
                    if(ans[j]==i)ai++;
                    if(g[j]==i)gi++;
                }
                B+=(ai<gi)?ai:gi;
            }
            printf("    (%d,%d)\n",A,B-A);
        }
    }
    return 0;
}
