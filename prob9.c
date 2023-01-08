// 테스트 데이터를 모두 통과
/*
단어를 입력 받고 입력 받은 단어를 접두어로 하는 harry.txt의 파일의 모든 단어를 나열
중복은 제외
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 100

int main()
{
    char* word;
    char* data[100000];
    char tmp[BUF_SIZE];
    char insert[BUF_SIZE];

    FILE* fp = fopen("harry.txt", "r");
    int cnt = 0;
    for (cnt; !feof(fp); cnt++)
    {
        word = (char*)malloc(sizeof(char) * BUF_SIZE);
        fscanf(fp, "%s", word);
        data[cnt] = word;
    }
    cnt--;

    for (int i = 0; i < cnt; i++)   //사전식 정렬
    {
        for (int j = i + 1; j < cnt; j++)
        {
            if (strcmp(data[i], data[j]) > 0)
            {
                strcpy(tmp, data[i]);
                strcpy(data[i], data[j]);
                strcpy(data[j], tmp);
            }
        }
    }
    int idx = 0;
    while (idx <= cnt)
    {
        if (strcmp(data[idx], data[idx + 1]) == 0)
        {
            for (int i = idx + 1; i < cnt - 1; i++)
            {
                strcpy(data[i], data[i + 1]);
            }
            idx--;
            cnt--;
        }
        idx++;
    }
    int k = 0;
    scanf("%s", insert);

    for (int i = 0; i < cnt; i++)
    {
        if (strncmp(insert, data[i], strlen(insert)) == 0)
        {
            printf("%s\n", data[i]);
            k++;
        }
    }
    printf("%d", k);
    fclose(fp);
    return 0;
}