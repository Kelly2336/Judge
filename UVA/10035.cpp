#include<stdio.h>
#include<algorithm>
#include<cstring>
int main()
{
    while(1)
    {
        char a[12],b[12];
        int sum[12];
        for(int i=0;i<12;i++)
        {
            a[i]='0';
            b[i]='0';
            sum[i]=0;
        }
        scanf(" %s",a);
        scanf(" %s",b);
        int la=strlen(a);
        int lb=strlen(b);
        if(la==1&&lb==1&&a[0]=='0'&&b[0]=='0')break;
        a[la]='0';
        b[lb]='0';
        int carry=0;
        for(int i=0;i<11;i++)
        {
            if(la-i>=0)sum[i]+=a[la-i]-'0';
            if(lb-i>=0)sum[i]+=b[lb-i]-'0';
            if(sum[i]>=10)
            {
                carry++;
                sum[i+1]+=sum[i]/10;
            }
        }
        if(carry>1)printf("%d carry operations.\n",carry);
        else if(carry==1)printf("%d carry operation.\n",carry);
        else printf("No carry operation.\n");
    }
    return 0;
}
