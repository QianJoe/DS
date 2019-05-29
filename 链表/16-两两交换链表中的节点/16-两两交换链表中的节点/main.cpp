//
//  main.cpp
//  16-两两交换链表中的节点
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

ListNode* swapPairs1(ListNode* head) {
    
    if(!head || !head->next) return head;
    ListNode tmp_head(-1); // 临时节点
    ListNode *pre = &tmp_head; // 前驱节点，用于链接两个交换过的节点
    ListNode *p = head;
    ListNode *q = head->next;
    
    while (p && q) {
        // 交换
        p->next = q->next;
        q->next = p;
        // 链接到前面
        pre->next = q;
        // 移动指针到下一个交换处
        pre = p;
        p = p->next;
        if (p) { // 主要是为了处理最后一个
            q = p->next;
        }
    }
    
    return tmp_head.next;
}

ListNode* swapPairs2(ListNode* head) {
    // Write your code here
    //如果链表长度为0或者为1直接返回就行，不需要操作 ,经过这步操作之后，链表的长度大于等于2
    if(!head || !head->next) return head;
    ListNode *p=new ListNode(0);//首地址
    p->next=head;
    head=p;
    ListNode *q=head->next;
    ListNode *k=q->next;
    while(k){
        //先进行交换
        q->next=k->next;
        k->next=q;
        p->next=k;
        //然后进行向前推进
        p=q;
        if(q->next==NULL){
            q=NULL;
            k=NULL;
        }else{
            q=q->next;
            k=q->next;
        }
    }
    head=head->next;
    return head;
}

int main(int argc, const char * argv[]) {
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    ListNode *head = swapPairs2(&a);
    
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
