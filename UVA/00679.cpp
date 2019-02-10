#include<stdio.h>
#include<cstring>
using namespace std;

/*const int maxd=20;
int s[1<<maxd];//pow(2,maxd)

int main()
{
    int D,I;
    while(scanf("%d%d",&D,&I)==2)
    {
        memset(s,0,sizeof(s));
        int k,n=(1<<D)-1;
        for(int i=0;i<I;i++)
        {
            k=1;
            while(1)
            {
                s[k]=!s[k];
                k=s[k]?k*2:k*2+1;
                if(k>n)break;
            }
        }
        printf("%d\n",k/2);
    }
    return 0;
}*/
int main()
{
    int a;
    scanf("%d",&a);
    int D,I;
    while(a--)
    {
        scanf("%d",&D);
        scanf("%d",&I);
        int k=1;
        for(int i=0;i<D-1;i++)
        {
            if(I%2)
            {
                k=k*2;
                I=(I+2)/2;
            }
            else
            {
                k=k*2+1;
                I/=2;
            }
        }
        printf("%d\n",k);
    }
    scanf("%d",&a);
    return 0;

}
