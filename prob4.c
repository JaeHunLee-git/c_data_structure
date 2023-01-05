//테스트 데이터를 모두 통과했습니다.
/*100보다 작은 정수 n을 입력 받고 n개의 정수를 입력 받은 후
  하나의 정수 k를 입력 받아 k와 가장 비슷한 수를 출력*/
#include<stdio.h>
int main(void) {
	int n, k;
	int a[100];
	int b[100];
	int s;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &k);
	for (int i = 0; i < n; i++) {
		b[i] = k - a[i];
		if (b[i] < 0) b[i] = -b[i];
		else continue;
	}
	for (int i = 0; i < n; i++) {
		for (int k = i + 1; k < n; k++) {
			if (b[i] > b[k]) {
				s = b[i];
				b[i] = b[k];
				b[k] = s;
				s = a[i];
				a[i] = a[k];
				a[k] = s;
			}
		}
	}
	printf("%d", a[0]);
	return 0;
}