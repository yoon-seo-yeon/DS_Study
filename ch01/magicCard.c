#include <stdio.h>
#include <math.h>

enum bool{ false, true };

int main(void) {
	int n = 31, i, j, k = 1, cnt = 0;
	char answer;
	enum bool b[8] = { false };

	printf("0 ~ %d�� ���ڸ� �����ϼ���!\n", n);

	for (i = 0; i < log2(n); i++) {
		printf("\n\t%d��° ī��\n\n", i + 1);
		for (j = 0; j <= n; j++) {
			if ((j & k) == k) {
				printf("%d\t", j);
				cnt++;
				if (cnt % 4 == 0)printf("\n");
			}
		}
		printf("\n������ ���ڰ� ������ y, ������ n�Է�: ");
		scanf_s("%c", &answer, 1); getchar();

		if (answer == 'y') b[i] = true;
		else b[i] = false;

		cnt = 0;
		k *= 2;
	}

	k = 1;
	answer = 0;
	for (i = 0; i < log2(n); i++) {
		if (b[i] == 1) answer += k;
		k *= 2;
	}

	if (answer <= n) printf("\n������ ���ڴ� %d�Դϴ�.\n\n", answer);
	else printf("\n��信 ������ �ֽ��ϴ�.\n\n");

	return 0;
}