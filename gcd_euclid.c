#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
long long int gcd(long long int a,long long int b)
{
	if(b%a==0)
		return a;
	return gcd(b%a,a);
}
int main()
{
	long long int a,b,temp;
	scanf("%lld %lld",&a,&b);
	if(b<a)
		a=a+b-(b=a);
	temp=gcd(a,b);
	printf("GCD is %lld\n",temp);
	//printf("LCM is %d\n",a*b/temp);
	return 0;
}
