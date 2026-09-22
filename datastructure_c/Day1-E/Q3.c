/*
            环形链表：

            给你一个链表的头节点 head ，判断链表中是否有环。
            如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
            为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
            如果链表中存在环 ，则返回 true 。 否则，返回 false 。
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct ListNode{
    int val;
    struct ListNode* next;
};

//核心思路：
// 1. 快慢指针法，快指针每次跨两步，慢指针每次跨一步，如果存在环，则快指针会追上慢指针，否则不存在环。
// 2. 快慢指针法的优化，如果链表长度为n，则快指针每次跨两步，慢指针每次跨一步，则快指针会在第n/2步追上慢指针，如果存在环，则快指针会在第n/2步追上慢指针，否则不存在环。
// 3. 哈希表法，遍历链表，将每个节点的值作为key，将节点的地址作为value，如果存在重复的key，则说明存在环。
// 4. 双指针法，快慢指针法的优化，如果链表长度为n，则快指针每次跨两步，慢指针每次跨一步，则快指针会在第n/2步追上慢指针，如果存在环，则快指针会在第n/2步追上慢指针，否则不存在环。
// 5. 快慢指针法的变形，如果链表长度为n，则快指针每次跨两步，慢指针每次跨一步，则快指针会在第n/2步追上慢指针，如果存在环，则快指针会在第n/2步追上慢指针，否则不存在环。
bool hasCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}






//测试代码
int main(){
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->val = 2;
    head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->val = 3;
    head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next->next->next->val = 4;
    head->next = head->next;
    if(hasCycle(head)){
        printf("Cycle exists\n");
    }else{
        printf("Cycle does not exist\n");
    }
    return 0;