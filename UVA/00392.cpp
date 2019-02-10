#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int a[9];
    while(1)
    {
        cin>>a[8];
        if(cin.fail())break;
        for(int i=7;i>=0;i--)
        {
           scanf("%d",&a[i]);
        }
        int not_zero=0;
        for(int i=8;i>=1;i--)
        {
            if(a[i]<0)
            {
                if(not_zero!=0)printf(" - ");
                else printf("-");
                a[i]*=-1;
                if(a[i]>1)printf("%d",a[i]);
            }
            else if(a[i]>0)
            {
                if(not_zero!=0)printf(" + ");
                if(a[i]>1)printf("%d",a[i]);
            }
            if(a[i]!=0)
            {
                printf("x");
                if(i>1)printf("^%d",i);
                not_zero++;
            }
        }
        if(not_zero==0)
        {
            printf("%d",a[0]);
        }
        else if(a[0]>0)
        {
            printf(" + %d",a[0]);
        }
        else if(a[0]<0)
        {
            printf(" - %d",a[0]*-1);
        }
        printf("\n");
    }
    return 0;
}
