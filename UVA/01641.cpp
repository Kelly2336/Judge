#include<stdio.h>
using namespace std;
int main()
{
    int h,w;
    while(scanf("%d%d",&h,&w)==2)
    {
        int sum=0;
        while(h--)
        {
            char s[120];
            scanf(" %s",s);
            bool cnt=false;
            for(int i=0;i<w;i++)
            {
                if(s[i]=='/'||s[i]=='\\')
                {
                    sum+=1;
                    cnt=!cnt;
                }
                else if(s[i]=='.')
                {
                    if(cnt)sum+=2;
                }
            }
        }
        printf("%d\n",sum/2);
    }
    return 0;
}
