#include<stdio.h>
#include<math.h>
#include<limits.h>
int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int main()
{
    int t,n,i,stk_start,index,max_area;
    int stk[1000],right[1000],left[1000],a[1000];
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    for(i=0;i<n;i++)
	        scanf("%d",&a[i]);
	    stk_start=-1;
	    for(i=0;i<n;i++)
	    {
	        if((stk_start==-1)||(a[i]>=a[stk[stk_start]]))
	        {
	            stk_start++;
	            stk[stk_start]=i;
	        }
	        else
	        {
	            // a[i] < stk.top()
	            // pop the stack till a[stk.top()] <= a[i]
	            // before popping each right[stk[stk_start]] = i,,,,, then pop stk[stk_start]
	            // then insert i
	            while((a[stk[stk_start]]>a[i])&&(stk_start>=0))
	            {
	                index = stk[stk_start];
	                right[index] = i;
	                stk_start--;
	            }
	            stk_start++;
	            stk[stk_start] = i;
	        }
	    }
	    while(stk_start!=-1)
	    {
	        index = stk[stk_start];
	        right[index] = i;
	        stk_start--;
	    }
	    // now definitely stk_start=-1;
	    for(i=n-1;i>=0;i--)
	    {
	        if((stk_start==-1)||(a[i]>=a[stk[stk_start]]))
	        {
	            stk_start++;
	            stk[stk_start]=i;
	        }
	        else
	        {
	            while((a[stk[stk_start]]>a[i])&&(stk_start>=0))
	            {
	                index = stk[stk_start];
	                left[index] = i;
	                stk_start--;
	            }
	            stk_start++;
	            stk[stk_start] = i;
	        }
	    }
	    while(stk_start!=-1)
	    {
	        index = stk[stk_start];
	        left[index] = i;
	        stk_start--;
	    }
	    max_area=-1;
	    for(i=0;i<n;i++)
	        max_area = max(max_area,(a[i]*(right[i]-left[i]-1)));
	    printf("%d\n",max_area);
	}
	return 0;
}
