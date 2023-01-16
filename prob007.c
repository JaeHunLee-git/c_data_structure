//테스트 데이터 모두 통과
/*
100보다 작은 n을 입력 받고 길이가 짧은 것 부터 나열한다.
단 길이가 같은 것은 사전순으로 빠른 것을 먼저 나열한다.
*/
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main(void) {
	int n;
	scanf("%d", &n);
	char insert[MAX];
	char* word[MAX];
	char temp[MAX];
	for (int i = 0; i < n; i++) {
		scanf("%s", insert);
		word[i] = strdup(insert);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strlen(word[i]) > strlen(word[j])) {
				strcpy(temp, word[i]);
				strcpy(word[i], word[j]);
				strcpy(word[j], temp);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strlen(word[i]) == strlen(word[j]) && strcmp(word[i], word[j]) > 0) {
				strcpy(temp, word[i]);
				strcpy(word[i], word[j]);
				strcpy(word[j], temp);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%s\n", word[i]);
	}
	return 0;
}
