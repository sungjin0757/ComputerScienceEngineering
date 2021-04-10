#include<stdio.h>

int Bsearch(int arr[], int first, int last, int target) {
	int mid = (first + last) / 2;

	if (first > last)
		return -1;
	if (mid == target)
		return arr[mid];

	if (arr[first] < arr[mid])
		return Bsearch(arr, first, mid - 1, target);
	else
		return Bsearch(arr, mid + 1, last, target);


}

int main(void) {
	int arr[7] = { 1,2,3,4,5,6,7 };
	int idx;
	idx = Bsearch(arr, 0, 6, 3);

	if (idx < -1)
		printf("Å½»ö½ÇÆĞ");
	else
		printf("Å½»öÀúÀå ÀÎµ¦½º:%d", idx);

	return 0;
}