/*
        移除链表元素
        给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


//核心思路
//创建一个哑结点，将原链表的头结点指向哑结点，然后遍历链表，如果当前结点的值等于val，则将当前结点的下一个结点指向当前结点的下下个结点，并释放当前结点的内存，否则将当前结点指向下一个结点。最后返回哑结点的下一个结点，即链表的头结点。

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val=0;
    dummy->next=head;
    struct ListNode* p = dummy;
    while(p&&p->next){
        if(p->next->val==val){
            struct ListNode* temp = p->next;
            p->next=temp->next;
            free(temp);
        }else{
            p=p->next;
        }
    }
    return dummy->next;
}


//测试代码
int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 6;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 4;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 5;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 6;
    head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 7;
    head->next = NULL;
    struct ListNode* newHead = removeElements(head, 6);
    while (newHead) {
        printf("%d ", newHead->val);
        newHead = newHead->next;
    }
    return 0;
}