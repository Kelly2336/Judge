#include<stdio.h>
unsigned int reserve(unsigned int a)
{
    unsigned int b=0;
    while(a!=0)
    {
        b=b*10+a%10;
        a/=10;
    }
    return b;
}
int main()
{
    int N;
    scanf("%d",&N);
    while(N--)
    {
        unsigned int a;
        scanf("%u",&a);
        int add=0;
        unsigned int b=reserve(a);
        do
        {
            a+=b;
            add++;
            b=reserve(a);
        }
        while(a!=b);
        printf("%d %u\n",add,a);
    }
    return 0;
}
