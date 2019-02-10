/*
ID: whitech1
TASK: ride
LANG: C++
*/
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{

    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);

    char a[12],b[12];
    scanf("%s%s",a,b);
    int sum_a=1,sum_b=1;
    for(int i=0;i<strlen(a);i++)
    {
        sum_a*=(a[i]-'A'+1);
    }
    for(int i=0;i<strlen(b);i++)
    {
        sum_b*=(b[i]-'A'+1);
    }
    if( sum_a%47 == sum_b%47 )printf("GO\n");
    else printf("STAY\n");
    //printf("%d %d",sum_a,sum_b);
    return 0;
}
