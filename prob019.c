// 테스트 데이터 모두 통과
/*
board.txt의 바둑판 상태를 읽어서 어느 돌이 이긴지를 판단하는 프로그램을 만들어라.
*/
#pragma warning(disable:4996)
#include <stdio.h>
#define MAX 100

int main(void) {
	FILE* fp = fopen("board.txt", "r");
	int n;
	int egg[MAX][MAX];
	int count1[MAX] = { 0 };    //1은 검은돌
	int count2[MAX] = { 0 };   //2는 흰돌
	int x, y;
	int k = 0;
	int k1 = 0;
	int result = 0;
	fscanf(fp, "%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(fp, "%d", &egg[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (egg[i][j] == 1) {
				while (1) {
					x = i;
					y = j;
					while (egg[x][++y] == 1) {
						count1[k]++;
					}
					k++;
					if (egg[x][y] != 1)break;
				}
				while (1) {
					x = i;
					y = j;
					while (egg[++x][--y] == 1) {
						count1[k]++;
					}
					k++;
					if (egg[x][y] != 1)break;
				}
				while (1) {
					x = i;
					y = j;
					while (egg[++x][y] == 1) {
						count1[k]++;
					}
					k++;
					if (egg[x][y] != 1)break;
				}
				while (1) {
					x = i;
					y = j;
					while (egg[++x][++y] == 1) {
						count1[k]++;
					}
					k++;
					if (egg[x][y] != 1)break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (egg[i][j] == 2) {
				while (1) {
					x = i;
					y = j;
					while (egg[x][++y] == 2) {
						count2[k1]++;
					}
					k1++;
					if (egg[x][y] != 2)break;
				}
				while (1) {
					x = i;
					y = j;
					while (egg[++x][--y] == 2) {
						count2[k1]++;
					}
					k1++;
					if (egg[x][y] != 2)break;
				}
				while (1) {
					x = i;
					y = j;
					while (egg[++x][y] == 2) {
						count2[k1]++;
					}
					k1++;
					if (egg[x][y] != 2)break;
				}
				while (1) {
					x = i;
					y = j;
					while (egg[++x][++y] == 2) {
						count2[k1]++;
					}
					k1++;
					if (egg[x][y] != 2)break;
				}
			}
		}
	}
	for (int i = 0; i < k; i++) {
		if (count1[i] == 4) {
			printf("Black");
			result++;
			break;
		}
	}
	for (int i = 0; i < k1; i++) {
		if (count2[i] == 4) {
			printf("White");
			result++;
			break;
		}
	}
	if (result == 0)printf("Not Finished");
	return 0;
}
