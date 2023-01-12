// 테스트 데이터 모두 통과
/*
data.mat을 읽어 show, colmax,colmin,slice등의 명령어를 입력 받았을 때
대응하는 값을 출력하는 프로그램을 만들어라 exit을 입력 시 프로그램을 종료한다.
*/
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

int main(void) {
	int n;
	char command[MAX];
	FILE* fp = fopen("data.mat.txt", "r");
	fscanf(fp, "%d", &n);  //n 입력 받음
	int num[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(fp, "%d", &num[i][j]);
		}
	}
	while (1) {
		int a[MAX] = { 0 };
		int x, p, y, q;
		printf("$ ");
		scanf("%s", command);
		if (strcmp(command, "exit") == 0) {
			break;
		}
		if (strcmp(command, "show") == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					printf("%d ", num[i][j]);
					if (j == 7)printf("\n");
				}
			}
		}
		if (strcmp(command, "colmax") == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (num[j][i] > a[i])a[i] = num[j][i];
				}
			}
			for (int i = 0; i < n; i++)printf("%d ", a[i]);
		}
		if (strcmp(command, "colmin") == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (num[j][i] < a[i])a[i] = num[j][i];
				}
			}
			for (int i = 0; i < n; i++)printf("%d ", a[i]);
		}
		if (strcmp(command, "rowmax") == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (num[i][j] > a[i])a[i] = num[i][j];
				}
			}
			for (int i = 0; i < n; i++) printf("%d ", a[i]);
		}
		if (strcmp(command, "rowmin") == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (num[i][j] < a[i])a[i] = num[i][j];
				}
			}
			for (int i = 0; i < n; i++) printf("%d ", a[i]);
		}
		if (strcmp(command, "slice") == 0) {
			scanf("%d %d %d %d", &x, &p, &y, &q);
			for (int x1 = x; x1 < n; x1 += p) {
				for (int y1 = y; y1 < n; y1 += q) {
					printf("%d ", num[x1][y1]);  //줄 바꿈 필요
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	fclose(fp);
	return 0;
}