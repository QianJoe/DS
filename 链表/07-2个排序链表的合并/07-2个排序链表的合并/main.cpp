//
//  main.cpp
//  07-2个排序链表的合并
//
//  Created by 乔谦 on 2019/5/23.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode *mergeTwoList(ListNode *l1, ListNode *l2)
{
    ListNode tempNode(0); // 设置临时头结点
    ListNode *pre = &tempNode;
    
    while (l1 && l2) {
        
        if (l1->val < l2->val) {
            
            pre->next = l1;
            l1 = l1->next;
        } else
        {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    
    if (l1) {
        pre->next = l1;
    }
    
    if (l2) {
        pre->next = l2;
    }
    
    return tempNode.next;
}

int main(int argc, const char * argv[]) {
    
    ListNode a(1);
    ListNode b(4);
    ListNode c(6);
    ListNode d(0);
    ListNode e(5);
    ListNode f(7);
    a.next = &b;
    b.next = &c;
    
    d.next = &e;
    e.next = &f;
    
    ListNode *node = mergeTwoList(&a, &d);
    while (node) {
        printf("%d\n", node->val);
        node = node->next;
    }
    return 0;
}
