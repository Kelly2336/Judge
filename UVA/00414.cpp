#include<stdio.h>
using namespace std;
int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==0)break;
        int a[13]={0};
        char c;
        for(int i=0;i<n;i++)
        {
            while(1)
            {
                scanf("%c",&c);
                if(c==' ')
                {
                    a[i]++;
                    break;
                }
                else if(c=='X')break;
            }
            for(int j=0;j<24;j++)
            {
                scanf("%c",&c);
                if(c==' ')
                {
                    a[i]++;
                }
            }
        }
        int min=25;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<min)min=a[i];
            sum+=a[i];
        }
        sum-=min*n;
        printf("%d\n",sum);
    }
    return 0;
}
