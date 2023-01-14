// 테스트 데이터 모두 통과
/*
harry.txt 파일을 읽어서 단어들을 하나의 연결리스트로 저장하여 사전식 순으로 정리하고
등장빈도가 10 이하인 단어들은 연결리스트에서 제거하고 마지막 줄에 남아있는 단어의 개수를 출력
또한 등장빈도를 내림차순으로 정렬하라
*/
#define _CRT_SECURE_NO_WARINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char* data;
    int cnt;
    struct node* next;
} Node;
Node* head = NULL;
Node* head2 = NULL;

void addFirst(char* word)
{
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->cnt = 1;
    tmp->data = strdup(word);
    tmp->next = head->next;
    head->next = tmp;
}
int addAfter(Node* prev, char* word)
{
    if (prev == NULL)
    {
        return 0;
    }
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->cnt = 1;
    tmp->data = strdup(word);
    tmp->next = prev->next;
    prev->next = tmp;
    return 1;
}
void add_to_ordered_list(char* word)
{
    Node* p = head->next;
    Node* q = NULL;
    while (p != NULL && strcmp(p->data, word) <= 0)
    {
        q = p;
        p = p->next;
    }
    if (q == NULL)
    {
        addFirst(word);
    }
    else
    {
        addAfter(q, word);
    }
}
int dup(char* word)
{
    Node* curr = head->next;
    while (curr != NULL)
    {
        if (strcmp(curr->data, word) == 0)
        {
            curr->cnt++;
            return 0;
        }
        curr = curr->next;
    }
    return 1;
}
int total = 0;

int main()
{
    FILE* fp = fopen("harry.txt", "r");
    if (fp == NULL)
    {
        return 0;
    }
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    head2 = (Node*)malloc(sizeof(Node));
    head2->next = NULL;
    char word[100];
    int flag = 0;
    while (!feof(fp)) {

        fscanf(fp, "%s", word);
        flag = dup(word);
        if (flag == 0)
            continue;
        else
        {
            add_to_ordered_list(word);
        }
        total++;
    }
    fclose(fp);
    /*Node* curr = head->next;
    while (curr != NULL)
    {
        printf("%s: %d\n", curr->data, curr->cnt);
        curr = curr->next;
    }
    printf("%d", total);*/
    Node* k = head->next;
    while (k != NULL) {
        Node* tmp = k->next;
        if (tmp == NULL) {
            break;
        }
        else if (tmp->cnt <= 10) {
            total = total--;
            k->next = tmp->next;
        }
        else {
            k = k->next;
        }
    }
    /*Node* k2 = head->next;
    while (k2 != NULL)
     {
         printf("%s: %d\n", k2->data, k2->cnt);
         k2 = k2->next;
     }
    printf("%d", total);*/
    int max = 0;
    Node* x = head->next;
    while (x != NULL) {
        if (x->cnt > max) {
            max = x->cnt;
        }
        x = x->next;
    }
    Node* x1 = head2;
    while (max != 10) {
        Node* x2 = head->next;
        while (x2 != NULL) {
            Node* tmp = x2->next;
            if (tmp == NULL) {
                break;
            }
            else if (tmp->cnt == max) {
                x1->next = tmp;
                x1 = x1->next;
                x2->next = tmp->next;
            }
            else {
                x2 = x2->next;
            }
        }
        max--;
    }
    Node* k3 = head2->next;
    while (k3 != NULL)
    {
        printf("%s: %d\n", k3->data, k3->cnt);
        k3 = k3->next;
    }
    printf("%d", total);

    return 0;
}