//
//  main.cpp
//  06-复杂链表的深度拷贝
//
//  Created by 乔谦 on 2019/5/23.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x): label(x), next(NULL), random(NULL){}
};

// 思路：用一个map保存原来的位置
RandomListNode *copyRandomList(RandomListNode *head)
{
    map<RandomListNode *, int> node_map; // 存放节点地址对应的位置
    vector<RandomListNode *> node_vec; // 使用vector存储节点位置访问地址
    RandomListNode *ptr = head;
    int i = 0;
    while (ptr) {
        
        node_vec.push_back(new RandomListNode(ptr->label)); // 生成label一样的新节点到vector
        node_map[ptr] = i; // 记录原始位置
        ptr = ptr->next;
        i++; // 记录节点位置
    }
    node_vec.push_back(0); // 方便从vector取出最后一个时，不用再处理他的next为NULL了
    ptr = head;
    i = 0; // 再次遍历
    
    while (ptr) { // 连接新链表的next和random
        
        node_vec[i]->next = node_vec[i+1]; // 连接新链表的next
        if (ptr->random) { // 当random不为空时，连接random
            int id = node_map[ptr->random]; // 根据node_map找出地址id
            // 连接random
            node_vec[i]->random = node_vec[id];
        }
        ptr = ptr->next;
        i++;
    }
    return node_vec[0];
}

int main(int argc, const char * argv[]) {
    map<RandomListNode *, int> node_map;
    RandomListNode a(5);
    RandomListNode b(3);
    RandomListNode c(6);
    
    a.next = &b;
    b.next = &c;
    a.random = &c;
    c.random = &a;
    c.random = &c;
    
    node_map[&a] = 1;
    node_map[&b] = 2;
    node_map[&c] = 3;
    
    RandomListNode *head = copyRandomList(&a);
    
    return 0;
}
