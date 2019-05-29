//
//  main.cpp
//  04-链表求环
//
//  Created by 乔谦 on 2019/5/22.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

// 第一种方法
ListNode *detectCycle1(ListNode *head)
{
    set<ListNode *> node_set;
    
    while (head) { // 遍历链表
        if (node_set.find(head) != node_set.end()) { // 如果能找到，就返回环的第一个节点
            return head;
        }
        // 往集合中插入节点
        node_set.insert(head);
        head = head->next;
    }
    return NULL;
}

// 第二种方法，快慢指针赛跑：跑步，有环的话，会相遇。快的组两步，慢的走一步
ListNode *detectCycle2(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *meet = NULL;
    
    while (fast) {
        
        // 先各走一步
        fast = fast->next;
        slow = slow->next;
        if (!fast) { // 为空，说明只有一块
            return NULL;
        }
        fast = fast->next;
        
        if (fast == slow) { // 相遇
            meet = fast;
            break; // 跳出循环
        }
    }
    
    // 如果meet为空，说明没有环
    if (meet == NULL) {
        return meet;
    }
    
    while (head && meet) {
        
        if (meet == head) {
            return head;
        }
        meet = meet->next;
        head = head->next;
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    ListNode g(7);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &c;
    ListNode *node = detectCycle2(&a);
    if (node) {
        printf("%d\n", node->val);

    } else
    {
        printf("NULL\n");
    }
    return 0;
}
