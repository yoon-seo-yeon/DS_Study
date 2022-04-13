#include <stdio.h>

int main() {
	int a[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				printf("%d %d %d", a[i], a[j], a[k]);
				printf("\t");
			}
		}
	}

	return 0;
}