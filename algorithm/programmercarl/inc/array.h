#ifndef __ARRAY_H
#define __ARRAY_H

#include <iostream>
#include <vector>

class Solution {
public:

    int search(std::vector<int>& nums, int target);         // 二分查找
    int removeElement(std::vector<int>& nums, int val);     // 移除元素
    std::vector<int> sortedSquares(std::vector<int>& nums);       // 有序数组的平方
    int minSubArrayLen(int target, std::vector<int>& nums);       // 长度最小的子数组
    std::vector<std::vector<int>> generateMatrix(int n);    // 螺旋矩阵II
    void interval_sum(void);    // 区间和
    void purchase_land(void);   // 开发商购买土地
};

void test_generateMatrix(void);

#endif