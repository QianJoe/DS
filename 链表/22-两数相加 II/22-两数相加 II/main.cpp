//
//  main.cpp
//  22-两数相加 II
//
//  Created by 乔谦 on 2019/5/28.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

int getLength(ListNode *head)
{
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}


// 思路，求出两个链表的长度，算出差值，然后长的先走x步，然后相加
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    int n1 = getLength(l1);
    int n2 = getLength(l2);
    
    ListNode* long_list = NULL;
    ListNode* short_list = NULL;
    int bigger_n = 0;
    int smaller_n = 0;
    
    if (n1 <= n2)
    {
        long_list = l2;
        short_list = l1;
        bigger_n = n2;
        smaller_n = n1;
    }
    else
    {
        long_list = l1;
        short_list = l2;
        bigger_n = n1;
        smaller_n = n2;
    }
    
    
    int temp = bigger_n - smaller_n + 1;
    
    int sum_array[100];
    memset(sum_array, 0, 100);
    int carry_array[100];
    memset(carry_array, 0, 100);
    int sum = 0;
    int carry = 0;
    
    ListNode* long_temp = long_list;
    ListNode* short_temp = short_list;
    
    for (unsigned int i = 1; i <= bigger_n; i++)
    {
        carry = 0;
        if (i < temp)
        {
            sum = long_temp->val;
        }
        else
        {
            sum = long_temp->val + short_temp->val;
            if (sum >= 10)
            {
                sum = sum % 10;
                carry = 1;
            }
            short_temp = short_temp->next;
        }
        sum_array[i] = sum;
        carry_array[i-1] = carry;
        long_temp = long_temp->next;
    }
    
    ListNode* new_head = new ListNode(0);
    long_temp = new_head;
    
    for (unsigned int i = bigger_n; i > 0; i--)
    {
        // 在链表头部进行插入
        sum = sum_array[i] + carry_array[i];
        if (sum >= 10)
        {
            sum = sum % 10;
            carry_array[i-1] = 1;
        }
        short_temp = new ListNode(sum);
        short_temp->next = long_temp->next;
        long_temp->next = short_temp;
    }
    
    sum = sum_array[0] + carry_array[0];
    if (sum)
    {
        short_temp = new ListNode(sum);
        short_temp->next = long_temp->next;
        long_temp->next = short_temp;
    }
    
    return new_head->next;
}

int main(int argc, const char * argv[]) {
    
    ListNode a1(7);
    ListNode b1(2);
    ListNode c1(4);
    ListNode d1(3);

    ListNode a2(5);
    ListNode b2(6);
    ListNode c2(4);

    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;

    a2.next = &b2;
    b2.next = &c2;
    
//    ListNode a1(0);
//    ListNode a2(0);
    
    ListNode *head = addTwoNumbers(&a1, &a2);
    while (head) {
        printf("%d", head->val);
        head = head->next;
    }
    
    return 0;
}
