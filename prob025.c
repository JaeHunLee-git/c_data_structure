// 테스트 데이터 모두 통과
/*
하나의 단어를 입력 받아 회문인지 아닌지 is_palindrome의 순환함수로 작성하라
*/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdbool.h>
#define MAX_LENGTH 100

bool is_palindrome(char *input, int k)
{
    if (input[k] != input[strlen(input) - k - 1])
        return false;
    if (k == strlen(input) - k - 1 || strlen(input) - k - 1 - k == -1)
        return true;
    if (k != strlen(input) - k - 1 || strlen(input) - k - 1 - k != -1)
        is_palindrome(input, k + 1);
}
int main(void)
{
    int k = 0;
    char word[MAX_LENGTH];
    scanf("%s", word);
    if (is_palindrome(word, k))
        printf("Yes");
    if (!is_palindrome(word, k))
        printf("No");
    return 0;
}