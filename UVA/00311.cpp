#include<stdio.h>
using namespace std;
int main()
{
    while(1)
    {
        int a[7];
        int notzero=0;
        for(int i=1;i<=6;i++)
        {
            scanf("%d",&a[i]);
            if(a[i])notzero++;
        }
        if(!notzero)break;
        int box=0;
        //1 0 0 0 0 0
        box+=a[6];
        //0 1 0 0 0 11
        box+=a[5];
        a[1]-=a[5]*11;
        //0 0 4 0 5 0
        box+=a[4];
        a[2]-=a[4]*5;
        //0 0 0 4 0 0
        box+=a[3]/4;
        a[3]%=4;

        if(a[3]==3)
        {
            box++;
            a[2]-=1;
            a[1]-=5;
        }
        else if(a[3]==2)
        {
            box++;
            a[2]-=3;
            a[1]-=6;
        }
        else if(a[3]==1)
        {
            box++;
            a[2]-=5;
            a[1]-=7;
        }

        if(a[2]<0)
        {
            a[1]+=a[2]*4;
            a[2]=0;
        }
        //0 0 0 0 9 0
        box+=a[2]/9;
        a[2]%=9;
        if(a[2]>0)
        {
            box++;
            a[1]-=(36-a[2]*4);
        }
        if(a[1]<0)a[1]=0;
        //0 0 0 0 0 36
        box+=a[1]/36;
        if(a[1]%36)box++;
        printf("%d\n",box);
    }
    return 0;
}
/*
6 5 4 3 2 1
1 0 0 0 0 0
0 1 0 0 0 11
0 0 1 0 5 0
0 0 0 4 0 0
0 0 0 3 1 5
0 0 0 2 3 6
0 0 0 1 5 7
0 0 0 0 9 0
*/
