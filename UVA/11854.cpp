//right triangle
#include<stdio.h>
using namespace std;
int main()
{
    int a,b,c,C;
    while(1)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(!a&&!b&&!c)break;
        if(a>c)C=a*a;
        else if(b>c)C=b*b;
        else C=c*c;
        if(a*a+b*b+c*c==2*C)printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}
