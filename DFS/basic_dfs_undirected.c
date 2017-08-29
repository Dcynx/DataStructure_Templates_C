#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct b{
	int val;
	struct b *next;
}node;
node *a[1000006];
int dist[1000006];
void insert(int v1,int v2)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->val=v2;
	temp->next=NULL;
	if(a[v1]==NULL)
		a[v1]=temp;
	else
	{
		node *n=a[v1];
		while((n->next)!=NULL)
			n=n->next;
		n->next=temp;
	}
}
void refresh()
{
	int i;
	for(i=0;i<1000006;i++)
	{
		a[i]=NULL;
		dist[i]=-1;	//-1 means unknown
	}
}
int n;
int dfs(int v)
{
	if(v==n)
	{
		dist[v]=0;
		return 0;
	}
	node *temp=a[v];
	int ans;
	int max=-1;
	while(temp!=NULL)
	{
		if(dist[temp->val]==-1)
			ans=1+(dfs(temp->val));
		else
			ans=1+dist[temp->val];
		if(max<ans)
			max=ans;
		temp=temp->next;
	}
	dist[v]=max;
	return max;
}
int main()
{
	int t,m,i,v1,v2,req;
	scanf("%d",&t);
	while(t--)
	{
		refresh();
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&v1,&v2);
			insert(v1,v2);		// v1 -> v2
		}
		req=dfs(1)-1;
		printf("%d\n",req);
	}
	return 0;
}
