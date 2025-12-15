#pragma once
#include <iostream>

struct ListNode{    // C++中的结构体和C不，C++中结构体和类相似，只是成员默认public
    int val;        // 数据域的值
    ListNode* next; // 下一个节点指针

    // 构造函数
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next):val(x),next(next){}
};

class MyLinkedList {
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x):val(x),next(nullptr){};
    };
    
    ListNode* _fake_head ;
    int _len;
public:
    MyLinkedList();
    int get(int index);
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);
};

namespace linked_list{
    class Solution {
    public:
        ListNode* removeElements(ListNode* head, int val);  // 移除链表元素
        ListNode* reverseList(ListNode* head);      // 反转链表
        ListNode* swapPairs(ListNode* head);        // 两两交换链表中的节点
        ListNode* removeNthFromEnd(ListNode* head, int n);  // 删除链表的倒数第N个节点
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);    // 链表相交
        ListNode *detectCycle(ListNode *head);      // 环形链表II
    };
}

void MyLinkedList_Test(void);
