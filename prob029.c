// 테스트 데이터 모두 통과
/*
N=1~15인 경우에 대해 N-queens 문제의 해의 개수를 구하라
*/
#pragma warning(disable : 4996)
#include <stdio.h>

int vx[16], vy[16];

int check(int a, int b)
{
    if (a - b >= 0)
        return a - b;
    else
        return (a - b) * -1;
}

int n_queen(int x, int y, int n)
{
    int i;
    i = 0;
    while (i < y)
    {
        if (y == vy[i])
            return 0;
        if (x == vx[i])
            return 0;
        if (check(x, vx[i]) == check(y, vy[i]))
            return 0;
        i++;
    }
    if (y == n - 1)
        return 1;
    vx[y] = x;
    vy[y] = y;
    int count = 0;
    i = 0;
    while (i < n)
    {
        count = count + n_queen(i, y + 1, n);
        i++;
    }
    return count;
}

int main()
{
    int k = 0;
    int n = 1;
    while (k < 15)
    {
        int i = 0;
        int count = 0;
        while (i < n)
        {
            count = count + n_queen(i, 0, n);
            i++;
        }
        printf("%d\n", count);
        n++;
        k++;
    }
}