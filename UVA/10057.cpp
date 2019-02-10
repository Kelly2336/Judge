#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    while(1)
    {
        int n;
        cin>>n;
        if(cin.fail())break;
        int a[1000000];
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        sort(a,a+n);
        if(n%2==0&&n>=2)
        {
            int mina=n/2-1;
            int maxa=n/2;
            int x=2;
            for(int i=mina-1;i>=0;i--)
            {
                if(a[i]==a[mina])
                {
                    x++;
                }
                else break;
            }
            for(int i=maxa+1;i<n;i++)
            {
                if(a[i]==a[maxa])
                {
                    x++;
                }
                else break;
            }
            printf("%d %d %d\n",a[mina],x,a[maxa]-a[mina]+1);
        }
        else
        {
            int mina=n/2;
            int x=1;
            for(int i=mina-1;i>=0;i--)
            {
                if(a[i]==a[mina])
                {
                    x++;
                }
                else break;
            }
            for(int i=mina+1;i<n;i++)
            {
                if(a[i]==a[mina])
                {
                    x++;
                }
                else break;
            }
            printf("%d %d 1\n",a[mina],x);
        }
    }
    return 0;
}
