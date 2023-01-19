//테스트 데이터 모두 통과
/*
단어와 그 단어에 대한 설명이 들어있는 shuffled_dict.txt를 읽어
단어가 사전식 순으로 나오게 출력
*/
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

int main()
{
    char* buffer = (char*)malloc(sizeof(char) * MAX);
    char* word[MAX];
    char* line[MAX];
    FILE* fp;
    fp = fopen("shuffled_dict.txt", "r");
    int cnt = 0;
    while (fgets(buffer, MAX, fp) != NULL) {
        line[cnt] = strdup(buffer);
        word[cnt] = strdup(strtok(buffer, "\t"));
        cnt++;
    }
    fclose(fp);

    char* temp1;
    char* temp2;
    for (int i = 0; i < cnt - 1; i++) {
        for (int j = i + 1; j < cnt; j++) {
            if (strcmp(word[i], word[j]) > 0) {
                temp1 = word[i];
                word[i] = word[j];
                word[j] = temp1;
                temp2 = line[i];
                line[i] = line[j];
                line[j] = temp2;
            }
        }
    }

    FILE* fs = fopen("sorted_dict.txt", "w");
    for (int i = 0; i < cnt; i++) {
        fprintf(fs, "%s", line[i]);

    }
    fclose(fs);

    return 0;
}
