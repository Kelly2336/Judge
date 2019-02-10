/*
ID: whitech1
TASK: friday
LANG: C++
*/
#include<stdio.h>
#include<iostream>
using namespace std;

bool isleap(int y)
{
    if(y%4)return false;
    if(y%400==0)return true;
    if(y%100==0)return false;
    return true;//y%4==0
}

int main()
{

    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);

    int n;
    scanf("%d",&n);

    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int cnt[7]={0};
    int now=0;
    cnt[0]++;
    for(int i=1;i<=11;i++)
    {
        now+=month[i-1];
        now%=7;
        cnt[now]++;
    }
    for(int i=1;i<n;i++)
    {
        int year=1900+i;
        for(int j=0;j<12;j++)
        {
            if(j==0)now+=month[11];
            else now+=month[j-1];
            if(j==2&&isleap(year))now++;
            now%=7;
            cnt[now]++;
        }
    }
    for(int i=0;i<6;i++)
    {
        printf("%d ",cnt[i]);
    }
    printf("%d",cnt[6]);
    cout<<endl;
    return 0;
}
