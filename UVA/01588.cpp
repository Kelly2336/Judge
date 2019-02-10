#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    //freopen("1588in.txt","r",stdin);
    //freopen("1588out.txt","w",stdout);
    char a[120],b[120];
    while(scanf("%s%s",a,b)>=2)
    {
        int lena=strlen(a);
        int lenb=strlen(b);
        int ans=0;
        int A[120],B[120];
        for(int i=0;i<lena;i++)A[i]=a[i]-'0';
        for(int i=0;i<lenb;i++)B[i]=b[i]-'0';
        for(int i=0;i<=lena;i++)
        {
            bool s=true;
            for(int k=0;k+i<lena&&k<lenb;k++)
            {
                if(A[k+i]+B[k]>3)
                {
                    s=false;
                    break;
                }
            }
            if(s)
            {
                ans=max(lenb+i,lena);
                break;
            }
        }
        for(int i=0;i<=lenb;i++)
        {
            bool s=true;
            for(int k=0;k+i<lenb&&k<lena;k++)
            {
                if(B[k+i]+A[k]>3)
                {
                    s=false;
                    break;
                }
            }
            if(s)
            {
                ans=min(ans,max(lena+i,lenb));
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
