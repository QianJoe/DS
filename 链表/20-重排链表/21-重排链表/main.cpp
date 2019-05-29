//
//  main.cpp
//  21-重排链表
//
//  Created by 乔谦 on 2019/5/27.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>

//给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
//将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *new_head = NULL;
    while (head) {
        ListNode *next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }
    return new_head;
}

void reorderList(ListNode* head) {
    
    if (head == NULL || head->next == NULL) {
        return ;
    }
    
    // 用快慢指针找到中间
    ListNode *fast = head;
    ListNode *slow = head;
    
    while (fast->next && fast->next->next) {
        
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *right_head = slow->next;
    slow->next = NULL;
    ListNode *left_head = head;
    right_head = reverseList(right_head);
    
    // 归并
    ListNode tmp(-1);
    ListNode *pre = &tmp;
    int i = 0;
    while (left_head && right_head) {
        if (i % 2 == 0) {
            pre->next = left_head;
            left_head = left_head->next;
            pre = pre->next;
        } else {
            pre->next = right_head;
            right_head = right_head->next;
            pre = pre->next;
        }
        i++;
    }
    if (left_head) {
        pre->next = left_head;
    }
    if (right_head) {
        pre->next = right_head;
    }
    head = tmp.next;
}

int main(int argc, const char * argv[]) {
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    
    reorderList(&a);
    ListNode *head = &a;
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
