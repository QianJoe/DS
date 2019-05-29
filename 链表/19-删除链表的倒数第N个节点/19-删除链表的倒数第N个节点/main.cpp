//
//  main.cpp
//  19-删除链表的倒数第N个节点
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

// 思路：快慢指针
ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    if (head == NULL) {
        return head;
    }
    ListNode tmp(0);
    tmp.next = head;
    ListNode *fast = &tmp;
    ListNode *slow = &tmp;
    while (fast) {
        if(n > -1)
        {// 快指针先走n+1步
            n--;
            fast = fast->next;
        } else
        { // 然后同时走，fast到尾部，就是倒数第n个位置的前驱指针
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    // 删除
    ListNode *cur = slow->next;
    slow->next = cur->next;
    return tmp.next;
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
    
    ListNode *head = removeNthFromEnd(&a, 2);
    while (head) {
        printf("%d\n", head->val);
        head = head->next;

    }
    
    return 0;
}
