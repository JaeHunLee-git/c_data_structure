//테스트 데이터를 모두 통과
/*먼저 입력될 정수의 개수 2<=n && n<=100을 입력받고, 이어서 n개의 정수를 입력받는다. 입력된 정수들 중
에서 최소값과 두번째로 작은 값을 찾아 출력하는 프로그램을 작성하라. 만약 최소값이 2개 이상 중복
되어 존재하면 그 중 하나를 최소값으로, 다른 하나를 두 번째로 작은 값으로 간주한다*/
#include<stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int num[100];
	int s;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int k = i+1; k < n; k++) {
			if (num[i] > num[k]) {
				s = num[i];
				num[i] = num[k];
				num[k] = s;
			}
			else continue;
		}
	}
		printf("%d %d", num[0], num[1]);
	return 0;
}