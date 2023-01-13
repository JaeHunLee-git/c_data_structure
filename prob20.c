//  테스트 데이터 모두 통과
/*
sample.html을 읽어서 모든 태그를 제거한 후 sample.txt라는 파일로 저장하라.
*/
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

int main(void) {
	char* word[MAX];
	char line[MAX];
	char* result[MAX];
	char* result1[MAX];
	int k = 0;
	int n = 0;

	FILE* fp = fopen("sample.html", "r");
	FILE* fs = fopen("sample.txt", "w");

	while (fgets(line, MAX, fp) != NULL) {
		char* ptr = strtok(line, ">");
		while (ptr != NULL)
		{
			word[k++] = strdup(ptr);
			ptr = strtok(NULL, ">");
		}
	}
	fclose(fp);
	for (int i = 0; i < k; i++) {
		if (word[i][0] != '<') {
			result[n] = word[i];
			n++;
		}
	}
	for (int i = 0; i < n; i++) {
		char* ptr1 = strtok(result[i], "<");
		while (ptr1 != NULL)
		{
			result1[i] = strdup(ptr1);
			ptr1 = strtok(NULL, "<");
		}
	}
	for (int i = 0; i < n; i++) {
		fprintf(fs, "%s", result[i]);
	}
	fclose(fs);
	return 0;
}