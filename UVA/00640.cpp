#include<stdio.h>
using namespace std;
bool self[1000010];
int main()
{
    for(int i=1;i<=1000000;i++)
    {
        if(!self[i])printf("%d\n",i);
        int sum=i,t=i;
        while(t)
        {
            sum+=t%10;
            t/=10;
        }
        self[sum]=true;
    }
    return 0;
}
