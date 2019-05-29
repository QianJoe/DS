//
//  main.cpp
//  27-旋转链表
//
//  Created by 乔谦 on 2019/5/28.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>

//给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
//输入: 0->1->2->NULL, k = 4
//输出: 2->0->1->NULL
//解释:
//向右旋转 1 步: 2->0->1->NULL
//向右旋转 2 步: 1->2->0->NULL
//向右旋转 3 步: 0->1->2->NULL
//向右旋转 4 步: 2->0->1->NULL

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 思路一
ListNode* rotateRight1(ListNode* head, int k) {
    
    if (!head) return NULL;
    
    int n = 0;
    ListNode *cur = head;
    while (cur) { // 得到链表长度
        ++n;
        cur = cur->next;
    }
    k %= n; // 计算出是倒数第几个
    // 快慢指针走
    ListNode *fast = head, *slow = head;
    for (int i = 0; i < k; ++i) {
        if (fast) fast = fast->next;
    }
    // 快指针到最后了，
    if (!fast) return head;
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    // 连接
    fast->next = head;
    fast = slow->next;
    slow->next = NULL;
    return fast;
}

// 时间短一点思路二：与找倒数k个节点差不多，如果k大于链表的长度，用长度-k
ListNode* rotateRight2(ListNode* head, int k) {
    
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode tmp(0);
    ListNode *p = &tmp;
    tmp.next = head;
    ListNode *fast = &tmp;
    ListNode *slow = &tmp;
    int i = 0;
    while (fast) {
        
        if (k == i) {
            // 找到了第k-1个位置
            break;
        }
        i++;
        fast = fast->next;
        
        if (fast == NULL && k >= i) { // 如果下一个为空，且还未走到k步，
            k = k % (i - 1); // 对i取余，为真正的倒数k
            if (k == 0) { // k等于0就是k是i-1的倍速
                k = i - 1;
            }
            fast = &tmp;
            i = 0; // i重置为0
//            continue;
        }
    }
    
    // 同时走
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    // 此时slow指向的就是倒数第K+1个，就是k的前驱
    if (slow == p && fast->next == NULL) {
        return p->next;
    } else
    {
        fast->next = p->next;
        p->next = slow->next;
        slow->next = NULL;
    }
    
    return p->next;
}

// 思路三：走一边链表，然后将尾首相连，再往后走n - k % n个节点就到达新链表的头结点前一个点，这时断开链表即可
ListNode *rotateRight(ListNode *head, int k) {
    if (!head) return NULL;
    int n = 1;
    ListNode *cur = head;
    while (cur->next) {
        ++n;
        cur = cur->next;
    }
    cur->next = head;
    int m = n - k % n; // 还要走几步
    for (int i = 0; i < m; ++i) {
        cur = cur->next;
    }
    ListNode *newhead = cur->next;
    cur->next = NULL;
    return newhead;
}


int main(int argc, const char * argv[]) {
    
    ListNode a(0);
    ListNode b(1);
    ListNode c(2);
    a.next = &b;
    b.next = &c;
    
    ListNode *head = rotateRight1(&a, 9);
    
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    return 0;
}
