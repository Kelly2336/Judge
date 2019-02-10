#include<stdio.h>
#include<ctype.h>
#include<cstring>
int main()
{
    bool prime[2000];
    for(int i=3;i<2000;i+=2)prime[i]=true;
    for(int i=4;i<2000;i+=2)prime[i]=false;
    prime[0]=false;
    prime[1]=true;
    prime[2]=true;
    for(int i=3;i<2000;i+=2)
    {
        if(prime[i])
        {
            for(int j=i*3;j<2000;j+=2*i)
            {
                prime[j]=false;
            }
        }
    }
    //////
    char s[500];
    while(scanf("%s",s)>=1)
    {
        int len=strlen(s);
        int sum=0;
        for(int i=0;i<len;i++)
        {
            if(isupper(s[i]))sum+=s[i]-'A'+27;
            else if(islower(s[i]))sum+=s[i]-'a'+1;
        }
        if(prime[sum])printf("It is a prime word.\n");
        else printf("It is not a prime word.\n");
    }
    return 0;
}
