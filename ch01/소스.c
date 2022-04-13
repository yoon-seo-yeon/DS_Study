#include <stdio.h>
int main(void) {
	int i, j, b[4][3];
	int a[3][4] = { {1,2,3,100},
		{4,5,6,200},
		{7,8,9,300} };

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			b[i][j] = a[j][i];
		}
	}
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}