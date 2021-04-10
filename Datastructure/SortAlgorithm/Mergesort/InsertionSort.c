#include<stdio.h>

void InsertSort(int arr[], int n) {
	int i, j;
	int insData;

	for (i = 1; i < n; i++) {
		insData = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] < insData)
			{
				
				break;
			}
			else {
				arr[j + 1] = arr[j];
			}
		}
		arr[j + 1] = insData;
	}
}

int main(void) {
	int arr[4] = { 2,3,1,4 };
	int i;

	InsertSort(arr, 4);
	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	return 0;
}