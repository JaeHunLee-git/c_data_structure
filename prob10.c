//테스트 데이터 모두 통과
/*
파일에 등장하는 길이가 6이상인 모든 단어의 목록과 각 단어의 등장 빈도를 구하여 화면으로 출
력하는 프로그램을 작성하라. 단어들은 사전식 순서로 정렬되어 출력되어야 한다. 출력 파일의 각 줄에
하나의 단어와 그 단어의 등장 빈도를 콜론(:)으로 구분하여 출력하라. 동일한 단어가 중복해서 출력되
어서는 안된다
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main()
{
    char* name;
    char* word[100000];
    char temp[MAX];
    char insert[MAX];

    FILE* fp = NULL;
    int cnt = 0;

    fp = fopen("harry.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "File Open Error!\n");
        exit(1);
    }
    int a = 0;
    while (!feof(fp)) //파일의 끝에 도달 여부
    {
        name = (char*)malloc(sizeof(char) * MAX);
        fscanf(fp, "%s", name); //파일에 쓰여있는 데이터를 읽음
        if (strlen(name) >= 6) {
            word[a] = name;
            a++;
        }
    }
    a--;

    for (int i = 0; i < a; i++) {
        for (int j = i + 1; j < a; j++) {
            if (strcmp(word[i], word[j]) > 0) {
                strcpy(temp, word[i]);
                strcpy(word[i], word[j]);
                strcpy(word[j], temp);
            }

        }
    }

    int idx = 0;
    int idx2 = 0;
    int count2 = 0;
    while (idx < a) {
        int count = 0;
        idx2 = idx + 1;
        if (strcmp(word[idx], word[idx2]) == 0) {
            while (strcmp(word[idx], word[idx2]) == 0) {
                count++;
                idx2++;
            }
        }
        printf("%s: %d\n", word[idx], count + 1);
        idx = idx2;
        count2++;
    }
    printf("%d", count2);

    for (int i = 0; i < a; i++)
        free(word[i]);

    fclose(fp);

    return 0;
}