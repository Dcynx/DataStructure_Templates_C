#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
long long int quickpow(long long int a,long long int b,long long int p)
{
	if(b==0)
		return 1;
	if(b==1)
		return a%p;
	long long int halfpow=quickpow(a,b/2,p)%p;
	if(b%2==0)
		return ((halfpow%p)*(halfpow%p))%p;
	else
		return ((((halfpow%p)*(halfpow%p))%p)*(a%p))%p;
}
int main()
{
	long long int t,a,b,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&a,&b);
		ans=quickpow(a,b,1000000007);
		printf("%lld\n",ans);
	}
	return 0;
}
