#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int heapSize;
int heap[100005];
void max_heapify (int Arr[ ], int i, int N)
{
	int largest;
    int left = 2*i;                   //left child
    int right = 2*i +1;           //right child
    if(left<= N && Arr[left] > Arr[i] )
          largest = left;
    else
         largest = i;
    if(right <= N && Arr[right] > Arr[largest] )
        largest = right;
    if(largest != i )
    {
        Arr[i] = Arr[i] + Arr[largest] - (Arr[largest]=Arr[i]);
        max_heapify(Arr,largest,N);
    }
}
void build_maxheap(int Arr[],int N)
{
	// complexity = O(n) (Might Think it is O(nlogn), but do the math correctly)
	int i;
    for(i=N/2;i>=1;i--)
    {
        max_heapify(Arr,i,N);
    }
}

void insert(int x)
{
	// complexity = O(logn)
	heapSize++;
	heap[heapSize]=x;

	int par = heapSize/2;
	int i=heapSize;
	while( (i>1) && ( heap[par] < x ) )
	{
		heap[i]=heap[par];
		i = par;
		par = i/2;
	}
	heap[i] = x;
}

void deleteMax()
{
	// complexity = O(logn)
	heap[1] = heap[heapSize];
	heapSize--;

	int largest,left,right;

	int i=1;
	while(1)
	{
		left = 2*i;               //left child
	    right = 2*i +1;           //right child
	    if(left<=heapSize && heap[left] > heap[i] )
	          largest = left;
	    else
	         largest = i;
	    if(right<=heapSize && heap[right] > heap[largest] )
	        largest = right;
		if(largest==i)
			break;
		else
		{
			heap[i] = heap[i] + heap[largest] - (heap[largest]=heap[i]);	// swap heap[i] and heap[largest]
			i=largest;
		}
	}
}

int main()
{
	// buildmaxheap function is used when we want to make an array into heap for a single time only
	// If we want to continuously insert and delete the heap elements, we need to use insert and delete
	heapSize=0;
	insert(10);
	insert(100);
	insert(59);
	insert(13);
	insert(122);
	insert(109);
	printf("%d\n",heap[1]);
	deleteMax();
	printf("%d\n",heap[1]);
}
