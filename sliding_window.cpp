#include<stdio.h>
#include<iostream>
#include<deque>

using namespace std;

void print_dq(deque<int> dq)
{
    int i;
    for(i=0;i<dq.size();i++)
        printf("%d ",dq[i]);
    printf("\n");
}
int main()
{
    // To find the maximum of elements of each window
    int i,j,n,k;
    int a[100005];
    deque<int> dq;
    scanf("%d %d",&n,&k);       // n is the number of elements ..... k is window size
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    // first processing the k elements
    for(i=0;i<k;i++)
    {
        while( (!dq.empty()) && (a[i]>=a[dq.back()]) )
            dq.pop_back();
        dq.push_back(i);
    }
    printf("%d ",a[dq.front()]);

    // processing the rest of the windows
    for(j=i;j<n;j++)
    {
        // pop all elements not present in the window
        while( (!dq.empty()) && (dq.front()<=j-k) )
            dq.pop_front();
        // Remove all elements smaller than the currently
        // being added element (remove useless elements)
        while( (!dq.empty()) && (a[j]>=a[dq.back()]) )
            dq.pop_back();
        dq.push_back(j);
        printf("%d ",a[dq.front()]);
    }
    // printf("%d ",dq.front());
    printf("\n");
//
    // dq.push_back(10);
    // dq.push_back(2);
    // dq.push_front(14);
    // dq.push_front(32);
    // print_dq(dq);
    // dq.pop_back();
    // print_dq(dq);
    // dq.pop_front();
    // print_dq(dq);
    // printf("%d\n",dq.front());
    // printf("%d\n",dq.back());

    return 0;
}
