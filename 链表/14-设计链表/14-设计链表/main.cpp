//
//  main.cpp
//  14-设计链表
//
//  Created by 乔谦 on 2019/5/26.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *head;
/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int get(int index) {
    int i = 0;
    while (head) {
        if (i == index) {
            return head->val;
        }
        i++;
        head = head->next;
    }
    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void addAtHead(int val) {
    
    ListNode a(val);
    a.next = head;
    head = &a;
}

/** Append a node of value val to the last element of the linked list. */
void addAtTail(int val) {
    ListNode a(val);
    while (head->next) {
        head = head->next;
    }
    head->next = &a;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void addAtIndex(int index, int val) {
    ListNode a(val);
    int i = 0;
    while (head) {
        if (i == index-1) {
            a.next = head->next;
            head->next = &a;
            return;
        }
        i++;
        head = head->next;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void deleteAtIndex(int index) {
    int i = 0;
    while (head) {
        if (i == index-1) {
            
            ListNode *delete_node = head->next;
            head->next = delete_node->next;
            return;
        }
        i++;
        head = head->next;
    }
}

int main(int argc, const char * argv[]) {
    
    head = NULL;
 
    return 0;
}
