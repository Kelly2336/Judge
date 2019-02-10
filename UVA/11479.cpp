#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        long int s[3];
        for(int j=0;j<3;j++)scanf("%ld",&s[j]);
        sort(s,s+3);
        printf("Case %d: ",i);
        if(s[0]+s[1]>s[2]&&s[2]-s[1]<s[0])
        {
            if(s[0]==s[2])printf("Equilateral\n");
            else if(s[0]==s[1]||s[1]==s[2])printf("Isosceles\n");
            else printf("Scalene\n");
        }
        else
        {
            printf("Invalid\n");
        }
    }
    return 0;
}
