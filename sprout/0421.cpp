//取名字好困難QQ
//LIS
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int len=0;
        int s[100005]= {0};
        for(int i=0; i<n; i++)
        {
            int a;
            scanf("%d",&a);
            a*=2;
            for(int k=0; k<2; k++,a/=2)
            {
                if(a>=m)
                {
                    /*for(int j=len; j>=0; j--)
                    {
                        if(s[j]<=a)
                        {
                            if(j==len||s[j+1]>a)s[j+1]=a;
                            if(j==len)len++;
                            break;
                        }
                    }*/
                    int big=len;
                    int small=0;
                    int ans=0;
                    while(big>=small)
                    {
                        int mid=(big+small)/2;
                        if(s[mid]<=a)
                        {
                            small=mid+1;
                            if(mid>ans)ans=mid;
                        }
                        else big=mid-1;
                    }
                    if(ans==len||s[ans+1]>a)s[ans+1]=a;
                    if(ans==len)len++;
                }
            }
        }
        printf("%d\n",len);
    }
    return 0;
}
