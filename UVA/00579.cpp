#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    while(1)
    {
        int h=0,m=0;
        char a;
        while(1)
        {
            cin>>a;
            if(a==':')break;
            h=h*10+(a-'0');
        }
        for(int i=0;i<2;i++)
        {
            cin>>a;
            m=m*10+(a-'0');
        }
        if(h==0&&m==0)break;
        float degree=h*30+m/2.0-m*6;
        if(degree<0)degree+=360;
        if(degree>180)
        {
            degree=360-degree;
        }
        printf("%.3f\n",degree);
    }
    return 0;
}
