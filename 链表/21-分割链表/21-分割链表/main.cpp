//
//  main.cpp
//  21-分割链表
//
//  Created by 乔谦 on 2019/5/27.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

vector<ListNode*> splitListToParts(ListNode* root, int k) {
    
    vector<ListNode *> sub_lists;
    
    ListNode *cur = root;
    int count = 0;
    while (cur) { // 计算链表长度
        count++;
        cur = cur->next;
    }
    // 计算，分割成k个链表，每个链表的长度
    int size = count / k;
    // 计算余数，来确认是否要在size上+1
    int rem = count % k;
    
    cur = root;
    for (int i = 0; i < k; ++i) {
        if (cur) {
            ListNode Head(-1);
            ListNode* prev = &Head;
            // 根据余数判断链表长度在size基础上+1还是+0
            for (int j = 0; j < size + (rem > 0?1:0); ++j) {
                prev->next = new ListNode(cur->val); // 新建一个节点
                prev = prev->next;
                cur = cur->next;
            }
            
            // 每次生成一根链表就要把余数减1，否则后续每个链表长度都会在size基础上+1
            rem--;
            // 生成一根链表就把这个链表放到vector容器中
            sub_lists.push_back(Head.next);
        }
        // 如果原链表不够分隔，那么只能将null放入vector中
        else {
            sub_lists.push_back(NULL);
        }
    }
    return sub_lists;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
