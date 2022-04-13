//�̷λ��� �˰��� �Ұ� ����Ʈ http://www.jamisbuck.org/mazes/
/*
������ ��������� ������ �� �ִ� �� ����(�¿���� ��)�� ���Ƿ� �����Ͽ� ���� �㹰�� ����(�̷� ǥ��)�ϴٰ�
�� �̻� ������ �� ������ �������� ���ư��鼭 ������ �� �ִ� �ٸ� �������� ��� �̷θ� ����� ������ ���
������ �� ���� ������ �迭 ������ ����ų� ���� �̷θ� ������ ���
���� �̷������� ���� �㹰�� ����Ŭ�� �����Ǿ� �ɵ��� ��ΰ� ��������� ������ �����Ǿ�� ��
*/

/*
�̷� �࿭�� ���� �������� �ʴ� �������
�̷� ���� ���� c, ���� r���� ������� �� ���
�̷� �࿭�� �� ũ��� r, �� ũ��� c�� �غ��ϰ�
�� �̷� �濡�� �㹮 ���� ������ �����ϰ� �ִٰ� ����� �� ������
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//�̷� �� ����
struct cell {

	char searchDir; //�� �濡���� Ž�� ����

	char mazeDir; //�� �濡���� �̷� ���� ����

};

//�̷� ũ��, row�� ��, col�� �� ũ��
int row, col;

//�̷θ� ����� �ͷ� ȣ�� ������� ����� ����
void mazeCreating(struct cell** mazeMark, int i, int j) {
	int view_i, view_j, dir;
	int move[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//�����¿�

	while (mazeMark[i][j].searchDir < 15) { //�����¿� ��� ���� �� ������ �ݺ�

		do {

			dir = rand() % 4; //4���� �� ������ ����

		} while ((mazeMark[i][j].searchDir & (1 << dir)) >= 1); //dir�� ���캻 �����̸� dir �ٽ� ����

		//�̵� ������ ǥ����. dir�� 3�̸� �����ʿ��� �� ��°�� 1�� �ǰ� ��. 00000100
		//4���� ��� ���캸�Ҵٸ� 00001111 => 15
		mazeMark[i][j].searchDir |= (1 << dir);

		//�̵��� ���� ��ǥ�� ����
		view_i = i + move[dir][0];
		view_j = j + move[dir][1];

		//�̵��� ���� ��ǥ�� �̷� �࿭ �������� �ְ�
		if (view_i >= 0 && view_i < row && view_j >= 0 && view_j < col) {

			//Ž���� ���� �ʾҴٸ�
			if (mazeMark[view_i][view_j].searchDir == 0) {

				//�̷� ���� ǥ��. ���� �㹰��
				mazeMark[i][j].mazeDir |= (1 << dir);

				//�̵��� �濡�� ���� ������ ��Ǯ����
				mazeCreating(mazeMark, view_i, view_j);

			}

		}

	}

}

int main(void) {
	int i, j;
	struct cell** mazeMark;

	printf("�̷��� �� ũ��: ");

	do {

		scanf_s("%d", &row);

		if (row < 1) printf("\n�ٽ� �Է��ϼ���: ");

	} while (row < 1);

	printf("�̷��� �� ũ��: ");

	do {

		scanf_s("%d", &col);

		if (col < 1) printf("\n�ٽ� �Է��ϼ���: ");

	} while (col < 1);

	//2���� �迭ó�� ����� mazeMark �غ�
	mazeMark = (struct cell**)malloc(sizeof(struct cell*) * row);

	for (i = 0; i < row; i++) mazeMark[i] = (struct cell*)malloc(sizeof(struct cell) * col);

	//��� ����� ��Ž������ ä��
	for (i = 0; i < row; i++) {

		for (j = 0; j < col; j++) {

			mazeMark[i][j].searchDir = 0;

			mazeMark[i][j].mazeDir = 0;

		}

	}

	srand((unsigned int)time(NULL));

	//������� ���Ƿ� ����
	i = (int)rand() % row;
	j = (int)rand() % col;

	//����� ǥ��
	mazeMark[i][j].mazeDir |= (1 << 4);

	//����� �ͷ� ��� ȣ��
	mazeCreating(mazeMark, i, j);

	//�̷θ� �����
	printf("\n\n����� �ͷ�(Recursive Backtracking) ���");
	printf("\n\n��:�����, ��:�̷λ��� ����, ��:��\n\n");

	for (i = 0; i <= col * 2; i++) printf("��");
	printf("\n");

	for (i = 0; i < row; i++) {

		printf("��");

		for (j = 0; j < col; j++) {

			if (mazeMark[i][j].mazeDir & 16) printf("��");

			else printf("��");

			if (j == col - 1) {

				printf("��");

				break;
			}

			if (mazeMark[i][j + 1].mazeDir & 4) printf("��");

			else if (mazeMark[i][j].mazeDir & 8) printf("��");

			else printf("��");

		}

		printf("\n");

		if (i == row - 1) break;

		printf("��");

		for (j = 0; j < col; j++) {

			if (mazeMark[i][j].mazeDir & 2) printf("��");

			else if (mazeMark[i + 1][j].mazeDir & 1) printf("��");

			else printf("��");

			printf("��");

		}

		printf("\n");
	}


	for (i = 0; i <= col * 2; i++) printf("��");

	printf("\n");

	return 0;

}