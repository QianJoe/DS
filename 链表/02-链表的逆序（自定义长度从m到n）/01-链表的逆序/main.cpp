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
    ListNode(int x): val(x), next(NULL){}
};

// 关键：四个节点：m节点，m的前驱节点，n节点，n的后继节点
// 找m节点和m的前驱节点比较容易，只要移动head m-1个格就可以了，并且同时可以找到m的前驱
// 一共要逆置n-m+1个k节点
ListNode *reverseBetween(ListNode *head, int m, int n)
{
    int change_len = n - m + 1; // 逆置节点的个数
    ListNode *pre_head = NULL; // 初始化开始逆置节点的前驱
    ListNode *result = head; // 最终转换后的头节点
    
    // 找到m节点，将head往前移动m-1格
    while (head && --m) {
        pre_head = head;
        head = head->next;
    }
    
    // 当前的head为逆序后那段的尾
    ListNode *modify_list_tail = head;
    ListNode *new_head = NULL;
    
    while (head && change_len) {
        
        ListNode *next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
        change_len--;
    }
    
    // 链接到后面的节点;
    modify_list_tail->next = head;
    
    if (pre_head) { // pre_head不为空，说明不是从第一个开始逆置的，m>1
        
        pre_head->next = new_head;
    } else
    {
        result = new_head;
    }
    return result;
    
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
    head = reverseBetween(&a, 2, 4);
    cout<<"after reverse:\n";
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
