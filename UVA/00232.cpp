#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    int r,c,puzzle=0;
    while(1)
    {
        scanf("%d",&r);
        if(r==0)break;
        scanf("%d",&c);
        if(puzzle)printf("\n");
        puzzle++;
        char a[15][15];
        int n[15][15];
        memset(n,0,sizeof(n));
        for(int i=1;i<=r;i++)
        {
            scanf("%s",a[i]+1);
        }
        for(int i=0;i<=r+1;i++)a[i][0]='*';
        for(int i=0;i<=r+1;i++)a[i][c+1]='*';
        for(int i=0;i<=c+1;i++)a[0][i]='*';
        for(int i=0;i<=c+1;i++)a[r+1][i]='*';

        int num=0;
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(a[i][j]!='*'&&(a[i][j-1]=='*'||a[i-1][j]=='*'))
                {
                    num++;
                    n[i][j]=num;
                }
            }
        }
        /*for(int i=0;i<=r+1;i++)
        {
            for(int j=0;j<=c;j++)
                printf("%d ",n[i][j]);
            printf("\n");
        }*/
        printf("puzzle #%d:\n",puzzle);
        printf("Across\n");
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(n[i][j])
                {
                    printf("%3d.",n[i][j]);
                    while(a[i][j]!='*'&&j<=c)
                    {
                        printf("%c",a[i][j]);
                        j++;
                    }
                    printf("\n");
                }
            }
        }
        printf("Down\n");
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(n[i][j]&&a[i-1][j]=='*')
                {
                    printf("%3d.",n[i][j]);
                    int t=i;
                    while(a[t][j]!='*'&&t<=r)
                    {
                        printf("%c",a[t][j]);
                        t++;
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}
