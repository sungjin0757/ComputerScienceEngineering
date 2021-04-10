#include<stdio.h>

int Isearch(int arr[], int first, int last, int target) {
	int mid;
	mid = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;
	if (arr[first] >target||arr[last]<target)
		return -1;

	if (arr[mid] == target)
		return mid;
	if (arr[first] < arr[mid])
		return Isearch(arr, first, mid - 1, target);
	else
		return Isearch(arr, mid + 1, first, target);
}

int main(void) {
	int arr[] = { 1,3,5,7,9 };

	int idx;

	idx = Isearch(arr, 0, 4, 7);

	if (idx < 0)
		printf("탐색실패");
	else
		printf("저장위치 인덱스:%d", idx);

	return 0;
}