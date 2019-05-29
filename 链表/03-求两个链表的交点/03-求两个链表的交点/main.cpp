//
//  main.cpp
//  03-求两个链表的交点
//
//  Created by 乔谦 on 2019/5/22.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

// 方法一：时间复杂度O(nlogn)
ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB)
{
    set<ListNode *> node_set; // 设置查找集合
    // 遍历链表A，将其节点插入到集合中
    while (headA) {
        node_set.insert(headA);
        headA = headA->next;
    }
    
    while (headB) {
        if (node_set.find(headB) != node_set.end()) { // 第一次出现，直接返回
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}

// 方法二：时间复杂度O(n)
// 步骤：1.计算两个链表的长度，2.将长的链表移到对齐，3.同时移到两个，直到找到相同的节点
// 1.计算两个链表的长度
int get_list_length(ListNode *head)
{
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return  len;
}
// 2.将长的链表移到多出地方的节点
ListNode *forward_long_list(int long_len, int short_len, ListNode *head)
{
    int delta = long_len - short_len;
    while (head && delta) {
        head = head->next;
        delta--;
    }
    return head;
}
// 3.同时移到两个，直到找到相同的节点
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB)
{
    int list_A_len = get_list_length(headA);
    int list_B_len = get_list_length(headB);
    
    if (list_A_len > list_B_len) {
        headA = forward_long_list(list_A_len, list_B_len, headA);
    } else
    {
        headB = forward_long_list(list_B_len, list_A_len, headB);
    }
    
    while (headA && headB) {
        
        if (headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    
    return NULL;
}

int main(int argc, const char * argv[]) {
    
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(3);
    ListNode b2(4);
    ListNode b3(5);
    ListNode c1(6);
    ListNode c2(7);
    ListNode c3(8);
    a1.next = &a2;
    a2.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    
    ListNode *result = getIntersectionNode2(&a1, &b1);
    printf("%d\n", result->val);
    return 0;
}

void test()
{
    set<int> test_set;
    const int A_LEN = 7;
    const int B_LEN = 8;
    
    int a[A_LEN] = {5, 1, 4, 8, 10, 1, 3};
    int b[B_LEN] = {2, 7, 6, 3, 1, 6, 0, 1};
    
    for (int i = 0; i < A_LEN; i++) {
        test_set.insert(a[i]);
    }
    
    for (int i = 0; i < B_LEN; i++) {
        // 元素检索：find()，若找到，返回该键值迭代器的位置，否则，返回最后一个元素后面一个位置。
        if (test_set.find(b[i]) != test_set.end()) {
            
            printf("b[%d] = %d in array A.\n", i, b[i]);
        }
    }
}
