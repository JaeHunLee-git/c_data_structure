// 테스트 데이터 모두 통과
/*
두 문자열을 받은 후 str1이 str2보다 사전순으로 빠르면 -1, 같으면 0, 늦으면 1을 반환하라.
int compare(char* st1, char* str2)의 순환함수로 작성하라.
*/
#pragma warning(disable : 4996)
#include <stdio.h>
#define MAX_LENGTH 100

int j = 0;
int compare(char *str1, char *str2)
{
    if (str1[j] - str2[j] < 0)
        return -1;
    else if (str1[j] - str2[j] > 0)
        return 1;
    if (str1[j] - str2[j] == 0)
    {
        if (j == strlen(str1) - 1 && j == strlen(str2) - 1)
            return 0;
        j++;
        compare(str1, str2);
    }
}
int main(void)
{
    char word1[MAX_LENGTH];
    char word2[MAX_LENGTH];
    scanf("%s", word1);
    scanf("%s", word2);
    printf("%d", compare(word1, word2));
    return 0;
}