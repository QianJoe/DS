//
//  main.cpp
//  23- 删除排序链表中的重复元素(包括自身)
//
//  Created by 乔谦 on 2019/5/28.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* deleteDuplicates(ListNode* head) {
    
    ListNode *pre = new ListNode(0);
    pre->next = head; // 前驱节点，方便删除节点
    ListNode *new_head = pre; // 新的头结点
    ListNode *cur = head; // 表示当前节点
    int flag = 0; // 0为当前不为重复的元素，1是
    while (cur) {
        if (cur->next && cur->val == cur->next->val) { // cur->next 是为了最后一个节点如果是重复节点
            flag = 1; // 这类值全为重复元素
            // 先删除下一个节点
            ListNode *next = cur->next;
            cur->next = next->next;
        } else
        { // 此时下一个节点与当前节点不一样
            if (flag) { // flag为1时，表示当前节点还是重复元素，只不过之前重复的都删除了
                // 删除当前节点
                
                pre->next = cur->next;
                cur = cur->next;
                
            } else
            { // 不是重复节点
                pre = pre->next;
                cur = cur->next;
            }
            flag = 0;
        }
    }
    
    return new_head->next;
}

int main(int argc, const char * argv[]) {
    
    ListNode a(1);
    ListNode b(2);
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
