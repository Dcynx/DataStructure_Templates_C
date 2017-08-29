#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int a[1000],tree[1000];
void build(int node,int start,int end) //start and end are the intervals of segment
{
	if(start==end)				//start and end are 0 indexed(0 to n-1) and node also starts from 0
	{
		tree[node]=a[start];
		return;
	}
	int mid=(start+end)/2;
	build(2*node+1,start,mid);
	build(2*node+2,mid+1,end);
	tree[node]=tree[2*node+1]+tree[node*2+2];		//segtree specific operation which is add here
}
void update(int node,int start,int end,int idx,int val)
{
	if(start==end)
	{	
		//leaf node
		tree[node]+=val;
		a[idx]+=val;
	}
	else
	{
		int mid=(start+end)/2;
		if((start<=idx)&&(idx<=mid))	
			update(2*node+1,start,mid,idx,val);
		else
			update(2*node+2,mid+1,end,idx,val);
		tree[node]=tree[2*node+1]+tree[2*node+2];
	}
}
int query(int node,int start,int end,int l,int r)
{
	if((l<=start)&&(r>=end))		//superset
		return tree[node];
	if((r<start)||(l>end))			//no intersection
		return 0;
	int mid=(start+end)/2;
	int p1=query(2*node+1,start,mid,l,r);
	int p2=query(2*node+2,mid+1,end,l,r);
	return p1+p2;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	build(0,0,n-1);
	int ans=query(0,0,n-1,1,3);
	printf("%d\n",ans);
	return 0;
}
