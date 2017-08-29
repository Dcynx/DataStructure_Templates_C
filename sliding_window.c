#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n,k,i,s,e,a[100000],q[100000],b[100000],temp1,temp2,temp3,temp4;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	s=0;
	e=0;
	q[0]=0;					//q stores index values
	for(i=1;i<k;i++)
	{
		temp1=q[e];
		while((s<=e)&&(a[i]<=a[temp1]))
		{
			e--;
			temp1=q[e];	//update everytime e changes
		}
		e++;
		q[e]=i;
	}
	//printf("%d\n",a[q[e]]);
	for(i=k;i<n;i++)
	{
		temp2=q[s];
		b[i-k]=a[temp2];
		temp3=q[e];
		while((s<=e)&&(q[s]<=(i-k)))
			s++;
		while((s<=e)&&(a[i]<=a[temp3]))
		{
			e--;
			temp3=q[e];
		}
		e++;
		q[e]=i;
	}
	temp4=q[s];
	b[n-k]=a[temp4];
	for(i=0;i<=(n-k);i++)
		printf("%d ",b[i]);
	printf("\n");
	return 0;
}
