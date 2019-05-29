//
//  main.cpp
//  12-去除有序链表重复的元素
//
//  Created by 乔谦 on 2019/5/26.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* deleteDuplicates(ListNode* head) {
    
    ListNode *node = head;
    while (node && node->next) {
        
        if (node->val == node->next->val) {
            ListNode *next = node->next;
            node->next = next->next;
            continue;
        }
        
        node = node->next;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    
    ListNode a(1);
    ListNode b(1);
    ListNode c(2);
    ListNode d(3);
    ListNode e(3);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    ListNode *head = deleteDuplicates(&a);
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
