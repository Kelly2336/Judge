#include<stdio.h>
int f[31];
void table()
{
    //f[i]=f[i-2]+2(f[i-2]+f[i-4]+....f[0])
    f[0]=1;
    f[2]=3;
    for(int i=1;i<=30;i+=2)
    {
        f[i]=0;
    }
    for(int i=4;i<=30;i+=2)
    {
        f[i]=f[i-2];
        for(int j=i-2;j>=0;j-=2)
        {
            f[i]+=f[j]*2;
        }
    }
}
int main()
{
    table();
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==-1)break;
        printf("%d\n",f[n]);
    }
    return 0;
}
