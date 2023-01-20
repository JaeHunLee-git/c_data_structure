// 테스트 데이터 모두 통과
/*
N개의 수를 입력 받고 K를 입력 받아 합이 K가 되는 정수 쌍의 개수를 카운트하라
*/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#define MAX 1000

int data[MAX];
int N, k;
int count = 0;

void SUM(int start1, int end1)
{
    int sum = data[start1] + data[end1];
    if (start1 < end1)
    {
        if (sum > k)
            SUM(start1, end1 - 1);
        else if (sum < k)
            SUM(start1 + 1, end1);
        else
        {
            count++;
            SUM(start1 + 1, end1 - 1);
        }
    }
}
int main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &data[i]);
    }
    scanf("%d", &k);
    int start = 0, end = N - 1;
    SUM(start, end);
    printf("%d", count);
    return 0;
}