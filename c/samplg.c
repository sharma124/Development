#include <stdio.h>

int func(int arr[], int n, int k);

int main() {

	int T, N, arr[1000000], K, i;
	
	scanf ("%d", &T);
	while (T-- > 0)
	{
	    scanf("%d", &N);
	    
	    for (i=0; i<N; i++)
	    {
	        scanf("%d", &arr[i]);
	    }
	    
	    scanf("%d", &K);
	    
	    printf("%d\n", func(arr, N, K));
	}
	return 0;
}

void heapify (int arr[], int i, int n)
{
    int lchild, rchild, least, temp;
	least = i;

    lchild = 2*i+1;
    rchild = 2*i+2;
        
    if ((lchild < n) && (arr[lchild] < arr[least]))
    {
        least = lchild;
    }
    
    if ((rchild < n) && (arr[rchild] < arr[least]))
    {
        least = rchild;
    }
    
    if (least != i)
    {
        temp = arr[i];

        arr[i] = arr[least];
        
        arr[least] = temp;
        
        heapify (arr, least, n);
    }
	
}

int func(int arr[], int n, int k)
{
    int i, j, num, freq;
    int index=0, sum=0;
    
    for (i=0; i<n; i++)
    {
        if (arr[i] == 0)
        {
          continue;
        }
        
        num = arr[i];
        freq = 0;
        
        for (j=i; j<n; j++)
        {
            if (num == arr[j])
            {
                freq++;
                arr[j] = 0;
            }
        }
        
        arr[index] = freq;
        index++;
    }
    
    for (i = (k/2)-1; i>=0; i--)
    {
        heapify(arr, i, k);
    }
    
    for (i=k; i<index; i++)
    {
        if (arr[i] > arr[0])
        {
            arr[0]= arr[i];
            
            heapify(arr, 0, k);
        }
    }
    
    for (i=0; i<k; i++)
    {
        sum = sum + arr[i];
    }
    
    return sum;
}
