//
//  main.cpp
//  09-链表删除节点
//
//  Created by 乔谦 on 2019/5/25.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

void deleteNode(ListNode *node)
{
    // 由于不知道前一个节点，可以直接将后一个节点与当前节点值交换，然后当前节点可以变成前一个节点，删除n后一个节点就ok
    ListNode *nextNode = node->next;
    node->val = nextNode->val;
    node->next = nextNode->next;
    nextNode->next = NULL;
}

//void deleteNode(ListNode* head, ListNode *node) {
//
//    ListNode *pre_node = head;
//    ListNode *delete_node = head;
//    while (head) {
//        if (head == node) {
//
//            pre_node->next = head->next;
//            delete_node = head;
//            head = head->next;
//        }
//        // pre_head指向当前head，head往后移，正好pre_head是前一个
//        pre_node = head;
//        head = head->next;
//    }
//
//}

int main(int argc, const char * argv[]) {
    
//    ListNode a(0);
//    ListNode b(1);
//    ListNode c(2);
//    ListNode d(3);
//    ListNode e(4);
//    a.next = &b;
//    b.next = &c;
//    c.next = &d;
//    d.next = &e;
//    ListNode *head = &a;
//
//    deleteNode(&a, &a);
//
//    while (head) {
//        printf("%d\n", head->val);
//        head = head->next;
//    }
    return 0;
}
