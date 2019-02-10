#include<stdio.h>
int main()
{
    int k;
    while(scanf("%d",&k)==1)
    {
        int r=0;
        int a[10000][3];
        for(int y=k+1;y<=2*k;y++)
        {
            if((y*k)%(y-k)==0)
            {
                a[r][0]=k;
                a[r][1]=(y*k)/(y-k);
                a[r][2]=y;
                r++;
            }
        }
        printf("%d\n",r);
        for(int i=0;i<r;i++)
        {
            printf("1/%d = 1/%d + 1/%d\n",a[i][0],a[i][1],a[i][2]);
        }
    }
    return 0;
}
