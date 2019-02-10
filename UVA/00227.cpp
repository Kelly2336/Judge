#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
void swap(char* a,char* b)
{
    char t=*a;
    *a=*b;
    *b=t;
}
char f[]="ABRL";
int x[4][2]= {-1,0,1,0,0,1,0,-1};
int main()
{
    int t=0;
    while(1)
    {
        t++;
        char a[5][6];
        for(int i=0;i<5;i++)for(int j=0;j<5;j++)a[i][j]=' ';
        char s[50];
        cin.getline(a[0],6);
        if(strcmp(a[0],"Z")==0)break;
        if(t!=1)printf("\n");
        printf("Puzzle #%d:\n",t);
        for(int i=1; i<5; i++)
        {
            cin.getline(a[i],6);
        }
        /*
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                printf("%c",a[i][j]);
                if(j!=4)printf(" ");
            }
            printf("\n");
        }
        */
        int si=0,sj=0;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(a[i][j]==' '||a[i][j]=='\0')
                {
                    si=i;
                    sj=j;
                    break;
                }
            }
        }
        bool solve=true;
        while(1)
        {
            cin.getline(s,50);
            int len=strlen(s);
            for(int i=0; i<len; i++)
            {
                if(!solve)break;
                for(int j=0; j<4; j++)
                {
                    if(s[i]==f[j])
                    {
                        if(0<=si+x[j][0]&&si+x[j][0]<5&&0<=sj+x[j][1]&&sj+x[j][1]<5)
                        {
                            swap(&a[si][sj],&a[si+x[j][0]][sj+x[j][1]]);
                            si+=x[j][0];
                            sj+=x[j][1];
                        }
                        else
                        {
                            solve=false;
                            //printf("%d %d %d %c\n",si,sj,i,s[i]);
                        }
                        break;
                    }
                }
            }
            if(s[len-1]=='0')
            {
                break;
            }
        }
        if(solve)
        {
            for(int i=0; i<5; i++)
            {
                for(int j=0; j<5; j++)
                {
                    printf("%c",a[i][j]);
                    if(j!=4)printf(" ");
                }
                printf("\n");
            }
        }
        else printf("This puzzle has no final configuration.\n");
    }
    return 0;
}
