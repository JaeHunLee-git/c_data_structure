// 테스트 데이터 모두 통과
/*
순환 함수를 이용하여 k보다 작거나 같으면서 가장 큰 수를 찾는 floor함수와
k보다 크거나 같으면서 가장 작은 수를 찾는 ceiling함수를 작성하라.
*/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#define MAX 1000

int data[MAX];
int N, k;
int small = 0;
int large = 0;

void floor(start)
{
    if (start < N)
    {
        if (k >= data[start])
        {
            small = data[start];
            floor(start + 1);
        }
    }
}
void ceiling(end)
{
    if (end > -1)
    {
        if (data[end] >= k)
        {
            large = data[end];
            ceiling(end - 1);
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
    floor(start);
    ceiling(end);
    if (small == 0)
        small = -1;
    if (large == 0)
        large = -1;
    printf("%d\n%d", small, large);
    return 0;
}