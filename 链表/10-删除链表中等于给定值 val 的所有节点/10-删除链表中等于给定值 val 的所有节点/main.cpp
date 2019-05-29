//
//  main.cpp
//  10-删除链表中等于给定值 val 的所有节点
//
//  Created by 乔谦 on 2019/5/25.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 第二种思路
ListNode* removeElements(ListNode* head, int val) {
    
    if (head == NULL) { // 空链表就直接返回
        return NULL;
    }
    while (head != NULL && head->val == val) { // 头结点为要删除的，就删除
        head = head->next;
    }
    if (head == NULL) { // 如果此时为空，说明全部为val
        return NULL;
    }
    
    ListNode *node = head;
    while (node->next) {
        
        if (node->next->val == val) {
            node->next = node->next->next;
        } else
        {
            node = node->next;
        }
    }
    return head;
}

int main(int argc, const char * argv[]) {
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(6);
    ListNode d(3);
    ListNode e(4);
    ListNode f(5);
    ListNode g(6);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    
    ListNode *head = removeElements(&a, 6);
    
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
