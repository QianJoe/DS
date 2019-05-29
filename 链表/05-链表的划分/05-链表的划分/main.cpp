//
//  main.cpp
//  05-链表的划分
//
//  Created by 乔谦 on 2019/5/23.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>
// 已知指针head和值x，把小于x的z节点放在大于等于x的前面，并且不改之前的相对y位置
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode *partiton(ListNode *head, int x)
{
    ListNode less_head(0); // 设置两个临时头结点
    ListNode more_head(0);
    
    ListNode *less_ptr = &less_head; // 临时指针
    ListNode *more_ptr = &more_head;
    
    while (head) {
        
        if (head->val < x) { // 小于x的放在小链表上
            less_ptr->next = head;
            less_ptr = less_ptr->next;
        } else
        {
            more_ptr->next = head;
            more_ptr = more_ptr->next;
        }
        
        head = head->next;
    }
    less_ptr->next = more_head.next;
    more_ptr->next = NULL;
    
    return less_head.next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
