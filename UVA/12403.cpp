#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    int sum=0;
    while(T--)
    {
        char s[15];
        scanf("%s",s);
        if(strcmp(s,"donate")==0)
        {
            int money;
            scanf("%d",&money);
            sum+=money;
        }
        else if(strcmp(s,"report")==0)
        {
            printf("%d\n",sum);
        }
    }
    return 0;
}
