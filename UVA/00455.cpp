#include<stdio.h>
#include<cstring>
int main()
{
    int n;
    scanf("%d",&n);
    for(;n>0;n--)
    {
        char s[100];
        scanf("%s",s);
        int len=strlen(s);
        for(int T=1;T<=len;T++)
        {
            if(len%T==0)
            {
                bool circle=true;
                for(int i=0;i<T;i++)
                {
                    for(int j=i;j<len;j+=T)
                    {
                        if(s[j]!=s[i])
                        {
                            circle=false;
                            i=T;
                            break;
                        }
                    }
                }
                if(circle)
                {
                    printf("%d\n",T);
                    if(n!=1)printf("\n");
                    break;
                }
            }
        }
    }
    return 0;
}
