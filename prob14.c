//테스트 데이터 모두 통과
/*
n을 입력 받아 n개의 수로 이루어진 수열에서 역전된 수의 개수를 출력
*/
#include <stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int a[100];
	int count = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) count++;
		}
	}
	printf("%d", count);
	return 0;
}