// 테스트 데이터를 모두 통과했습니다.
/*
연속된 문자열에서 자음이 가장 여러 번 연속해서 등장하는 부분을 찾아서 출력하라.
*/
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main(void) {
	char word[MAX];
	scanf("%s", word);
	int count[MAX] = { 0, };
	int k = 0;
	int check[MAX] = { 0, };
	int t = 0;

	for (int i = 0; i < strlen(word); i++) {
		if (word[i] != 'a' && word[i] != 'e' && word[i] != 'i' && word[i] != 'o' && word[i] != 'u') {
			count[k]++;   //연속된 자음의 수 저장
			if (i == strlen(word) - 1) {
				check[k] = i + 1;
				k++;
			}
		}
		else {
			check[k] = i;   //자음 끝의 배열 번호 저장
			k++;
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (count[i] < count[j]) {
				t = count[i];
				count[i] = count[j];
				count[j] = t;
				t = check[i];
				check[i] = check[j];
				check[j] = t;
			}
		}
	}
	int q = 0;
	char a[MAX] = { 0, };
	//check[0] == 8 count[0] == 5
	for (int i = check[0] - count[0]; i < check[0]; i++) {
		a[q] = word[i];
		q++;
	}
	printf("%s", &a);
	//word[i]의 3부터 ~ 7 까지의 출력법

	return 0;
}