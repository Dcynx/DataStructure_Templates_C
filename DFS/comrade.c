#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct n{
	int val;
	struct n *next;
}node;
node *a[1000000];
int visit[1000000];
void insert(int v1,int v2)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->val=v2;
	temp->next=a[v1];
	a[v1]=temp;
}
int dfsin[1000000];
int dfsout[1000000];
int height[1000000];
int time;
int h;
void dfs(int v)
{
	visit[v]=1;
	dfsin[v]=time;
	height[v]=h;
	node *temp=a[v];
	int check=1;
	while(temp!=NULL)
	{
		h=height[v];
		check=1;
		if(!visit[temp->val])
		{	
			time++;
			if(check)
				h++;
			check=0;
			dfs(temp->val);
		}
		temp=temp->next;
	}
	time++;
	dfsout[v]=time;
}
void init()
{
	int i;
	for(i=0;i<1000000;i++)
	{
		a[i]=NULL;
		visit[i]=0;
		time=1;
		dfsin[i]=0;
		dfsout[i]=0;
		height[i]=0;
		h=0;
	}
}
int main()
{
	int n,i,m,v,q1,q2,t;
	scanf("%d",&t);
	while(t--)
	{
		init();
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v);
			insert(v,i);
		}
		dfs(0);
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&q1,&q2);		//q2 is supposed to be superior of q1
			if((dfsin[q1]>dfsin[q2])&&(dfsout[q1]<dfsout[q2]))
				printf("%d\n",height[q1]-height[q2]-1);
			else
				printf("-1\n");
		}
	}
	return 0;
}

