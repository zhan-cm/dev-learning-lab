/*
        删除排序链表中的重复元素
*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int val;
    struct ListNode* next;
};

//核心思路：
//1. 遍历链表，将当前节点的值与下一个节点的值进行比较，如果相同，则删除下一个节点
//2. 重复步骤1，直到链表末尾
//3. 返回头节点
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head||!head->next)return head;
    struct ListNode* p = head ;
    while(p->next){
        if(p->val==p->next->val){
            struct ListNode* q = p->next;
            p->next=q->next;
            free(q);
        }else{
            p=p->next;
        }
        
    }
    return head;
}

//测试代码
int main(){
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));    
    head->next->next->val = 3;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 4;
    head->next->next = NULL;
    head = deleteDuplicates(head);
    while(head){
        printf("%d ",head->val);
        head = head->next;
    }
    return 0;
}
