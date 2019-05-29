//
//  main.cpp
//  01-链表的逆序
//
//  Created by 乔谦 on 2019/5/21.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){} // 构造函数
};

// 第一种方法：迭代法
ListNode *reverseList(ListNode *head)
{
    ListNode *new_head = NULL;
    while (head) {
        
        // 先保存下一个节点
        ListNode *next = head->next;
        // head链接到new_head
        head->next = new_head;
        // new_head指向head
        new_head = head;
        // head移动到下一个
        head = next;
    }
    return new_head;
}

// 第二种方法：递归法
// 思路：就是先走到链表尾部，然后逆向连接
ListNode *reverseList2(ListNode *head)
{
    if (head == NULL || head->next == NULL) { // 如果为空，或者下一个也为空就直接返回（为了判断是否到尾部了）
        return head;
    }
    
    ListNode *new_head = reverseList2(head->next); // 一直d移动到尾部
    // 将当前节点连接到下一个节点的next上
    head->next->next = head;
    // 断开以前的,防止链表错乱
    head->next = NULL;
    return new_head;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    
    ListNode *head = &a;
    
    cout<<"before reverse:\n";
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    
    // 逆序
    head = reverseList2(&a);
    cout<<"after reverse:\n";
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
