#include <stdio.h>
#define R 3

int b[R] = { 0, };

void PrintReCom() {
	int i;

	for (i = 0; i < R; i++) printf("%5d", b[i]);
	printf("\n");
}

void Recombination(int a[], int n, int r, int ii) {
	int i;

	if (r == R) PrintReCom();

	else for (i = ii; i < n; i++) {
		b[r] = a[i];
		Recombination(a, n, r + 1, i);
	}
}

int main(void) {
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	Recombination(a, n, 0, 0);

	return 0;
}