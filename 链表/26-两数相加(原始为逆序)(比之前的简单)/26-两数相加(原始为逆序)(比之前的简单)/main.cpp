//
//  main.cpp
//  26-两数相加(原始为逆序)(比之前的简单)
//
//  Created by 乔谦 on 2019/5/28.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
 
    ListNode *p = new ListNode(-1);
    ListNode *q = p;
    int carry = 0;
    while (l1 || l2)
    {
        int val1 = l1 ? l1->val : 0;// 如果短的链表没有和长的对齐时，短的值为0，方便相加
        int val2 = l2 ? l2->val : 0;
        
        int sum = val1 + val2 + carry;
        if(sum >= 10) // 如果此次相加需要进位，carry为1
        {
            sum = sum % 10;
            carry = 1;
        }
        else // 如果此次相加不需要进位 carry为0
        {
           carry = 0;
        }
        q->next = new ListNode(sum); // 创建新节点
        // 头插
        q = q->next;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2; // 当l1和l2为null时不取其next指针，一直让其保持空的状态
    }
    if(carry == 1)//考虑最高位进位的情况
        q->next = new ListNode(1);
    return p->next;
}

int main(int argc, const char * argv[]) {
    
    ListNode a1(2);
    ListNode b1(4);
    ListNode c1(3);
    
    ListNode a2(5);
    ListNode b2(6);
    ListNode c2(4);
    
    a1.next = &b1;
    b1.next = &c1;
    
    a2.next = &b2;
    b2.next = &c2;
    
    ListNode *head = addTwoNumbers(&a1, &a2);
    
    while (head) {
        printf("%d", head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}
