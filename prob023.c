// 테스트 데이터 모두 통과
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char *Item;

typedef struct stack_type *Stack;

Stack create();
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
void reallocate(Stack s);
Item pop(Stack s);
Item peek(Stack s);

struct stack_type
{
    Item *contents;
    int top;
    int size;
};
static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(1);
}
Stack create()
{
    Stack s = (Stack)malloc(sizeof(struct stack_type));
    if (s == NULL)
    {
        terminate("Error in create: stack could not be created.");
    }
    s->contents = (Item *)malloc(100 * sizeof(Item));
    s->top = -1;
    s->size = 100;
    return s;
}
void destroy(Stack s)
{
    free(s->contents);
    free(s);
}
int is_full(Stack s)
{
    return s->top == 100;
}
void make_empty(Stack s)
{
    s->top = -1;
}
bool is_empty(Stack s)
{
    return s->top == -1;
}
void push(Stack s, Item i)
{
    if (is_full(s))
        reallocate(s);
    s->top++;
    s->contents[s->top] = strdup(i);
}
Item pop(Stack s)
{
    if (is_empty(s))
        terminate("Error in pop: stack is empty");
    printf("%s\n", s->contents[s->top]);
    s->top--;
    return s->contents[s->top + 1];
}
Item peek(Stack s)
{
    if (is_empty(s))
        terminate("Error in peek: stack is empty.");
    return s->contents[s->top];
}
void reallocate(Stack s)
{
    Item *tmp = (Item *)malloc(2 * s->size * sizeof(Item));
    if (tmp == NULL)
    {
        terminate("Error in create: stack could not be created.");
    }
    for (int i = 0; i < s->size; i++)
    {
        tmp[i] = s->contents[i];
    }
    free(s->contents);
    s->contents = tmp;
    s->size *= 2;
}

int main()
{
    int stmt = 0;
    char *name[100];
    Stack add[100];
    while (1)
    {
        printf("$ ");
        int idx = 0;
        char buf[1000];
        char buf2[1000];
        char buf3[1000];
        scanf("%s", buf);
        if (strcmp(buf, "create") == 0)
        {
            scanf("%s", buf2);
            Stack s = create();
            name[stmt] = strdup(buf2);
            add[stmt] = s;
            stmt++;
        }
        else if (strcmp(buf, "push") == 0)
        {
            scanf("%s", buf2);
            scanf("%s", buf3);
            for (int i = 0; i < stmt; i++)
            {
                if (strcmp(buf2, name[i]) == 0)
                {
                    Stack s1 = add[i];
                    push(s1, buf3);
                }
            }
        }
        else if (strcmp(buf, "pop") == 0)
        {
            scanf("%s", buf2);
            for (int i = 0; i < stmt; i++)
            {
                if (strcmp(buf2, name[i]) == 0)
                {
                    Stack s2 = add[i];
                    pop(s2);
                }
            }
        }
        else if (strcmp(buf, "list") == 0)
        {
            scanf("%s", buf2);
            for (int i = 0; i < stmt; i++)
            {
                if (strcmp(buf2, name[i]) == 0)
                {
                    Stack s3 = add[i];
                    for (int i = s3->top; i > -1; i--)
                    {
                        printf("%s\n", s3->contents[i]);
                    }
                }
            }
        }
        else if (strcmp(buf, "exit") == 0)
        {
            break;
        }
    }
}