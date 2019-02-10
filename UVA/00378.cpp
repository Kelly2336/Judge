//解二元一次聯立方程式
#include<stdio.h>
using namespace std;
int main()
{
    int n;
    int x[4],y[4];
    printf("INTERSECTING LINES OUTPUT\n");
    scanf("%d",&n);
    while(n--)
    {
        for(int i=0;i<4;i++)scanf("%d%d",&x[i],&y[i]);
        int x01=x[0]-x[1];
        int y01=y[0]-y[1];
        int x23=x[2]-x[3];
        int y23=y[2]-y[3];
        if(!x01&&!x23)//垂直*2
        {
            if(x[0]==x[3])printf("LINE\n");
            else printf("NONE\n");
        }
        else if(!y01&&!y23)//水平*2
        {
            if(y[0]==y[3])printf("LINE\n");
            else printf("NONE\n");
        }
        else if(!x01)//L01垂直
        {
            printf("POINT");
            printf(" %.2lf",x[0]*1.0);
            printf(" %.2lf\n",y23*1.0*(x[0]-x[3])/x23+y[3]);
        }
        else if(!x23)//L23垂直
        {
            printf("POINT");
            printf(" %.2lf",x[2]*1.0);
            printf(" %.2lf\n",y01*1.0/x01*(x[2]-x[0])+y[0]);
        }
        else
        {
            if(x01*y23==x23*y01)
            {
                if((x[0]-x[3])*y23==x23*(y[0]-y[3]))printf("LINE\n");
                else printf("NONE\n");
            }
            else
            {
                double t1=y01*1.0/x01;
                double t2=y23*1.0/x23;
                double xx=(y[1]-y[2]+x[2]*t2-x[1]*t1)/(t2-t1);
                double yy=((x[2]-x[1])*t1*t2+y[1]*t2-y[2]*t1)/(t2-t1);
                printf("POINT");
                printf(" %.2lf %.2lf\n",xx,yy);
            }
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
