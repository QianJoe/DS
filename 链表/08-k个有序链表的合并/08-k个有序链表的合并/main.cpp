//
//  main.cpp
//  08-k个有序链表的合并
//
//  Created by 乔谦 on 2019/5/23.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};


ListNode *mergeTwoList(ListNode *l1, ListNode *l2)
{
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

// stl的排序法方法
bool cmp(const ListNode *a, const ListNode *b)
{
    return a->val < b->val;
}

ListNode *mergeKLists1(vector<ListNode *> &lists)
{
    vector<ListNode *> node_vec;
    for (int i = 0; i < lists.size(); i++) {
        
        ListNode *head = lists[i];
        while (head) {
            
            node_vec.push_back(head);
            head = head->next;
        }
    }
    
    sort(node_vec.begin(), node_vec.end(), cmp);
    
    for (int i = 1; i < node_vec.size(); i++) {
        
        node_vec[i-1]->next = node_vec[i];
    }
    
    node_vec[node_vec.size()-1]->next = NULL;
    return node_vec[0];
}

// 分治法
ListNode *mergeKLists2(vector<ListNode *> &lists)
{
    if (lists.size() == 0) { // 0个
        return NULL;
    }
    if (lists.size() == 1) { // 1个
        return lists[0];
    }
    if (lists.size() == 2) { // 2个
        return mergeTwoList(lists[0], lists[1]);
    }
    
    int mid = (int)(lists.size() / 2);
    
    vector<ListNode *> sub1_lists; // 拆分为两个lists
    vector<ListNode *> sub2_lists;
    
    for (int i = 0; i < mid; i++) { // 前一半的链表存放到这个vector
        sub1_lists.push_back(lists[i]);
    }
    
    for (int i = mid; i < lists.size(); i++) {
        sub2_lists.push_back(lists[i]);
    }
    ListNode *l1 = mergeKLists2(sub1_lists);
    ListNode *l2 = mergeKLists2(sub2_lists);
    
    return mergeTwoList(l1, l2); // 分治
}

int main(int argc, const char * argv[]) {
    
    ListNode a(1);
    ListNode b(4);
    ListNode c(6);
    ListNode d(0);
    ListNode e(5);
    ListNode f(7);
    ListNode g(2);
    ListNode h(3);
    
    a.next = &b;
    b.next = &c;
    d.next = &e;
    e.next = &f;
    g.next = &h;
    
    vector<ListNode *> lists;
    lists.push_back(&a);
    lists.push_back(&d);
    lists.push_back(&g);
    
    ListNode *head = mergeKLists2(lists);
    
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
    
    return 0;
}
