#include<stdio.h>
int main()
{
    int b,s,cas=0;
    while(scanf("%d%d",&b,&s)==2&&(b!=0||s!=0))
    {
        cas++;
        int man[10000];
        int woman[10000];
        for(int i=0;i<b;i++)scanf("%d",&man[i]);
        for(int i=0;i<s;i++)scanf("%d",&woman[i]);
        printf("Case %d: ",cas);
        if(b<=s)
        {
            printf("0\n");
            continue;
        }
        printf("%d ",b-s);
        int min=100;
        for(int i=0;i<b;i++)
        {
            if(man[i]<min)min=man[i];
        }
        printf("%d\n",min);
    }
    return 0;
}
