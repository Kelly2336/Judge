/*
ID: whitech1
TASK: transform
LANG: C++
*/
#include<stdio.h>
using namespace std;
#define maxn 12
int n;
char a[maxn][maxn];
char b[maxn][maxn];
char c[maxn][maxn];

void swap(char &A,char &B)
{
    char t=A;
    A=B;
    B=t;
}

void Copy()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            c[i][j]=a[i][j];
}

void horizon()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n/2;j++)
            swap(c[i][j],c[i][n-1-j]);
}

void clockwise()
{
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            swap(c[i][j],c[j][i]);
    horizon();
}

bool check()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(b[i][j]!=c[i][j])return false;
    return true;
}

int main()
{

    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);

    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    for(int i=0;i<n;i++)
        scanf("%s",b[i]);
    //1
    Copy();
    clockwise();
    if(check()){printf("1\n");return 0;}
    //2
    clockwise();
    if(check()){printf("2\n");return 0;}
    //3
    clockwise();
    if(check()){printf("3\n");return 0;}
    //4
    Copy();
    horizon();
    if(check()){printf("4\n");return 0;}
    //5
    clockwise();
    if(check()){printf("5\n");return 0;}
    clockwise();
    if(check()){printf("5\n");return 0;}
    clockwise();
    if(check()){printf("5\n");return 0;}
    //6
    Copy();
    if(check()){printf("6\n");return 0;}
    //7
    printf("7\n");
    return 0;
}
