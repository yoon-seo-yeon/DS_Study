#include <stdio.h>
#define R 3

int b[R] = { 0, };

void PrintCom() {
	int i;

	for (i = 0; i < R; i++) printf("%5d", b[i]);
	printf("\n");
}

void combination(int a[], int n, int r, int ii) {
	int i;

	if (r == R) PrintCom();

	else for (i = ii + 1; i < n; i++) {
		b[r] = a[i];
		combination(a, n, r + 1, i);
	}
}

int main(void) {
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	combination(a, n, 0, -1);

	return 0;
}