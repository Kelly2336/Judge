#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    char a[110][110];
    int len[110];
    int MAX=0;
    int n=0;
    while(1)
    {
        cin.getline(a[n],110);
        if(cin.fail())break;
        len[n]=strlen(a[n]);
        MAX=max(len[n],MAX);
        n++;
    }
    for(int i=0;i<MAX;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(i<len[j])printf("%c",a[j][i]);
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
