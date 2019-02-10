#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        int N;
        scanf("%d",&N);
        char a[110];
        scanf(" %s",a);
        int sum=0;
        for(int i=0;i<N;i++)
        {
            if(a[i]=='.')
            {
                sum+=1;
                for(int j=0;j<=2;j++)
                {
                    a[i+j]='#';
                }
            }
        }
        printf("Case %d: %d\n",t,sum);
    }
    return 0;
}
