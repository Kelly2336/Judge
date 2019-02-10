#include<stdio.h>
int main()
{
    int n,c=0;
    while(scanf("%d",&n)>=1)
    {
        c++;
        int a[20];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);

        }
        long long int p[20][20];
        long long int max=0;
        for(int i=0;i<n;i++)
        {
            p[i][i]=a[i];
            if(p[i][i]>max)max=p[i][i];
            for(int j=i+1;j<n;j++)
            {
                p[i][j]=p[i][j-1]*a[j];
                if(p[i][j]>max)max=p[i][j];
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",c,max);
    }
    return 0;
}
