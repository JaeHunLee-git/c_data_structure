//테스트 데이터 모두 통과
/*
시작점이 빠른 순서대로 출력하고 시작점이 같으면 끝점이 빠른 것을 먼저 출력하라.
*/
#include<stdio.h>
int main(void) {
	int n;
	int start[100];
	int end[100];
	int x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &start[i]);
		scanf("%d", &end[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (start[i] > start[j]) {
				x = start[i];
				start[i] = start[j];
				start[j] = x;

				x = end[i];
				end[i] = end[j];
				end[j] = x;
			}
			else if (start[i] == start[j] && end[i] > end[j]) {
				x = start[i];
				start[i] = start[j];
				start[j] = x;

				x = end[i];
				end[i] = end[j];
				end[j] = x;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", start[i], end[i]);
	}


	return 0;
}