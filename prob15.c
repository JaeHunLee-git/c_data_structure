//테스트 데이터 모두 통과
/*
평균과 표준편차 구하기 단 소수점 이하 2자리까지 출력한다.
math.h를 include 하고 sqrt함수를 사용하라
*/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>

int main(void) {
	int n;
	int a[100][100] = { 0 };
	int input = 0;

	FILE* fp = fopen("input.txt", "r");

	fscanf(fp, "%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(fp, "%d", &input);  //넣어놨다 치고
			a[i][j] = input;
		}
	}
	for (int q = 0; q < n; q++) {    //n번 반복

		float ave = 0;  //평균
		float dev = 0; //표준편차
		float result = 0;

		for (int i = 0; i < n; i++) {
			printf("%d ", a[q][i]);
			ave += a[q][i];
		}
		ave /= n;
		printf("%0.2lf ", ave);

		for (int i = 0; i < n; i++) {
			dev += (a[q][i] - ave) * (a[q][i] - ave);
		}
		dev /= n;
		result = sqrt(dev);
		printf("%0.2lf ", result);

		printf("\n");

	}
	float ss[100];
	for (int q = 0; q < n; q++) {
		float ave1 = 0;  //평균
		for (int i = 0; i < n; i++) {
			ave1 += a[i][q];
		}
		ave1 /= n;
		printf("%0.2lf ", ave1);
		ss[q] = ave1;
	}
	printf("\n");

	for (int q = 0; q < n; q++) {
		float dev1 = 0; //표준편차
		float result1 = 0;
		for (int i = 0; i < n; i++) {
			dev1 += (a[i][q] - ss[q]) * (a[i][q] - ss[q]);
		}
		dev1 /= n;
		result1 = sqrt(dev1);
		printf("%0.2lf ", result1);
	}
	return 0;
}
//SQRT(숫자)   (양의 제곱근 반환)