#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int quickpow(int a,int b,int p)
{
	if(b==0)
		return 1;
	if(b==1)
		return a%p;
	int halfpow=(quickpow(a,b/2,p))%p;
	if(b%2==0)
		return ((halfpow%p)*(halfpow%p))%p;
	else
		return ((((halfpow%p)*(halfpow%p))%p)*(a%p))%p;
}
int main()		
{
	int a,p;							// p should be prime
	scanf("%d %d",&a,&p);
	printf("%d\n",quickpow(a,p-2,p));
	return 0;
}
	
