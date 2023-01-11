//테스트 데이터를 모두 통과했습니다.
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
char* word[100][100];
char* white_space(char* arr);
int main()
{
    FILE* fp = fopen("table.txt", "r");
    FILE* fw = fopen("output.txt", "w");
    int m, n;
    char str[MAX];
    if (fp == NULL)
    {
        return 0;
    }
    fscanf(fp, "%d %d ", &m, &n);
    int i = 0, j = 0;
    while (fgets(str, MAX, fp) != NULL)
    {
        if (str[strlen(str) - 1] == '\n')  //이렇게 안 해주면 줄바꿈할 때 4칸의 공백이 생김
        {
            str[strlen(str) - 1] = '\0';
        }
        if (strlen(str) <= 0)  //입력이 잘 못 되었을 때
            continue;
        char* ptr = strtok(str, "&");
        while (ptr != NULL)
        {
            ptr = white_space(ptr);
            word[i][j++] = strdup(ptr);
            ptr = strtok(NULL, "&");
        }
        j = 0;
        i++;
    }
    fclose(fp);
    int cnt[10];
    int max, len;
    for (int i = 0; i < m; i++)
    {
        max = -1;
        len = 0;
        for (int j = 0; j < n; j++)
        {
            len = strlen(word[j][i]);
            if (len > max)
            {
                max = len;
            }
        }
        cnt[i] = max;         //cnt[i]에 제일 긴 단어 길이 저장
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int len = cnt[j] - strlen(word[i][j]);
            fprintf(fw, "%s", word[i][j]);
            while (len > 0)
            {
                fprintf(fw, " ");
                len--;
            }
        }
        fprintf(fw, "\n");
    }
    fclose(fw);
    return 0;
}
char* white_space(char* arr)  //맨 뒤와 맨 앞의 공백 1칸은 디폴트 값으로 간주
{
    while (*arr == ' ')
        arr++;          //무슨 뜻?
    int idx = strlen(arr);
    for (int k = idx; k > 0; k--)
    {
        if (arr[k] == ' ' && arr[k - 1] == ' ')
        {
            for (int i = k; i < idx; i++)
            {
                arr[i] = arr[i + 1];
            }
        }
    }
    return arr;
}