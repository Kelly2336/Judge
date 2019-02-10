#include<stdio.h>
#include<string.h>
int main()
{
    int t=0;
    while(1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)break;
        t++;
        char map[100][100];
        for(int i=0;i<n;i++)
            scanf("%s",map[i]);
        int ans[100][100];
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='*')
                {
                    for(int x=-1;x<=1;x++)
                    {
                        for(int y=-1;y<=1;y++)
                        {
                            if(i+x<n&&i+x>=0&&j+y>=0&&j+y<m)
                            {
                                ans[i+x][j+y]++;
                            }
                        }
                    }
                }
            }
        }
        if(t>1)printf("\n");
        printf("Field #%d:\n",t);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='*')
                    printf("*");
                else printf("%d",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
