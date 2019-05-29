//
//  main.cpp
//  18-链表的插入排序
//
//  Created by 乔谦 on 2019/5/27.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

// 第一种
ListNode* insertionSortList1(ListNode* head) {
    
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode tmp(-1);
    ListNode *pre = &tmp;//插入位置的前一个节点
    ListNode *cur = head;;  //待排序的节点
    ListNode *rear; //待排序节点的下一个节点
    
    while(cur != NULL){
        
        rear = cur->next;
        while(pre->next != NULL && pre->next->val < cur->val){ // 将前驱指针一直移到要插入的位置
            pre = pre->next;
        }
        // 插入
        cur->next = pre->next;
        pre->next = cur;
        cur = rear;
        pre = &tmp;
    }
    return tmp.next;
}

// 第二种
ListNode* insertionSortList2(ListNode* head) {
    
    if(head==NULL||head->next==NULL) return head;
    
    // 创建一个前驱节点
    ListNode* newhead = new ListNode(INT_MIN);
    newhead->next = head;
    head = newhead;
    
    ListNode *rear = head->next;//有序链表最后一个节点
    ListNode *p = rear->next;//待排序插入节点
    while(p!=NULL){
        
        //将p节点移除
        rear->next = p->next;
        p->next = NULL;
        //确定位置
        ListNode *pre = head;//保存插入位置的前一个节点
        ListNode *temp = head->next;
        while(temp->val <= p->val && temp != rear){
            pre = temp;
            temp = temp->next;
        }
        if(temp->val > p->val){
            p->next = temp;
            pre->next = p;
        }else{
            p->next = temp->next;
            temp->next = p;
            rear = p;
        }
        p = rear->next;
    }
    return head->next;
}
int main(int argc, const char * argv[]) {
    
    ListNode a(4);
    ListNode b(2);
    ListNode c(1);
    ListNode d(3);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    ListNode *head = insertionSortList2(&a);
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
