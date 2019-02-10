//逆序數對
//D&C
#include<stdio.h>
using namespace std;

int mod=10000019;
long long int a[1000005];
long long int c[1000005];
long long int counting(long long int l,long long int r)
{
    if(l>=r)return 0;

    long long int mid=(l+r)/2;

    long long int cnt=0;
    cnt+=counting(l,mid);
    cnt%=mod;
    cnt+=counting(mid+1,r);
    cnt%=mod;

    long long int li,ri=mid+1;
    long long int sum=0;
    for(li=l; li<=mid; li++)
    {
        while(ri<=r && a[li]>a[ri])
        {
            sum+=a[ri];
            sum%=mod;
            ri++;
        }
        cnt+=sum;
        cnt%=mod;
        cnt+=( (ri-1-mid)*a[li]%mod );
        cnt%=mod;
    }
    //merge sort
    li=l;
    ri=mid+1;
    int ci=l;
    while(ci<=r)
    {
        if( (ri>r) || ( li<=mid && a[li]<a[ri] ) )
        {
            c[ci]=a[li];
            li++;
            ci++;
        }
        else
        {
            c[ci]=a[ri];
            ri++;
            ci++;
        }
    }
    for(int i=l; i<=r; i++)a[i]=c[i];

    return cnt;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)scanf("%d",&a[i]);
    printf("%d\n",counting(0,n-1));
    return 0;
}
