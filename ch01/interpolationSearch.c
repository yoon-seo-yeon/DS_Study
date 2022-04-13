#include <stdio.h>

int interpolationSearch(int a[], int n, int key) {
	int left = 0, right = n - 1, middle;

	while (left <= right) {
		if (a[left] < a[right]) {
			middle = left + (right - left) * (key - a[left]) / (a[right] - a[left]);
			if (middle > right) middle = right;
			if (middle < left) middle = left;
		}

		else middle = left;

		if (key == a[middle]) return middle;

		else if (key > a[middle]) left = middle + 1;
		else right = middle - 1;
	}
	return -1;
}

int main(void) {
	int i, key, index, n;
	int a[] = { 3, 7, 10, 12, 14, 18, 21, 33, 35, 48 };
	n = sizeof(a) / sizeof(int);

	printf("찾을 대상 : ");
	for (int i = 0; i < n; i++) printf("%5d  ", a[i]);
	printf("\n");

	printf("찾을 값 : ");
	scanf("%d", &key);

	index = interpolationSearch(a, n, key);

	if (index < 0) printf("\n찾고자 하는 값이 없다..\n");
	else printf("\n%d은(는) %d에서 찾음\n", key, index);
}