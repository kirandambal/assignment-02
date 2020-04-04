#include<stdlib.h>
#include <stdio.h>
void insertionSort(int a[], int size)
{
	int i, j, k, pos,pivot;
	for (i = 1; i < size; ++i)
	{
		j = i - 1;
		pivot = a[i];
		pos = binarySearch(a, pivot, 0, j);
		while (j >= pos)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = pivot;
	}
}
int binarySearch(int a[], int key, int low, int high)
{
	if (high <= low)
		return (key > a[low])?  (low + 1): low;
	int mid = (low + high)/2;
	if(key == a[mid])
        return mid+1;
 	if(key > a[mid])
        	return binarySearch(a, key, mid+1, high);
	else
        	return binarySearch(a, key, low, mid-1);
}
int main(int argc, char *argv[])
{
	if(argc==1)
	{
		printf("....Insufficent parameters..or..no parameters passed..\n");
		exit(0);
	}
	int size,i;
	int a[50];
	for(i =0;i<argc;i++)
		a[i] = atoi(argv[i]);
	size=argc;
	insertionSort(a, size);
	printf("Sorted array: \n");
	for (i =1; i<size; i++)
		printf("%d ",a[i]);
	return 0;
}
