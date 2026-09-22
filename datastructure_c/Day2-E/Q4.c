/*
        相交链表

        给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null。
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

//核心思路：
// 1. 先求出两个链表的长度，如果长度不一样，则说明两个链表没有相交节点，直接返回 NULL。
// 2. 然后让两个链表同时往后移动，直到两个链表的末尾节点相等。
// 3. 然后再从头开始遍历两个链表，直到找到相交节点。
// 4. 返回相交节点。
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* p1= headA;
        struct ListNode* p2= headB;
        int lenA = 0;
        int lenB = 0;
        while(p1!=NULL){p1=p1->next;lenA++;}
        while(p2!=NULL){p2=p2->next;lenB++;}
        int lenC=lenA-lenB;
        p1=headA;
        p2=headB;
        if(lenC>0){
            while(lenC!=0){
                p1=p1->next;
                lenC--;
            }
        }else{
            while(lenC!=0){
                p2=p2->next;
                lenC++;
            }
        }
        while(p1&&p2){
            if(p1==p2){
                return p1;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return NULL;
}



//测试代码
int main() {
    struct ListNode* headA = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* headB = (struct ListNode*)malloc(sizeof(struct ListNode));
    headA->val = 1;
    headA->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    headA->next->val = 2;
    headA->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    headA->next->next->val = 3;
    headA->next = (struct ListNode*)malloc(sizeof(struct ListNode));                                                                                
    headA->next->val = 4;
    headA->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    headA->next->next->val = 5;
    headA->next = NULL;
    headB->val = 6;
    headB->next = (struct ListNode*)malloc(sizeof(struct ListNode));                                                                                
    headB->next->val = 7;
    headB->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    headB->next->next->val = 8;
    headB->next = (struct ListNode*)malloc(sizeof(struct ListNode));                                                                                
    headB->next->val = 9;
    headB->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    headB->next->next->val = 10;
    headB->next = NULL;
    struct ListNode* res = getIntersectionNode(headA, headB);
    if(res==NULL){
        printf("No intersection node.\n");
    }else{
        printf("Intersection node value is %d.\n", res->val);
        }
    return 0;
}   