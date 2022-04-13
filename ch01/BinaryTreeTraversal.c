#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* llink;
	char data;
	struct node* rlink;
};

struct node* CREATE(char item) {
	struct node* p;
	p = (struct node*)malloc(sizeof(struct node));

	p->data = item;
	p->llink = p->rlink=NULL;

	return p;
}

void PreOrder(struct node* p) {	//傈困 款青
	if (p != NULL) {
		printf("%c  ", p->data);	//D
		PreOrder(p->llink);			//L
		PreOrder(p->rlink);		//R
	}
}

void InOrder(struct node* p) {	//吝困 款青
	if (p != NULL) {
		InOrder(p->llink);			//L
		printf("%c  ", p->data);	//D
		InOrder(p->rlink);			//R
	}
}

void PostOrder(struct node* p) {	//饶困 款青
	if (p != NULL) {
		PostOrder(p->llink);			//L
		PostOrder(p->rlink);			//R
		printf("%c  ", p->data);		//D
	}
}

void Delete(struct node* Delnode) {
	if (Delnode != NULL) {
		Delete(Delnode->llink);
		Delete(Delnode->rlink);
		free(Delnode);
	}
}

int main(void) {
	struct node* root = CREATE('A'); 
	root->llink = CREATE('B');

	root->rlink = CREATE('C');
	root->llink-> llink = CREATE('D');

	root->llink->rlink = CREATE('E');
	root->rlink->llink = CREATE('F');

	root->llink->llink->rlink = CREATE('G');
	root->rlink->llink->llink = CREATE('H');

	root->rlink->llink->rlink = CREATE('I');
	root->rlink->llink->rlink->llink = CREATE('J');

	printf("傈困 款青(PreOrder : ");
	PreOrder(root);
	printf("\n");

	printf("吝困 款青(InOrder : ");
	InOrder(root);
	printf("\n");

	printf("饶困 款青(PostOrder : ");
	PostOrder(root);
	printf("\n");

	Delete(root);

	return 0;
}