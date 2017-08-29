#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	float a,x,temp;
	scanf("%f",&a);
	x=1.0;
	while(fabs(x*x-a)>=0.0001)
	{
		temp=a/x;
		x=0.5*(x+temp);
		//printf("%f\n",x);
	}
	printf("%f\n",x);
	return 0;
}


