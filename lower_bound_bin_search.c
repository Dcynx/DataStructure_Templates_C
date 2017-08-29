#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b );
}
int min(int a,int b)
{
	if(a<=b)
		return a;
	else
		return b;
}
int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

int lower_bound_bin_search(int l,int r,int a[],int x)		// returns the highest index of highest number <= x
{
	int m;
	while(l<r)
	{
		m=l+((r-l)/2);
		if(a[m]>x)
			r=m-1;
		else
			l=m+1;
	}
	if(a[r]<=x)
		return r;
	else
		return r-1;
}

int main()
{
	int n,x,i,index,a[100005];
	scanf("%d %d",&n,&x);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	index=lower_bound_bin_search(0,n-1,a,x);
	printf("The Greatest Index of Greatest Number <=%d is %d\n",x,index);
	return 0;
}
