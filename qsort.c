#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int pivot(int a[],int l,int r)
{
	int i,j;
	i=l-1;
	for(j=l;j<r;j++)
	{
		if(a[j]<=a[r])
		{
			i++;
			a[i]=a[i]+a[j]-(a[j]=a[i]);
		}
	}
	a[r]=a[r]+a[i+1]-(a[i+1]=a[r]);
	return i+1;
}
void sort(int a[],int l,int r)
{
	if(l<r)
	{
		int p=pivot(a,l,r);
		sort(a,l,p-1);
		sort(a,p+1,r);
	}
}
int main()
{
	int n,i,a[10000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

