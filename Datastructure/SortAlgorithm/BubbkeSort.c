#include<stdio.h>

void BubbleSort(int arr[], int n) {
	int i, j;
	int temp;

	for (i = 0; i < n-1; i++) {
		for (j = 0; j <(n-1) -i; j++) {
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void) {
	int arr[4] = { 3,2,4,1 };
	int i;

	BubbleSort(arr, 4);
	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	return 0;
}