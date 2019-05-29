//
//  main.cpp
//  10-链表组件
//
//  Created by 乔谦 on 2019/5/27.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//给定一个链表（链表结点包含一个整型值）的头结点 head。
//同时给定列表 G，该列表是上述链表中整型值的一个子集。
//返回列表 G 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 G 中）构成的集合。

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

// 思路：问题要找子集的连续组件
// 用指针p表示当前链表结点，p一开始为head头结点，我们从G中挨个遍历，如果能找到，说明p的val在G中存在，这时，把p后移一个，即p=p->next，再在G（从G[0]到G[n-1]）中找p的值，如果找到，同样进香行操作，直到在中找不到p->val为止。此时，组件的个数加1
int numComponents(ListNode* head, vector<int>& G) {
    
    ListNode *p = head;
    int num = 0; // 记录组件个数
    while (p) {
        int len = 0; // 存在链表中的个数
        for (int i = 0; i < G.size(); i++) {
            
            if (G[i] == p->val) { // 发现有，就重新找，看下一个节点在列表中还有没有
                p = p->next;
                i = -1; // 再次x从头开始查找，-1是因为i++
                len++;
                if (!p) {
                    break;
                }
            }
        }
        if (len) { // len不为0就说明有组件
            num++;
        }
        if (!p) {
            break;
        }
        p = p->next;
    }
    return num;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
