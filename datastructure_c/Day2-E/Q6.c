/*
        反转链表
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

//核心思路：
// 1. 定义三个指针，分别指向头结点，当前结点，下一个结点
// 2. 遍历链表，将当前结点的next指针指向前一个结点
// 3. 移动指针，指向下一个结点
// 4. 重复步骤2，直到遍历完整个链表
// 5. 返回头结点
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* frist=NULL;
    struct ListNode* second = head;
    struct ListNode* third;
    while(second){
        third=second->next;
        second->next=frist;
        frist=second;
        second=third;
    }
    return frist;
}


//测试代码
int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next = NULL;
    struct ListNode* newHead = reverseList(head);
    while(newHead) {
        printf("%d ", newHead->val);
        newHead = newHead->next;
    }
    return 0;