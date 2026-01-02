#ifndef __STACK_AND_QUEUE_H
#define __STACK_AND_QUEUE_H

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

namespace stack_and_queue{
    class MyQueue {
    public:
        std::stack<int> in_stack;   // 入栈时存储
        std::stack<int> out_stack;  // 出栈时存储，用于使“先进”的能够“先出”
        MyQueue();
        void push(int x);
        int pop();
        int peek();
        bool empty();
    };

    class MyStack {
    public:
        std::queue<int> queue;
        MyStack();
        void push(int x);
        int pop();
        int top();
        bool empty();
    };

    class Solution {
    public:
        bool isValid(std::string s);
        std::string removeDuplicates(std::string s);
        int evalRPN(std::vector<std::string>& tokens);
        std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k);
    };
}


#endif