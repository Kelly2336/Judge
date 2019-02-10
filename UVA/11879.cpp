#include<stdio.h>
#include<cstring>

void minu(int a[],int b,int *lena)
{
    int len=*lena;
    if(len>=3)
    {
        a[0]-=5*b;
        for(int i=0;i<len-1;i++)
        {
            if(a[i]<0)
            {
                a[i+1]+=a[i]/10;
                a[i]%=10;
            }
            if(a[i]<0)
            {
                a[i]+=10;
                a[i+1]--;
            }
        }
    }
    else
    {
        int A=a[0]+10*a[1];
        A-=5*b;;
        if(A<0)A*=-1;
        A%=17;
        a[0]=A%10;
        a[1]=A/10;
    }
    for(int i=len-1;i>=0;i--)
    {
        if(a[i]==0)len--;
        else break;
    }
    *lena=len;
}
bool seventeen(int n[],int len)
{
    int d=n[0];
    for(int i=0;i<len;i++)n[i]=n[i+1];
    len--;
    minu(n,d,&len);
    /*
    for(int i=len-1;i>=0;i--)
        printf("%d",n[i]);
    printf(" %d\n",len);
    */
    if(len<2)
    {
        if(n[0]==0)return true;
        else return false;
    }
    else return seventeen(n,len);
}

int main()
{
    while(1)
    {
        char s[105];
        scanf("%s",s);
        if(strcmp(s,"0")==0)break;
        int n[105]={0};
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            n[i]=s[len-1-i]-'0';
        }
        if(seventeen(n,len))printf("1\n");
        else printf("0\n");
    }
    return 0;
}
