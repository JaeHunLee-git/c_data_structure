// 테스트 데이터 모두 통과
/*
괄호가 포함된 하나의 공백 없는 문자열을 입력하여 열린 괄호와 닫힌 괄호의 순서를
숫자로 표시하는 프로그램을 만들어라
*/
#define _CRT_SECURE_NO_WARINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

int main(void) {
	char word[MAX_LENGTH];
	scanf("%s", word);
	int k = 0;
	int x;
	int h = 0;
	int count[MAX_LENGTH] = { 0, };
	for (int i = 0; i < strlen(word); i++) {
		if (word[i] == '(') {
			printf("%d ", ++k);
			x = k;
		}
		if (word[i] == ')') {
			for (int j = 0; j < h; j++) {
				if (x == count[j])x--;
			}
			printf("%d ", x);
			count[h] = x;
			x--;
			h++;
		}
	}
	return 0;
}
