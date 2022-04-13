#include<stdio.h>
#include<malloc.h>

//이진트리에 사용할 노드
struct node {
	struct node* llink;
	char data;
	struct node* rlink;
};

struct node** queue;

int rear = -1, front = 0;
int nodeCnt = 0;

//노드 생성 함수
struct node* newNode(char value) {
	struct node* p;

	p = (struct node*)malloc(sizeof(struct node));
	p->llink = NULL;
	p->data = value;
	p->rlink = NULL;

	return p;
}

//이진트리 구성 함수
struct node* createBinaryTree(char a[]) {
	struct node* root;

	root = newNode(a[0]);
	root->llink = newNode(a[1]);
	root->rlink = newNode(a[2]);
	root->llink->llink = newNode(a[3]);
	root->llink->rlink = newNode(a[4]);
	root->rlink->llink = newNode(a[5]);
	root->rlink->rlink = newNode(a[6]);
	root->llink->llink->rlink = newNode(a[7]);
	root->rlink->llink->llink = newNode(a[8]);
	root->rlink->llink->llink->llink = newNode(a[9]);

	return root;
}

//후위운행 함수
void postOrder(struct node* p) {
	if (p != NULL) {
		postOrder(p->llink);
		postOrder(p->rlink);
		printf("%c->", p->data);
	}
}

//큐에 add함
void add(struct node* p) {
	if (rear == nodeCnt - 1) {
		printf("\nQudue is Full!");
		return;
	}
	queue[++rear] = p;
}

//큐를 사용함
struct node* delete(void) {
	if (rear < front) {
		printf("\n\nQudue is Empty!");
		return NULL;
	}
	return queue[front++];
}

//이진트리 모든 노드 소멸
void deleteAll(struct node* p) {
	if (p != NULL) {
		deleteAll(p->llink);
		deleteAll(p->rlink);
		free(p);
	}
}

void levelOrder(struct node* p) {
	printf("%c", p->data);
	add(p);
	while ((p = delete()) != NULL) {
		if (p->llink != NULL) {
			printf("->%c", p->llink->data);
			add(p->llink);
		}
		if (p->rlink != NULL) {
			printf("->%c", p->rlink->data);
			add(p->rlink);
		}
	}
}

int main(void) {
	char a[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	struct node* root;

	root = createBinaryTree(a);
	nodeCnt = sizeof(a) / sizeof(char);

	printf("\n후위 운행 결과: ");
	postOrder(root);
	printf("\b\b  ");

	queue = (struct node**)malloc(sizeof(struct node*) * nodeCnt);

	printf("\n\n1차원 배열을 사용하여 큐를 구현함");

	printf("\n레벨 오더 운행 결과: ");
	levelOrder(root);
	printf("\n");

	return 0;
}