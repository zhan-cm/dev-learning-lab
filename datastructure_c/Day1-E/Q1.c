/*
        合并两个有序链表
*/

#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int val;
    struct ListNode* next;
};

//核心思路：
//1.创建两个指针p和q，p指向合并后的链表的头部，q指向一个空节点。
//2.比较两个链表的头部节点的值，将较小的节点添加到合并链表中，并将指针指向该节点。
//3.重复步骤2，直到两个链表中至少有一个节点为空。
//4.将剩余的节点添加到合并链表中。
//5.返回合并链表的头节点。
//6.释放q节点。
//7.返回合并链表的头节点。
//时间复杂度：O(n+m)，n和m分别为两个链表的长度。
//空间复杂度：O(1)，只需要常数的额外空间。
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* q =(struct ListNode*)malloc(sizeof(struct ListNode));
    q->val=0;
    q->next=NULL;
    struct ListNode* p = q;
    while(list1&&list2){
        if(list1->val<=list2->val){
            p->next=list1;
            list1=list1->next;
        }else{
            p->next=list2;
            list2=list2->next;
        }
        p=p->next;
    }
    if(list1){
            p->next=list1;
        }else{
            p->next=list2;
        }
        struct ListNode* result = q->next;
        free(q);
        return result;
}


//测试代码
int main(){
    struct ListNode* list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->val=1;
    list1->next=NULL;
    struct ListNode* list2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list2->val=2;
    list2->next=NULL;
    struct ListNode* list3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list3->val=3;
    list3->next=NULL;
    struct ListNode* list4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list4->val=4;
    list4->next=NULL;
    struct ListNode* list5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list5->val=5;
    list5->next=NULL;
    struct ListNode* list6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list6->val=6;
    list6->next=NULL;
    list1->next=list2;
    list2->next=list3;
    list3->next=list4;
    list4->next=list5;
    list5->next=list6;
    struct ListNode* result = mergeTwoLists(list1,list5);
    while(result){
        printf("%d ",result->val);
        result=result->next;
    }
    return 0;
}



