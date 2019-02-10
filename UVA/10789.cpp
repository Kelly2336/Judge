#include<stdio.h>
#include<ctype.h>
#include<cstring>
int main()
{
    int prime[2010];
    memset(prime,0,2010);
    prime[0]=1;
    prime[1]=1;
    for(int i=2;i<1015;i++)
    {
        if(!prime[i])
        {
            for(int j=i*2;j<2010;j+=i)prime[j]=1;
        }
    }
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        char a[2010];
        int num[1000]={0};
        scanf(" %s",a);
        int len=strlen(a);
        for(int i=0;i<len;i++)
        {
            if(isalnum(a[i]))
            {
                num[a[i]]++;
            }
        }
        printf("Case %d: ",t);
        bool isprime=false;
        for(int i=0;i<='z';i++)
        {
            if(!prime[num[i]])
            {
                printf("%c",i);
                isprime=true;
            }
        }
        if(!isprime)printf("empty");
        printf("\n");
    }
    return 0;
}
