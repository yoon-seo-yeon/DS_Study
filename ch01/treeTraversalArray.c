#include <stdio.h>

int n;

void preOrder(char a[], int node_num) {
	if (node_num < n && a[node_num] != NULL) {
		printf("%c  ", a[node_num]);
		preOrder(a, node_num * 2);
		preOrder(a, node_num * 2 + 1);
	}
}

void inOrder(char a[], int node_num) {
	if (node_num < n && a[node_num] != NULL) {
		inOrder(a, node_num * 2);
		printf("%c  ", a[node_num]);
		inOrder(a, node_num * 2 + 1);
	}
}

void postOrder(char a[], int node_num) {
	if (node_num < n && a[node_num] != NULL) {
		postOrder(a, node_num * 2);
		postOrder(a, node_num * 2 + 1);
		printf("%c  ", a[node_num]);
	}
}

int main(void) {
	char a[] = { NULL, 'A', 'B', 'C', 'D', 'E', NULL, 'F', NULL, NULL, 'G', NULL, NULL, NULL, 'H', 'I', NULL, NULL, NULL, NULL, NULL, 'J' };

	n = sizeof(a) / sizeof(char);

	preOrder(a, 1);
	printf("\n");
	inOrder(a, 1);
	printf("\n");
	postOrder(a, 1);
	printf("\n");

	return 0;
}