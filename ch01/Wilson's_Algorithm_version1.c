/*
���� �ϳ��� ��(������)�� ���� ����, �ٸ� ��(�����)����
�¿���� �� ������ �������� ���� �����ϸ鼭 �����ϱ⸦ �ݺ��ϴٰ�
���� ���� ���� �̷θ� ������ ��������� �ǵ��ư��� �ٽ� �����ϰ�
�������� ������ ���ݱ����� ��ο� ���Ͽ� �̷θ� ǥ���Ѵ�.
�� �������ʹ� ���Ƿ� ���� ��������� ������ �̷θ� ���� ������
������ �������� �����ϴٰ� �̷θ� ������ ���ݱ����� ��θ� �̷ο� �߰��ϱ⸦
��� ���� �̷��� ��θ� ���� ������ �� ������ �ݺ��Ѵ�.
������ �������̳� �̷θ� ������ ���� ��Ŵ� �ݺ�Ƚ���� ���� �����.
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

int main(void) {
	int i, j, k = 0;
	int row, col;
	int view_i, view_j, d, chk_cnt;
	int move[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//�����¿�
	int** maze;

	struct room {
		int r;
		int c;
	}*unknown;

	struct candidate_room {
		int r;
		int c;
		int d;
	}*candidate;

	printf("�̷��� �� ũ��: ");

	scanf_s("%d", &row);

	printf("\n�̷��� �� ũ��: ");

	scanf_s("%d", &col);

	//2���� �迭ó�� ����� maze ����
	maze = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++) maze[i] = (int*)malloc(sizeof(int) * col);

	//�̷� �� ��ü ���� 
	chk_cnt = row * col;

	//���� ����Ʈ �غ�
	unknown = (struct room*)malloc(sizeof(struct room) * chk_cnt);

	//�ĺ� �̷� ����Ʈ �غ�
	candidate = (struct candidate_room*)malloc(sizeof(struct candidate_room) * chk_cnt);

	//�̷� ��� ��ü�� 0(��Ž��)���� ä���, ��� ���� ���� ����Ʈ�� ���ʷ� ����
	for (i = 0; i < row; i++) {

		for (j = 0; j < col; j++) {

			maze[i][j] = 0;

			unknown[k].r = i;

			unknown[k].c = j;

			k++;

		}

	}

	srand((unsigned int)time(NULL));

	//������ ���� ����
	k = rand() % chk_cnt;

	//���� ���� ǥ��
	maze[unknown[k].r][unknown[k].c] |= (1 << 4); //������ 10000�� bit OR

	//���� ����Ʈ���� ����. �� ���� ��ǥ�� k ������ �̵�
	chk_cnt--; //���� ����Ʈ���� �ϳ� ����
	unknown[k].r = unknown[chk_cnt].r;
	unknown[k].c = unknown[chk_cnt].c;

	//���� ����Ʈ�� ���� ���� ������ �ݺ�
	while (chk_cnt > 0) {

		//������ ���� ����
		k = rand() % chk_cnt;
		i = unknown[k].r;
		j = unknown[k].c;

		//�ĺ� �̷� ����Ʈ�� �߰� 
		k = 0;
		candidate[k].r = i;
		candidate[k].c = j;

		//����� ǥ��
		maze[i][j] |= (1 << 6); //������ 1000000�� bit OR

		//�ĺ� �̷ι� ǥ��
		maze[i][j] |= (1 << 5); //������ 100000�� bit OR

		//�̷� ���� ������ �ݺ�
		while (1) {

			d = rand() % 4;
			view_i = i + move[d][0];
			view_j = j + move[d][1];

			//�̷� ���� ���̸� �ٽ� ���� ���� 
			if (view_i < 0 || view_i >= row || view_j < 0 || view_j >= col) continue;

			//(view_i, view_j)���� ������ �����ϰ�
			candidate[k].d = d;

			//���� �̵��� ��(view_i, view_j)�� �ĺ��� �߰�
			k++;
			candidate[k].r = view_i;
			candidate[k].c = view_j;

			//���� ���� ��Ž���̸� �����ϰ� �ĺ� �̷����� ǥ��
			if (maze[view_i][view_j] == 0) {

				i = view_i;
				j = view_j;

				maze[i][j] |= (1 << 5); //������ 100000�� bit OR

			}

			else if ((maze[view_i][view_j] & 31) > 0)break; //�̷θ� ������ ��������

			else { //maze[view_i][view_j] & 32 �Ǵ� maze[view_i][view_j] & 64 �� ��, �ĺ� �̷θ� �������Ƿ� ����Ŭ�� ������

				//���� �ĺ�
				k--;

				do { //(view_i, view_j)�� ���� ������ ����� ����

					//�������� �ǵ��� ���鼭 �ĺ�(32)�� ���(0)��
					maze[candidate[k].r][candidate[k].c] = 0;

					k--;

				} while (candidate[k].r != view_i || candidate[k].c != view_j);

				//����Ŭ�� �������� ���ƿ� �ٽ� �̷� ã�� ����
				i = view_i;
				j = view_j;

			}

		}

		//���� �������� �̷θ� ���� �������� �̷� ǥ���ϰ� �̷ι渶�� ��������Ʈ���� ������ 
		for (i = 0; i < k; i++) {

			//�̷� ���� ǥ��
			maze[candidate[i].r][candidate[i].c] |= (1 << candidate[i].d);

			//���� ����Ʈ���� �ϳ� ����
			chk_cnt--;

			//�ĺ� ��ġ Ž��
			for (j = 0; j < chk_cnt; j++) if (candidate[i].r == unknown[j].r && candidate[i].c == unknown[j].c) break;

			//�ĺ��� �̷η� ����Ǹ鼭 ����Ʈ���� ����. �� ���� ��ǥ�� j ������ �̵�
			unknown[j].r = unknown[chk_cnt].r;
			unknown[j].c = unknown[chk_cnt].c;

		}

	}

	//�̷θ� ����� 
	printf("\n\nWilson's Algorithm");
	printf("\n\n��:���� ����, ��:�����, ��:�̷λ��� ����, ��:�̷ι�, ��:��\n\n");

	for (i = 0; i <= col * 2; i++) printf("��");

	printf("\n");

	for (i = 0; i < row; i++) {

		printf("��");

		for (j = 0; j < col; j++) {

			if (maze[i][j] & 64) printf("��");

			else if (maze[i][j] & 16) printf("��");

			else printf("��");

			if (j == col - 1) {

				printf("��");

				break;
			}

			if (maze[i][j + 1] & 4) printf("��");

			else if (maze[i][j] & 8) printf("��");

			else printf("��");

		}

		printf("\n");

		if (i == row - 1) break;

		printf("��");

		for (j = 0; j < col; j++) {

			if (maze[i][j] & 2) printf("��");

			else if (maze[i + 1][j] & 1) printf("��");

			else printf("��");

			printf("��");

		}

		printf("\n");
	}

	for (i = 0; i <= col * 2; i++) printf("��");

	printf("\n");


	//�̷� ���� ���� �����ϰ� ���
	printf("\n\n���̷� ���� ���� �����ϰ� ��¡�\n\n");

	for (i = 0; i <= col * 2; i++) printf("��");

	printf("\n");

	for (i = 0; i < row; i++) {

		printf("��");

		for (j = 0; j < col; j++) {

			if (maze[i][j] & 16) printf("��");

			else if (maze[i][j] & 32) printf("��");

			else printf("��");

			if (j == col - 1) {

				printf("��");

				break;

			}

			if (maze[i][j + 1] & 4) printf("��");

			else if (maze[i][j] & 8) printf("��");

			else printf("��");

		}

		printf("\n");

		if (i == row - 1) break;

		printf("��");

		for (j = 0; j < col; j++) {

			if (maze[i][j] & 2) printf("��");

			else if (maze[i + 1][j] & 1) printf("��");

			else printf("��");

			printf("��");

		}

		printf("\n");
	}

	for (i = 0; i <= col * 2; i++) printf("��");

	printf("\n");

	return 0;

}