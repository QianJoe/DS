//
//  main.cpp
//  24-链表中的下一个更大节点
//
//  Created by 乔谦 on 2019/5/28.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

vector<int> nextLargerNodes2(ListNode* head) {
    
    vector<int> res;
    ListNode* p = head;
    while(p) // 先将node存到一个vector中
    {
        res.push_back(p->val);
        p = p->next;
    }
    
    int n = (int)res.size();
    
    stack<int> tmp;
    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--) // 从最后开始，因为最后一个肯定是0，正好每次都能存到栈了
    {
        while(!tmp.empty() && tmp.top() <= res[i]) // 如果当前节点比栈顶节点大，栈顶节点就出栈，直到栈空
        {
            tmp.pop();
        }
        
        if(!tmp.empty()) // 如果栈不为空
        {
            ans[i] = tmp.top(); // 说明碰到了大于当前元素的，就存起来
        }
        else // 否则说明没有找到，存0
        {
            ans[i] = 0;
        }
        
        tmp.push(res[i]); // 将当前节点值入栈
    }
    return ans;
}

// 这个超时
vector<int> nextLargerNodes(ListNode* head) {
    
    vector<int> largerNodes_vec; // 存放下一个最大的节点
    if (head == NULL || head->next == NULL) {
        largerNodes_vec.push_back(0);
        return largerNodes_vec;
    }
    
    ListNode *cur = head;
    ListNode *next = cur->next;
    while (cur) {
        
        if (cur->next == NULL) { // 处理最后一个
            largerNodes_vec.push_back(0); // 存到vector中
            break;
        }
        if (cur->val < next->val) { // 如果后一个比前面的大
            largerNodes_vec.push_back(next->val); // 存到vector中
            cur = cur->next; // 移到下一个节点
            next = cur->next; // 保证每次next开始都是cur的下一个
        } else
        {
            // 移到下一个节点
            next = next->next;
        }
        
        if (next == NULL && cur->next != NULL) { // next为NULL时，说明没有比cur大的
            largerNodes_vec.push_back(0); // 存到vector中
            cur = cur->next; // 移到下一个节点
            next = cur->next; // 保证每次next开始都是cur的下一个
        }
    }
    return largerNodes_vec;
}

int main(int argc, const char * argv[]) {
    
    ListNode a(2);
    ListNode b(7);
    ListNode c(4);
    ListNode d(3);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    
    vector<int> vec = nextLargerNodes(&a);
    
    for (int i = 0; i < vec.size(); i++) {
        printf("%d\n", vec[i]);
    }
    return 0;
}
