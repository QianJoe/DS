//
//  main.cpp
//  13-判断回文链表
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

// 也是用快慢指针
bool isPalindrome(ListNode* head) {
    
    if (head == NULL || head->next == NULL) {
        return true;
    }
    
    ListNode *slow = head;
    ListNode *fast = head;
    
    // 用快慢指针，将慢指针移动到中间
    while (fast->next && fast->next->next) {
        
        slow = slow->next;
        fast = fast->next->next;
    }
    // 然后将后面翻转
    ListNode *last_head = slow->next;
    ListNode *new_last_head = NULL;
    while (last_head) {
        // 保存下一个节点
        ListNode *next = last_head->next;
        // 连接到新的上面
        last_head->next = new_last_head;
        new_last_head = last_head;
        // headz移到下一个
        last_head = next;
    }
    
    // 开始比较
    while (head && new_last_head) {
        
        if (head->val != new_last_head->val) {
            return false;
        }
        head = head->next;
        new_last_head = new_last_head->next;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    ListNode a(1);
    ListNode b(2);
    ListNode e(3);
    ListNode c(2);
    ListNode d(1);
    a.next = &b;
    b.next = &e;
    e.next = &c;
    c.next = &d;
    if (isPalindrome(&a)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}
