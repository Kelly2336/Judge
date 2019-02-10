#include<stdio.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int k=0;
        for(int i=1;;i++)
        {
            k=(k*10+1)%n;
            if(!k)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
