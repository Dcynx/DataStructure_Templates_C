#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int a[1000][1000];
int ncr(int n,int r)
{
	if(a[n][r]!=-1)
		return a[n][r];
	else if(a[n][r]==-1)
	{
		if((r==0)||(n==r))
		{
			a[n][r]=1;
			return 1;
		}
		if(n<r)
		{
			a[n][r]=0;
			return 0;
		}
		a[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
		return a[n][r];
	}
}
int main()
{
	int i,j,n,r;
	//memset(a,-1,1000000);
	for(i=0;i<1000;i++)
		for(j=0;j<1000;j++)
			a[i][j]=-1;
	scanf("%d %d",&n,&r);
	printf("%d\n",ncr(n,r));
	return 0;
}

