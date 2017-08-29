long long int quickpow(int a, long int n, int m)
{
		if(n==0)
			return 1;
		if(n==1)
			return a;
        long long int halfpow=quickpow(a,n/2,m);
		if(n%2==0)
			return (halfpow*halfpow)%m;
		else
			return (((halfpow*halfpow)%m)*a)%m;
}
