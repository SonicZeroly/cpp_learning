#ifndef __HASH_TABLE_H
#define __HASH_TABLE_H

#include <iostream>
#include <vector>

namespace hash_table{

class Solution {
public:
    bool isAnagram(std::string s, std::string t);
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2);
    bool isHappy(int n);
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4);
    bool canConstruct(std::string ransomNote, std::string magazine);
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);
};

}


#endif