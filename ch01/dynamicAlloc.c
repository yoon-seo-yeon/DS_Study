#include <stdio.h>
#include <stdlib.h>
//#define SIZE 1000000

int main(void) {
	int n = 1000000;
	int* a = (int*)malloc(sizeof(int) * n);
	a[0] = 5;
	*(a + 1) = 10;
	*(a + 2) = 15;
	a[3] = 20;

	for (int i = 0; i < 4; i++) {
		printf("%d\n", a[i]); //printf("%d\n", *(a+i))
	}
	printf("\n");
	free(a);
	return 0;
}