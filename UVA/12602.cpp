#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(;n>0;n--)
    {
        char a[4];
        for(int i=0;i<4;i++)scanf(" %c",&a[i]);
        int num=0;
        scanf("%d",&num);
        int al=0;
        for(int i=0;i<3;i++)
        {
            al=al*26+a[i]-'A';
        }
        if(al-num<=100&&al-num>=-100)printf("nice\n");
        else printf("not nice\n");
    }
    return 0;
}
