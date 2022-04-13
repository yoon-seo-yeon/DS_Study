#include <stdio.h>

//������ �ű�� �Լ�
void HanoiTower(int n, char a, char b, char c) {
	if (n == 1) printf("���� %d, %c -> %c\n", n, a, c); //1�� ������ �������� ���� �ű�
	else {
		HanoiTower(n - 1, a, c, b);//(n - 1)���� a(�����) -> b(������)�� ��û
		printf("���� %d, %c -> %c\n", n, a, c); //n�� ������ �������� ���� �ű�
		HanoiTower(n - 1, b, a, c);//(n - 1)���� b(������) -> c(������)�� ��û
	}
}

int main(void) {
	int n = 4; //n�� ������ ����

	//n���� ������ ��������� �������� �Űܴ޶�� ��û
	HanoiTower(n, 'A', 'B', 'C'); //A�� �����, B�� ������, C�� ������

	return 0;
}