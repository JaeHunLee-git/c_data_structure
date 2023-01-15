//테스트 데이터를 모두 통과했습니다.
/*음이 아닌 정수를 입력 받으면서 오름 차순으로 정리해 출력
  단 중복된 수면 "duplicate"를 출력 -1을 입력하면 종료*/
#include <stdio.h>
int main(void) {
	int n;
	int a[100]={0,};
	int s = 0;
	int x;
	while (1) {
		int count = 0;
		scanf("%d", &n);
		if (n != -1) {
			for (int i = 0; i < 100; i++) {
				if (n == a[i]) count++;
			}
			if (count == 0) {
				a[s] = n;
				for (int i = 0; i < s + 1; i++) {
					for (int k = i + 1; k < s + 1; k++) {
						if (a[i] > a[k]) {
							x = a[i];
							a[i] = a[k];
							a[k] = x;
						}
					}
				}
				for (int i = 0; i < s + 1; i++) {
					printf("%d ", a[i]);
				}
				s++;
			}
			else printf("duplicate");
		}
		else break;
	}
	return 0;
}
