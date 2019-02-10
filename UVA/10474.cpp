#include<stdio.h>
#include<algorithm>
using namespace std;
/*int binary_search(int a[],int key,int n)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(key>a[mid])low=mid+1;
        else if(key<a[mid])high=mid-1;
        else return mid;
    }
    return -1;
}*/
int main()
{
    int N,Q,T=0;
    int a[10010];
    while(1)
    {
        scanf("%d%d",&N,&Q);
        if(N==0&&Q==0)break;
        T++;
        printf("CASE# %d:\n",T);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+N);
        for(int i=0;i<Q;i++)
        {
            int x;
            scanf("%d",&x);
            //int p=binary_search(a,x,N);
            int p=0;
            for(;p<N;p++)
            {
                if(a[p]==x)break;
                if(a[p]>x)
                {
                    p=-1;
                    break;
                }
            }
            if(a[p]!=x||p<0)printf("%d not found\n",x);
            else printf("%d found at %d\n",x,p+1);
        }
    }
    return 0;
}
