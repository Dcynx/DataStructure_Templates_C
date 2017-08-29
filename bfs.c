#include<stdio.h>
#include<math.h>
#include<stdlib.h>
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
	temp->next=NULL;
	if(a[v1]==NULL)
		a[v1]=temp;
	else
	{
		node *var=a[v1];
		while(var->next!=NULL)
			var=var->next;
		var->next=temp;
	}
}
int arr[1000000];
int f=-1;
int r=-1;
void enq(int v)
{
	if((f==-1)&&(r==-1))
		f=0;
	r++;
	arr[r]=v;
}
void deq()
{
	if(f==r)
	{
		f=-1;
		r=-1;
	}
	else
		f++;
}
void bfs(int v)
{
	int t1;
	visit[v]=1;
	enq(v);
	while((f!=-1)&&(r!=-1))
	{
		t1=arr[f];
		deq();
		printf("%d ",t1);
		node *temp=a[t1];
		while(temp!=NULL)
		{
			if(!visit[temp->val])
			{
				visit[temp->val]=1;
				enq(temp->val);
			}
			temp=temp->next;
		}
	}
}
int main()
{
	int n,m,i,v1,v2;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&v1,&v2);
		insert(v1,v2);
		insert(v2,v1);
	}
	bfs(1);
	printf("\n");
	return 0;
}
