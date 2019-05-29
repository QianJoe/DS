//
//  main.cpp
//  15-排序链表(归并排序)
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

ListNode* mergeSort(ListNode* l1, ListNode *l2) {
    
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

ListNode* sortList(ListNode* head) {
    
    if (head == NULL || head->next == NULL) return head;
    ListNode *slow = head, *fast = head, *pre = head;
    while (fast != NULL && fast->next != NULL) {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;
    return mergeSort(sortList(head), sortList(slow));
}

int main(int argc, const char * argv[]) {
    
    ListNode a(4);
    ListNode b(2);
    ListNode c(1);
    ListNode d(3);
    
    a.next = &b;
    b.next = &c;
    c.next = &d;
    ListNode *head = sortList(&a);
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
