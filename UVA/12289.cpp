#include<stdio.h>
#include<cstring>
int main()
{
    int T;
    scanf("%d",&T);
    for(;T>0;T--)
    {
        char wrong[6];
        scanf(" %s",wrong);
        if(strlen(wrong)==5)
        {
            printf("3\n");
        }
        else
        {
            int one=0;
            if(wrong[0]=='o')one++;
            if(wrong[1]=='n')one++;
            if(wrong[2]=='e')one++;

            if(one>=2) printf("1\n");
            else printf("2\n");
        }
    }
    return 0;
}
