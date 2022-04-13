#include<stdio.h>
#include<stdlib.h>
#define NEW (struct node *)malloc(sizeof(struct node))

//함수 원형 선언
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

	printf("노드 생성 순서: ");
	root = BinaryTree(a, 0, n - 1);
	printf("\n좌우 균형되게 이진 트리 구성함!\n");

	printf("사라지는 노드 순서: ");
	Delete(root);
	printf("\n\n");

	return 0;
}

//정렬된 1차원 배열 -> 좌우 균형된 이진 트리 생성
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

//모든 노드 제거
void Delete(struct node* DelNode) {
	if (DelNode != NULL) {
		Delete(DelNode->llink);
		Delete(DelNode->rlink);
		printf("%d  ", DelNode->data);
		free(DelNode);
	}
}