#include "linked_list.h"

using namespace linked_list;

/**
 * 【203. 移除链表元素】
 * 移除头节点和非头结点逻辑的不同
 */
ListNode* Solution::removeElements(ListNode* head, int val){
    #if 0
    // 移除头节点
    while(head != nullptr && head->val == val){
        head = head->next;
    }
    if(head == nullptr){
        return head;
    }
    
    // 移除非头节点
    ListNode* cur_node = head;
    while(cur_node->next != nullptr){
        if(cur_node->next->val == val){
            // 删除节点
            cur_node->next = cur_node->next->next;
        }
        else{
            cur_node = cur_node->next;
        }
    }
    return head;
    #else
    // 使用虚拟头节点
    ListNode fake_head(0, head);
    ListNode* cur_node = &fake_head;
    while(cur_node->next != nullptr){
        if(cur_node->next->val == val){
            // 删除节点
            cur_node->next = cur_node->next->next;
        }
        else{
            cur_node = cur_node->next;
        }
    }
    return fake_head.next;
    #endif
}

/**
 * 【707.设计链表】
 * 一个难点是循环边界的判断
 */
// 构造函数
MyLinkedList::MyLinkedList(){
    _fake_head = new ListNode(0);
    _len = 0;
}

// 获取第index个节点的值，索引从零开始
int MyLinkedList::get(int index){
    if(index >= _len || index < 0){
        return -1;
    }

    ListNode* cur_node = _fake_head;
    for(int i=0; i<=index; i++){
        cur_node = cur_node->next;
    }
    return cur_node->val;
}

void MyLinkedList::addAtHead(int val){
    ListNode* new_head = new ListNode(val);     // 动态创建后寿命保持
    new_head->next = _fake_head->next;
    _fake_head->next = new_head;
    _len++;
}

void MyLinkedList::addAtTail(int val){
    ListNode* new_tail = new ListNode(val);
    ListNode* temp_node = _fake_head;
    int temp_len = _len;
    while(temp_len>0){
        temp_node = temp_node->next;
        temp_len--;
    }
    temp_node->next = new_tail;
    _len++;
}

void MyLinkedList::addAtIndex(int index, int val){
    if(index > _len || index < 0){
        return ;
    }
    ListNode* new_node = new ListNode(val);
    ListNode* temp_node = _fake_head;
    int temp_index = index;
    while(temp_index>0){
        temp_node = temp_node->next;
        temp_index--;
    }

    new_node->next = temp_node->next;
    temp_node->next = new_node;
    _len++;

}

void MyLinkedList::deleteAtIndex(int index){
    if(index >= _len || index < 0 || _len == 0){
        return ;
    }
    ListNode* temp_node = _fake_head;
    int temp_index = index;
    while(temp_index>0){
        temp_node = temp_node->next;
        temp_index--;
    }

    temp_node->next = temp_node->next->next;
    _len--;
}

void MyLinkedList_Test(void){
    int res = 0;
    MyLinkedList* myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    myLinkedList->addAtTail(3);
    myLinkedList->addAtIndex(1, 2);    // 链表变为 1->2->3
    res = myLinkedList->get(1);              // 返回 2
    printf("res is %d\r\n", res);
    myLinkedList->deleteAtIndex(1);    // 现在，链表变为 1->3
    res = myLinkedList->get(1);              // 返回 3
    printf("res is %d\r\n", res);
    free(myLinkedList);
}

/**
 * 【206. 反转链表】（双指针，直接修改next指向）
 */
ListNode* Solution::reverseList(ListNode* head){
    ListNode* next_node;
    ListNode* pre = NULL;
    ListNode* cur = head;
    while(cur != NULL){
        next_node = cur->next;
        cur->next = pre;

        // 移动pre
        pre = cur;
        // 移动cur
        cur = next_node;
    }
    return pre;
}

/**
 * 【24. 两两交换链表中的节点】
 */
ListNode* Solution::swapPairs(ListNode* head){
    // ListNode* fake_head;
    ListNode* fake_head = new ListNode(0, head);    // 虚拟头节点不能直接创建野指针
    ListNode* node1 = head;
    ListNode* ret = head;
    int set_return_flag = 0;

    while(node1 != NULL && node1->next != NULL){
        ListNode* node2 = node1->next;
        ListNode* temp = node2->next;     // 原来的下一个

        fake_head->next = node2;
        fake_head->next->next = node1;
        node1->next = temp;

        if(set_return_flag == 0){
            ret = fake_head->next;
            set_return_flag = 1;
        }

        // fake_head->next = node1->next;
        fake_head = node1;      // 需要实际修改fake_head的指向
        node1 = fake_head->next;
    }
    return ret;     // 虽然ret是内部定义的指针，但是其指向的内容是函数外就创建好的
}

/**
 * 【19.删除链表的倒数第N个节点】
 */
ListNode* Solution::removeNthFromEnd(ListNode* head, int n){
    ListNode* fake_head = new ListNode(0, head);    // 有可能[1,2],n=2 要去掉head
    // 间隔N的双指针
    ListNode* node_0 = fake_head;
    ListNode* node_n = fake_head;
    for(int i=0; i<n; i++){
        if(node_n->next != nullptr){
            node_n = node_n->next;
        }
        else{
            return NULL;
        }
        
    }
    while(node_n->next != nullptr){
        node_0 = node_0->next;
        node_n = node_n->next;
    }
    node_0->next = node_0->next->next;
    return fake_head->next;
}

/**
 * 【160.链表相交】
 */
ListNode *Solution::getIntersectionNode(ListNode *headA, ListNode *headB){
    if(headA == nullptr || headB == nullptr){
        return NULL;
    }

    // 求A、B链表数量
    int lenA=0, lenB=0;
    ListNode* node_ptr = headA;
    while(node_ptr->next != nullptr){
        lenA++;
        node_ptr = node_ptr->next;
    }

    node_ptr = headB;
    while(node_ptr->next != nullptr){
        lenB++;
        node_ptr = node_ptr->next;
    }

    // 对齐，使从起始点到终点，A、B的长度是一样的
    int len_dis = lenA - lenB;
    int flag = 0;
    if(len_dis > 0){
        node_ptr = headA;
        flag = 1;
    }
    else{
        node_ptr = headB;
        len_dis = -len_dis;
        flag = 2;
    }
    for(int i=0; i<len_dis; i++){
        node_ptr = node_ptr->next;
    }

    // 找交点
    ListNode* tempA = headA;
    ListNode* tempB = headB;
    if(flag == 1)   tempA = node_ptr;
    else            tempB = node_ptr;

    if(tempA == tempB){
        return tempA;
    }

    while(tempA->next != nullptr){
        if(tempA->next == tempB->next){
            return tempA->next;
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return NULL;
}

ListNode *Solution::detectCycle(ListNode *head){
    ListNode* fast, slow;
    // fast指针每次移动两个节点，slow指针每次移动一个节点，有相遇则有环

    // 如何找到这个环的入口？
}
