#include<stdio.h>
#include<cstring>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        char a[60][1050];
        for(int i=0;i<m;i++)scanf("%s",a[i]);
        int t[1050][4];
        memset(t,0,sizeof(t));
        char c[]="ACGT";
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<4;k++)
                {
                    if(c[k]==a[i][j])
                    {
                        t[j][k]++;
                    }
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int max=0;
            for(int j=0;j<4;j++)
            {
                if(t[i][j]>t[i][max])max=j;
            }
            printf("%c",c[max]);
            sum+=(m-t[i][max]);
        }
        printf("\n%d\n",sum);
    }
    return 0;
}
