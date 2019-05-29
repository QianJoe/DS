//
//  main.cpp
//  11-找链表的中间点
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

ListNode* middleNode(ListNode* head) {
 
    ListNode *slow_node = head;
    ListNode *fast_node = head;
    
    while (fast_node && fast_node->next) {
        
        fast_node = fast_node->next->next;
        slow_node = slow_node->next;
    }
    
    return slow_node;
}

int main(int argc, const char * argv[]) {
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    
    a.next = &b;
    b.next = &c;
    ListNode *mid_node = middleNode(&a);
    printf("%d\n", mid_node->val);
    
    return 0;
}
