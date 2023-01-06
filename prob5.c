//테스트 데이터 모두 통과
/*n을 입력받고 n개의 수를 입력 받아 중복 된 수를 제거하고
  오름차순으로 정렬하여 출력하고 수의 개수를 출력하라*/
#include <stdio.h>
int main(void) {
	int n;
	scanf("%d", &n);
	int count = 0;
	int x;
	int a[100];
	int b[100];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int k = i + 1; k < n; k++) {
			if (a[i] == a[k]) s++;
		}
		if (s == 0) {
			b[count] = a[i];
			count++;
		}
	}
	for (int i = 0; i < count; i++) {
		for (int k = i + 1; k < count; k++) {
			if (b[i] > b[k]) {
				x = b[i];
				b[i] = b[k];
				b[k] = x;
			}
		}
	}
	printf("%d: ", count);
	for (int i = 0; i < count; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}