/*
        二进制链表转整数
        给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。
        已知此链表是一个整数数字的二进制表示形式。
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct ListNode {
    int val;
    struct ListNode *next;
};





//核心思路
//1. 遍历链表，计算链表长度len
//2. 遍历链表，从右到左，依次取出每个结点的值，乘以2的(len-1-i)次方，并累加到结果变量result中
//3. 返回结果变量result
int getDecimalValue(struct ListNode* head) {
    int len=0;
    struct ListNode* p = head;
    while(p){
        len++;
        p=p->next;
    }

    p=head;
    int result=0;

    for(int i=0;i<len;i++){
        result+=p->val*(int)pow(2,len-1-i);
        p=p->next;
    }
    return result;
}






//测试代码
int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 0;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 1;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 0;
    head->next = NULL;

    int decimalValue = getDecimalValue(head);
    printf("%d\n", decimalValue);

    return 0;
}