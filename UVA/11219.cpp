#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int t=1;t<=n;t++)
    {
        int d1,d2,m1,m2,y1,y2;
        char p1,p2;
        scanf("%d%c%d%c%d",&d1,&p1,&m1,&p2,&y1);
        scanf("%d%c%d%c%d",&d2,&p1,&m2,&p2,&y2);
        if(d1-d2<0)m1--;
        while(m1-m2<0)
        {
            m1+=12;
            y1--;
        }
        int age=y1-y2;
        printf("Case #%d: ",t);
        if(age<0)printf("Invalid birth date\n");
        else if(age>130)printf("Check birth date\n");
        else printf("%d\n",age);
    }
    return 0;
}
