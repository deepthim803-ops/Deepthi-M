#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define SIZE 100000
 void merge(int arr[], int l, int m, int r)
 {
 	int i = l,j = m+1,k = 0;
 	int temp[r-l+1];
 	while(i <= m && j <= r)
 	{
 		if(arr[i] <= arr[j])
		 temp[k++] = arr[i++];
		 else
		 temp[k++] = arr[j++];
	}
 while(i <= m)
 temp[k++] = arr[i++];
 while(j <= r)
 temp[k++] = arr[j++];
 for(i = 1;k = 0;i<r,i++,k++)
 arr[i] = temp[k];
}
void sequentialMergeSort(int arr[], int l, int r)
{
	if(l < r)
	{
		int m = (l+r)/2;
		sequentialMergeSort(arr, l, m);
		sequentialMergeSort(arr, m + 1,r);
		merge(arr, l, m, r);
	}
}
void parallelMergeSort(int arr[], int l, int r)
{
	if(l < r)
	{
		int m = (l+r)/2;
		{
			parallelMergeSort(arr, l, m);
			parallelMergeSort(arr, m + 1, r);
			
		}
		merge(arr,l,m,r);
	}
}
  int main()
  {
  	int arr1[SIZE], arr2[SIZE];
  	int i;
  	srand(time(NULL));
  	for(i = 0;i < SIZE; i++)
  	{
  		arr1[i] = rand()%1000;
  		arr2[i] = arr1[i];
  	}
  	double start,end;
  	
  	start = omp_get_wtime();
  	sequentialMergeSort(arr1,0,SIZE-1);
  	end  = omp_get_wtime();
  	printf("sequential Merge Sort Time = %f seconds \n", end - start);
  	
  	start = omp_get_wtime();
  	parallelMergeSort(arr2,0,SIZE-1);
  	end = omp_get_wtime();
  	printf("parallel Merge Sort Time = %f seconds \n", end - start);
  	
  	return 0;
  }



