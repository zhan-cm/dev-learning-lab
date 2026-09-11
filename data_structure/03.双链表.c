#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// 初始化链表
Node *initList()
{
    Node *list = (Node *)malloc(sizeof(Node));
    list->data = 0;
    list->next = NULL;
    list->prev = NULL;
    return list;
}
// 头插法
void headInsert(Node *list, int data)
{
    Node *head = list;
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    if (head->data == 0)
    {
        node->next=head->next;
        node->prev=head;
        head->next=node;
    }
    else
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    list->data++;
}
// 尾插法
void tailInsert(Node *list, int data)
{
    Node *head = list;
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    while (head->next)
    {
        head = head->next;
    }
    node->next = head->next;
    node->prev = head;
    head->next = node;
    list->data++;
}
// 删除节点
int delete(Node *list, int data)
{
    Node *node = list->next;
    while (node)
    {
        if (node->data == data)
        {
            node->prev->next = node->next;
            if (node->next)
            {
                node->next->prev = node->prev;
            }
            free(node);
            list->data--;
            return TRUE;
        }
        node = node->next;
    }
    return FALSE;
}
// 遍历链表
void printList(Node *list)
{
    Node *p = list->next;
    while (p)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
int main(void)
{
    Node *list = initList();
    headInsert(list, 1);
    headInsert(list, 2);
    headInsert(list, 3);
    headInsert(list, 4);
    headInsert(list, 5);
    tailInsert(list, 6);
    tailInsert(list, 7);
    tailInsert(list, 8);
    tailInsert(list, 9);
    tailInsert(list, 10);
    printList(list);
    delete(list, 5);
    delete(list, 10);
    delete(list, 6);
    printList(list);
    free(list);

    return 0;
}