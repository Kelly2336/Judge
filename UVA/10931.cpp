#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
    int I;
    while(1)
    {
        scanf("%d",&I);
        if(!I)break;
        int sum=0;
        stack<int> s;
        while(!s.empty())s.pop();
        while(I)
        {
            sum+=I%2;
            s.push(I%2);
            I>>=1;
        }
        printf("The parity of ");
        while(!s.empty())
        {
            printf("%d",s.top());
            s.pop();
        }
        printf(" is %d (mod 2).\n",sum);
    }
    return 0;
}
