#include<iostream>
using namespace std;
int main()
{
    double x1[12],y1[12],x2[12],y2[12];
    int r;
    char n;
    for(r=1;r<=11;r++)
    {
        cin>>n;
        if(n=='*')
        {
            r--;
            break;
        }
        cin>>x1[r]>>y1[r]>>x2[r]>>y2[r];
    }
    double x[10000],y[10000];//1000 is too small
    int p;
    for(int i=1;i<10000;i++)
    {
        cin>>x[i]>>y[i];
        if(x[i]==9999.9&&y[i]==9999.9)
        {
            p=i-1;
            break;
        }
    }
    for(int i=1;i<=p;i++)
    {
        bool f=true;
        for(int j=1;j<=r;j++)
        {
            if(x[i]>x1[j]&&x[i]<x2[j]&&y[i]<y1[j]&&y[i]>y2[j])
            {
                f=false;
                cout<<"Point "<<i<<" is contained in figure "<<j<<endl;
            }
        }
        if(f)
        {
            cout<<"Point "<<i<<" is not contained in any figure"<<endl;
        }
    }
    return 0;
}
