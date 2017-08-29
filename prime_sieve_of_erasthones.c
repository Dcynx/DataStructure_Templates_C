#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()				//This program is type of dictionary of information of number prime till 1000000
{
	int t,i,j,n,a[1000000];
	t=100000;
	for(i=2;i*i<=t;i++)
	{
		if(a[i]==0)
		{
			for(j=2*i;j<=t;j+=i)
				a[j]=1;					//if a[p] is 1 then not prime
		}
	}
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		if(a[i]==0)
			printf("%d\n",i);
	}
	return 0;
}
