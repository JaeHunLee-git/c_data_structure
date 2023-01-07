//테스트 데이터 모두 통과
/*
영문 소문자로 구성된 2개의 단어를 입력받은 후 두 단어가 동일한 문자집합으로 구성되었는지를 검사
하여 yes 혹은 no를 출력하는 프로그램을 작성하라. 예를 들어 ababc와 cba는 문자집합 {a, b, c}
로 구성되었으므로 yes이다. 입력 단어의 길이는 20이하이다
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char word1[20];
    char word2[20];
    int com1[27] = { 0 };
    int com2[27] = { 0 };
    int x = 0;
    scanf("%s", word1);
    scanf("%s", word2);
    for (int i = 0; i < strlen(word1); i++)
    {
        com1[word1[i] - 'a'] += 1;
    }
    for (int j = 0; j < strlen(word2); j++)
    {
        com2[word2[j] - 'a'] += 1;
    }
    for (int k = 0; k < 27; k++)
    {
        if ((com1[k] == 0 && com2[k] != 0) || (com1[k] != 0 && com2[k] == 0))
        {
            x++;
            break;
        }
    }
    if (x > 0)
    {
        printf("no");
    }
    else
        printf("yes");
    return 0;
}
