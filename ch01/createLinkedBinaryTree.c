#include<stdio.h>
#include<stdlib.h>
#define NEW (struct node *)malloc(sizeof(struct node))

//�Լ� ���� ����
struct node* BinaryTree(int[], int, int);
void Delete(struct node*);

struct node {
	struct node* llink;
	int data;
	struct node* rlink;
};

int main(void) {
	int a[] = { 3, 5, 7, 10, 15, 17, 20, 25, 28, 31, 33, 35 };
	struct node* root;
	int n = sizeof(a) / sizeof(int);

	printf("��� ���� ����: ");
	root = BinaryTree(a, 0, n - 1);
	printf("\n�¿� �����ǰ� ���� Ʈ�� ������!\n");

	printf("������� ��� ����: ");
	Delete(root);
	printf("\n\n");

	return 0;
}

//���ĵ� 1���� �迭 -> �¿� ������ ���� Ʈ�� ����
struct node* BinaryTree(int a[], int left, int right) {
	int mid;
	struct node* p = NULL;

	if (left <= right) {
		mid = (left + right) / 2;
		p = NEW;
		p->data = a[mid];
		printf("%d  ", p->data);
		p->llink = BinaryTree(a, left, mid - 1);
		p->rlink = BinaryTree(a, mid + 1, right);
	}
	return p;
}

//��� ��� ����
void Delete(struct node* DelNode) {
	if (DelNode != NULL) {
		Delete(DelNode->llink);
		Delete(DelNode->rlink);
		printf("%d  ", DelNode->data);
		free(DelNode);
	}
}