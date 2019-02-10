#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    char k='0';
    int counter=0;
    while(1)
    {
        cin.get(k);
        if(cin.fail())break;
        if(k=='"')
        {
            counter++;
            if(counter%2==1)cout<<"``";
            else cout<<"''";
        }
        else cout<<k;
    }
    return 0;
}
//2018/07/09
#include<stdio.h>
using namespace std;
int main()
{
    char c;
    int q=1;
    while((c=getchar())!=EOF)
    {
        if(c=='"')
        {
            printf("%s",q?"``":"''");
            q=!q;
        }
        else putchar(c);
    }
    return 0;
}
