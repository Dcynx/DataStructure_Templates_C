#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i,j,n,l,carry,prod,a[1000000];
	scanf("%d",&n);
	a[0]=1;
	l=1;
	for(i=2;i<=n;i++)
	{
		carry=0;
		for(j=0;j<l;j++)
		{
			prod=(a[j]*i)+carry;
			a[j]=prod%10;
			carry=prod/10;
		}
		while(carry!=0)
		{
			a[l++]=carry%10;
			carry=carry/10;
		}
	}
	for(i=l-1;i>-1;i--)
		printf("%d",a[i]);
	printf("\n");
	return 0;
}

