#include<stdio.h>
using namespace std;
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        int a[105][105];
        int x[105]={0};
        int y[105]={0};
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j])
                {
                    x[i]++;
                    y[j]++;
                }
            }
        }
        int xi=0,yi=0;
        int xn=0,yn=0;
        for(int i=1;i<=n;i++)
        {
            if(x[i]%2)
            {
                xn++;
                xi=i;
            }
            if(y[i]%2)
            {
                yn++;
                yi=i;
            }
        }
        if(!xn&&!yn)printf("OK\n");
        else if(xn>1||yn>1)printf("Corrupt\n");
        else printf("Change bit (%d,%d)\n",xi,yi);
    }
    return 0;
}
