#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    char m[12][20]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};
    int n;
    scanf("%d",&n);
    for(int t=1;t<=n;t++)
    {
        char m1[20],m2[20],p;
        int month1,month2;
        int day1,day2;
        int year1,year2;
        scanf(" %s%d%c%d",m1,&day1,&p,&year1);
        scanf(" %s%d%c%d",m2,&day2,&p,&year2);
        int ans=0;
        ans-=(year1/4-year1/100+year1/400);
        ans+=(year2/4-year2/100+year2/400);
        for(int i=0;i<12;i++)
        {
            if(strcmp(m1,m[i])==0)month1=i+1;
            if(strcmp(m2,m[i])==0)month2=i+1;
        }
        if(year1==year2)
        {
            if(year1%400==0||(year1%4==0&&year1%100!=0))
            {
                if(month1<=2&&(month2>=3||(month2==2&&day2==29)))ans++;
            }
        }
        else
        {
            if(year1%400==0||(year1%4==0&&year1%100!=0))
            {
                if(month1<=2)ans++;
            }
            if(year2%400==0||(year2%4==0&&year2%100!=0))
            {
                if(month2==1||(month2==2&&day2<29))ans--;
            }
        }
        printf("Case %d: %d\n",t,ans);
    }
    return 0;
}
