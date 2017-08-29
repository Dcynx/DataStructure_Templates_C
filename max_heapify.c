#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
void maxheapify(int a[],int i,int n)
{
	int lar,l,r;
	lar=i;
	l=2*i;
	r=2*i+1;
	if((l<=n)&&(a[l]>a[lar]))
		lar=l;
	if((r<=n)&&(a[r]>a[lar]))
		lar=r;
	if(lar!=i)
	{
		a[i]=a[i]+a[lar]-(a[lar]=a[i]);
		maxheapify(a,lar,n);
	}
}
int main()
{
	int n,i,a[1000000];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=n/2;i>=1;i--)
		maxheapify(a,i,n);
	printf("%d\n",a[1]);
	return 0;
}
