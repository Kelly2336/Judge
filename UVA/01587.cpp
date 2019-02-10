#include<stdio.h>
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int a[6][2];
    while(scanf("%d%d",&a[0][0],&a[0][1])==2)
    {
        for(int i=1; i<6; i++)scanf("%d%d",&a[i][0],&a[i][1]);
        for(int i=0; i<6; i++)
        {
            if(a[i][0]>a[i][1])swap(&a[i][0],&a[i][1]);
        }
        bool possible=true;
        for(int i=0; i<6; i++)
        {
            int same=0,line1=0,line0=0;
            for(int j=0; j<6; j++)
            {
                if(i!=j)
                {
                    if(a[i][0]==a[j][0]&&a[i][1]==a[j][1])same++;
                    if(a[i][0]==a[j][0]||a[i][0]==a[j][1])line0++;
                    if(a[i][1]==a[j][0]||a[i][1]==a[j][1])line1++;
                }
            }
            if(same<1||line0<3||line1<3)
            {
                possible=false;
                //break;
            }
            //printf("%d %d %d\n",same,line0,line1);
        }
        if(possible)printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
