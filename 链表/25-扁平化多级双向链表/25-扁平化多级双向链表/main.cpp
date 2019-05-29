//
//  main.cpp
//  25-扁平化多级双向链表
//
//  Created by 乔谦 on 2019/5/28.
//  Copyright © 2019 乔谦. All rights reserved.
//

#include <iostream>

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;
    
    Node() {}
    
    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

// 迭代法
Node* flatten2(Node* head)
{
    Node *cur = head; // 当前节点
    while(cur != NULL){
        if(cur->child != NULL){
            
            Node *child = cur->child;
            Node *sign = child; // 操作child链表
            while(child->next != NULL){ // 一直到尾部，然后用于连接cur的next
                child = child->next;
            }
            
            // 结尾插入
            if (cur->next == NULL){
                
                child->next = cur->next;
                sign->prev = cur;
                cur->next = sign;
            }else{
                
                //非结尾插入
                child->next = cur->next;
                sign->prev = cur;
                cur->next->prev = child;
                cur->next = sign;
            }
            cur->child = NULL;
        }
        cur = cur->next;
    }
    return head;
}

// 递归法
Node* flatten(Node* head) {
    
    if (head == NULL) {
        return head;
    }
    if (head->child == NULL) { // 如果此时的head的child没有，就扁平化下一个
        head->next = flatten(head->next);
    } else // 如果有，就处理
    {
        Node* n = flatten(head->next);
        Node* c = head->child;
        head->child = NULL;
        c = flatten(c); // 扁平化child
        // 连接
        c->prev = head;
        head->next = c;
        while(c && c->next)
            c = c->next;
        c->next = n;
        if(n)
            n->prev = c;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
