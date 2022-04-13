#include <stdio.h>
#include <time.h>
#include <math.h>

void main(void) {
	int i, j, k = 0, d;
	int a = 100000000, b = 100001000;
	clock_t t1, t2;

	printf("%d���� %d���� �Ҽ� ���ϱ�\n\n", a, b);

	printf("1. �ݺ�Ƚ���� ���� ��ȿ������ ���\n");
	t1 = clock();
	for (i = a; i <= b; i++) {
		d = i / 2;
		for (j = 2; j <= d; j++) {
			if (i % j == 0) {
				k = 1;
				break;
			}
		}
		if (k == 0)printf("%d  ", i);
		k = 0;
	}
	t2 = clock();
	printf("\n%.3lf�� �ҿ�\n\n", (double)(t2 - t1) / 1000);

	printf("2. �ݺ�Ƚ���� ���� ȿ������ ���\n");
	t1 = clock();
	k = 0;
	for (i = a; i <= b; i++) {
		if (i != 2 && i % 2 == 0)continue;
		d = (int)sqrt((double)i);
		for (j = 2; j <= d; j++) {
			if (i % j == 0) {
				k = 1;
				break;
			}
		}
		if (k == 0)printf("%d  ", i);
		k = 0;
	}
	t2 = clock();

	printf("\n%.3lf�� �ҿ�\n\n", (double)(t2 - t1) / 1000);
}