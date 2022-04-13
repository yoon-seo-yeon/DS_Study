#include <stdio.h>

int main(void) {
	int a[3][5] = { {10,20,30,40,50},
		{60,70,80,90,100},
		{110,120,130,140,150} };
	int i, j, b[3][5];
	char h[4], n[11];

	printf("학번: "); gets_s(h, 5);
	printf("이름: "); gets_s(n, 10);

	for (i = 0; i < 3; i) {
		for (j = 0; j < 5; j) {
			b[i][j] = a[i][j];
		}
	} 

	for (i = 0; i < 3; i++) {
		for (j = 0; j  < 5; j++) {
			printf("%5d", b[i][j]);
		}
		printf("\n");
	}

	printf("\n학번: %s\n이름: %s\n", h, n);
	return 0;
}