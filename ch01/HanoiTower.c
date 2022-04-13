#include <stdio.h>

//원판을 옮기는 함수
void HanoiTower(int n, char a, char b, char c) {
	if (n == 1) printf("원판 %d, %c -> %c\n", n, a, c); //1번 원판을 목적지로 실제 옮김
	else {
		HanoiTower(n - 1, a, c, b);//(n - 1)개를 a(출발지) -> b(경유지)로 요청
		printf("원판 %d, %c -> %c\n", n, a, c); //n번 원판을 목적지로 실제 옮김
		HanoiTower(n - 1, b, a, c);//(n - 1)개를 b(경유지) -> c(목적지)로 요청
	}
}

int main(void) {
	int n = 4; //n은 원판의 개수

	//n개의 원판을 출발지에서 목적지로 옮겨달라고 요청
	HanoiTower(n, 'A', 'B', 'C'); //A는 출발지, B는 경유지, C는 목적지

	return 0;
}