#include<stdio.h>

void swap(int arr[], int idx1, int idx2) {
	int temp;
	temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int partition(int arr[], int left, int right) {
	int piviot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (arr[low] <= piviot && low<=right)
			low++;
		while (arr[high] >= piviot && high>=left)
			high--;
		if (low <= high)
			swap(arr, low, high);
	}
	
	swap(arr, left, high); //�����ϸ鼭 �Ա⶧���� low�� ������ �ڸ��� �ǹ����� ������ �ۿ� ����. �ֳĸ� �ǹ�����ū ���� �ǹ����� ���� ���� �ٲ�� ����
	return high;
}

void QuickSort(int arr[], int left, int right) {
	if (left <= right) {
		
		int high=partition(arr, left, right);
		QuickSort(arr, left, high - 1);
		QuickSort(arr, high + 1, right);
	}
}

int main(void) {
	int arr[7] = { 3,2,4,1,7,6,5 };
//	int arr[3] = { 3,3,3 };

	int len = sizeof(arr) / sizeof(int);
	int i;
	QuickSort(arr, 0, len - 1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	return 0;
}