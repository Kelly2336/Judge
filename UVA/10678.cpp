#include<stdio.h>
#include<cmath>
int main()
{
	int N,D,L; //µJ¶Z¡AÃ·ªø
	const double pi=2*acos(0);
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
	    scanf("%d%d",&D,&L);
	    double lr=L/2.0;
	    double sr=sqrt(pow(lr,2)-pow(D/2.0,2));
		double Area = pi*lr*sr; //Ellipse = pi * minor axis * major axis

		printf("%.3lf\n",Area);
	}
	return 0;
}

