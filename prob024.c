// 테스트 데이터 모두 통과
/*
input.txt에서 주어진 미로에서 벽의 크기를 컴포넌트라고 할 때
각 컴포넌트의 크기를 출력하는 프로그램
*/
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10000

int stack[MAX_STACK_SIZE];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int N = 0;
    int T = 0;
    int n[100];
    FILE *fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &T);
    for (int i = 0; i < T; i++)
    {
        fscanf(fp, "%d", &N);
        int maze[51][51];
        int chst[51][51] = {
            0,
        };
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                fscanf(fp, "%d", &maze[j][k]);
            }
        }
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (maze[j][k] == 1 && chst[j][k] != 1)
                {
                    int cnt = 0;
                    int a = j * 100 + k;
                    chst[j][k] = 1;
                    push(a);
                    while (top != -1)
                    {
                        int add = pop();
                        cnt++;
                        int x = add / 100;
                        int y = add % 100;
                        if (maze[x - 1][y - 1] == 1 && chst[x - 1][y - 1] != 1 && x > 0 && y - 1 >= 0)
                        {
                            push((x - 1) * 100 + (y - 1));
                            chst[x - 1][y - 1] = 1;
                        }
                        if (maze[x - 1][y] == 1 && chst[x - 1][y] != 1 && x > 0)
                        {
                            push((x - 1) * 100 + y);
                            chst[x - 1][y] = 1;
                        }
                        if (maze[x - 1][y + 1] == 1 && chst[x - 1][y + 1] != 1 && x > 0 && y + 1 < N)
                        {
                            push((x - 1) * 100 + (y + 1));
                            chst[x - 1][y + 1] = 1;
                        }
                        if (maze[x][y - 1] == 1 && chst[x][y - 1] != 1 && y - 1 >= 0)
                        {
                            push(x * 100 + (y - 1));
                            chst[x][y - 1] = 1;
                        }
                        if (maze[x][y + 1] == 1 && chst[x][y + 1] != 1 && y + 1 < N)
                        {
                            push(x * 100 + (y + 1));
                            chst[x][y + 1] = 1;
                        }
                        if (maze[x + 1][y - 1] == 1 && chst[x + 1][y - 1] != 1 && x + 1 < N && y > 0)
                        {
                            push((x + 1) * 100 + (y - 1));
                            chst[x + 1][y - 1] = 1;
                        }
                        if (maze[x + 1][y] == 1 && chst[x + 1][y] != 1 && x < N)
                        {
                            push((x + 1) * 100 + y);
                            chst[x + 1][y] = 1;
                        }
                        if (maze[x + 1][y + 1] == 1 && chst[x + 1][y + 1] != 1 && x < N && y < N)
                        {
                            push((x + 1) * 100 + (y + 1));
                            chst[x + 1][y + 1] = 1;
                        }
                    }
                    top = -1;
                    printf("%d ", cnt);
                }
            }
        }
        printf("\n");
    }
    fclose(fp);

    return 0;
}