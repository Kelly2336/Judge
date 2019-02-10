#include<stdio.h>
int p[3500];
void prime_table()
{
    int k=1;
    p[0]=2;
    bool prime[100000]={false};
    for(int i=4;i<30000;i+=2)prime[i]=true;
    for(int i=3;i<30000;i+=2)
    {
        if(prime[i]==false)
        {
            p[k++]=i;
            for(int j=i*i;j<30000;j+=2*i)
            {
                prime[j]=true;
            }
        }
    }
    //printf("%d",k);//3245
}
int main()
{
    prime_table();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int l,u;
        scanf("%d%d",&l,&u);
        int m=0,maxn=0;
        for(int g=l;g<=u;g++)
        {
            int j=g;
            int jn=1;//D
            for(int k=0;p[k]<=g&&k<3245;k++)
            {
                int kn=1;
                while(j%p[k]==0)
                {
                    j/=p[k];
                    kn++;
                }
                jn*=kn;
            }
            //printf("%d %d\n",g,jn);
            if(jn>maxn)
            {
                maxn=jn;
                m=g;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,u,m,maxn);
    }
    return 0;
}
