#include<stdio.h>
#include<cmath>
int main()
{
    int i=0;
    char c[10000];
    double l[10000][4];
    while(1)
    {
        i++;
        scanf(" %c",&c[i]);
        if(c[i]=='*')break;
        if(c[i]=='r')
        {
            for(int j=0;j<4;j++)scanf("%lf",&l[i][j]);
        }
        else if(c[i]=='c')
        {
            for(int j=0;j<3;j++)scanf("%lf",&l[i][j]);
        }
    }
    i-=1;
    double p[10000][2];
    for(int k=1;k<10000;k++)
    {
        scanf("%lf%lf",&p[k][0],&p[k][1]);//x,y
        if(p[k][0]==9999.9&&p[k][1]==9999.9)break;
        bool contain=false;
        for(int g=1;g<=i;g++)
        {
            if(c[g]=='c')
            {
                if(pow((l[g][0]-p[k][0]),2)+pow((l[g][1]-p[k][1]),2)<pow(l[g][2],2))
                {
                    printf("Point %d is contained in figure %d\n",k,g);
                    contain=true;
                }
            }
            else if(c[g]=='r')
            {
                if(p[k][0]>l[g][0]&&p[k][0]<l[g][2]&&p[k][1]<l[g][1]&&p[k][1]>l[g][3])
                {
                    printf("Point %d is contained in figure %d\n",k,g);
                    contain=true;
                }
            }
        }
        if(!contain)printf("Point %d is not contained in any figure\n",k);
    }
    return 0;
}
