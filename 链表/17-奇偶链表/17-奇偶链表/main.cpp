//
//  main.cpp
//  17-奇偶链表
//
//  Created by 乔谦 on 2019/5/27.
//  Copyright © 2019 乔谦. All rights reserved.
//

/*
 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
 */

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* oddEvenList(ListNode* head) {
    
    if (!head || !head->next || !head->next->next) {
        return head;
    }
    
    ListNode *odd = head;
    ListNode *even = odd->next;
    ListNode *t = even; // 将偶数位的节点拿下来
    while (even && even->next) {
        
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = t;
    return head;
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
    
    ListNode *head = oddEvenList(&a);
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
