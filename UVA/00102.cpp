#include<stdio.h>
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a[3][3];
    while(scanf("%d%d%d",&a[0][0],&a[0][1],&a[0][2])>=3)
    {
        for(int i=1;i<=2;i++)
            for(int j=0;j<3;j++)
                scanf("%d",&a[i][j]);
        int min=2147483647;
        int gi=0,bi=0,ci=0;
        for(int b=0;b<3;b++)
            for(int c=0;c<3;c++)
                for(int g=0;g<3;g++)
                {
                    if(b==g||g==c||b==c)continue;
                    int sum=0;
                    for(int i=0;i<3;i++)
                    {
                        if(i!=b)sum+=a[i][0];
                        if(i!=g)sum+=a[i][1];
                        if(i!=c)sum+=a[i][2];
                    }
                    //printf("%d\n",sum);
                    if(sum<min)
                    {
                        min=sum;
                        gi=g;bi=b;ci=c;
                    }
                }
        for(int i=0;i<3;i++)
        {
            if(bi==i)printf("B");
            else if(gi==i)printf("G");
            else printf("C");
        }
        printf(" %d\n",min);
    }
    return 0;
}
