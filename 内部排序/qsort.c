#include <stdio.h>
#include <stdlib.h>
#include  <time.h>
int Partition(int A[], int left, int right)
{
	int temp = A[left];
	while (left < right)
	{
		while (left < right && A[right] > temp)
			right--;
		A[left] = A[right];
		while (left < right && A[left] <= temp)
			left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}
void quickSort(int A[], int left, int right)
{
	if (left < right)
	{
		int pos = Partition(A, left, right);
		quickSort(A, left, pos - 1);
		quickSort(A, pos + 1, right);
	}
}
/*
int main()
{
	int A[100];
	int left = 0;
	int right = 99;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++)
	{
		A[i] = rand();
	}
	quickSort(A, left, right);
	for (int i = 0; i < 100; i++)
		printf("%d", A[i]);
	return 0;
}
*/