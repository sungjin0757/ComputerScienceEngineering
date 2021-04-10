#include<stdio.h>

void selectionSort(int arr[], int n) {
	int temp;
	int i, j;
	int minidx;

	for (i = 0; i < n; i++) {
		minidx = i;
		for (j = i + 1; j < n; j++) {
			if (arr[minidx] > arr[j])
				minidx = j;
		}
		temp = arr[i];
		arr[i] = arr[minidx];
		arr[minidx] = temp;
	}
}

int main(void) {
	int arr[4] = { 2,3,1,4 };
	int i;

	selectionSort(arr, 4);

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	return 0;
}