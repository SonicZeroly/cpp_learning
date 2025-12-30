#include "hash_table.h"
#include <unordered_set>    // 似乎模板都有对应头文件
#include <unordered_map>
#include <algorithm>

using namespace hash_table;

/**
 * 【242. 有效的字母异位词】
 */
bool Solution::isAnagram(std::string s, std::string t){
    // 哈希表：创建一个表，查询目标直接就是表的索引，该索引的值就是这个目标的有无
    int table[27] = {0};
    if(s.length() != t.length()){
        return false;
    }

    int len = s.length();
    for(int i=0; i<len; i++){
        table[s[i]-'a']++;
    }
    
    len = t.length();
    for(int i=0; i<len; i++){
        table[t[i]-'a']--;
        if(table[t[i]] < 0){
            return false;
        }
    }
    return true;
}

/**
 * 【349. 两个数组的交集】
 */
std::vector<int> Solution::intersection(std::vector<int>& nums1, std::vector<int>& nums2){
    // set代表集合，unordered_set里没有重复
    std::unordered_set<int> ret_set;
    std::unordered_set<int> nums_set(nums1.begin(), nums1.end());
    for(int num:nums2){
        if(nums_set.find(num) != nums_set.end()){   // ==.end()代表不存在
            ret_set.insert(num);
        }
    }
    return std::vector<int>(ret_set.begin(), ret_set.end());
}

/**
 * 【202. 快乐数】
 */
bool Solution::isHappy(int n){
    std::unordered_set<int> set;
    while(n != 1){
        int sum = 0;
        // 对个位操作
        while(n){
            sum += (n%10)*(n%10);
            n /= 10;
        }
        n = sum;
        if(set.find(n) != set.end()){
            return false;
        }
        else{
        set.insert(n);
        }
    }
    return true;
}

/**
 * 【1. 两数之和】
 */
std::vector<int> Solution::twoSum(std::vector<int>& nums, int target){
    // 直接但不是最优解
    #if 0
    int len = nums.size();
    std::unordered_set<int> set(nums.begin(), nums.end());
    int index1, index2;
    for(int i=0; i<len; i++){
        int temp = target - nums[i];
        if(set.find(temp) != set.end()){
            index1 = i;
            for(int j=i+1; j<len; j++){
                if(nums[j] == temp){
                    index2 = j;
                    return {index1, index2};
                }
            }
        }
    }
    return {};
    #else
    // 最优解（使用map）
    int len = nums.size();
    std::unordered_map<int,int> map;
    for(int i=0; i<len; i++){
        int temp = target - nums[i];
        auto iter = map.find(temp);     // 比较奇妙
        if(iter == map.end()){
            // 没找到
            map.insert(std::pair<int,int>(nums[i], i));
        }
        else{
            return {i, iter->second};
        }
    }
    return {};
    #endif
}

/**
 * 【第454题.四数相加II】
 */
int Solution::fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4){
    std::unordered_map<int,int> map;
    int n = nums1.size();

    // 遍历A和B数组
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int sum = nums1[i] + nums2[j];

            auto iter = map.find(sum);
            if(iter == map.end()){
                // 不存在
                map.insert(std::pair<int,int>(sum, 1));
            }
            else{
                iter->second ++;
            }
        }
    }

    int count = 0;
    // 遍历C和D数组
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int temp = 0-nums3[i]-nums4[j];
            auto iter = map.find(temp);
            if(iter != map.end()){
                count += iter->second;
                // 符合四数之和为0
            }
        }
    }

    return count;
}

/**
 * 【383. 赎金信】
 */
bool Solution::canConstruct(std::string ransomNote, std::string magazine){
    std::unordered_map<char,int> map;
    int len = magazine.size();
    for(int i=0; i<len; i++){
        auto iter = map.find(magazine[i]);
        if(iter == map.end()){
            map.insert(std::pair<char,int>(magazine[i], 1));
        }
        else{
            iter->second++;
        }
    }

    len = ransomNote.size();
    for(int i=0; i<len; i++){
        auto iter = map.find(ransomNote[i]);
        if(iter == map.end()){
            return false;
        }
        else{
            if(iter->second == 0){
                return false;
            }
            iter->second--;
        }
    }
    return true;
}

/**
 * 【15. 三数之和】
 */
std::vector<std::vector<int>> Solution::threeSum(std::vector<int>& nums){
#if 0   /* 哈希表法 */
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size(); i++){
        // 去重
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }

        std::unordered_set<int> set;
        for(int j=i+1; j<nums.size(); j++){
            // 因为连续两个相同，第二个遍历为b时上一个为c，此时假如就是需要二者相同才为0，这种就符合
            if(j>i+2 && nums[j]==nums[j-1] && nums[j-1]==nums[j-2]){
                continue;
            }
            int target = 0-nums[i]-nums[j];
            if(set.find(target) != set.end()){
                res.push_back({nums[i], target, nums[j]});
                set.erase(target);
            }
            else{
                set.insert(nums[j]);
            }
        }
    }
    return res;
#else   /* 双指针法 */
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());

    if(nums[0] > 0){
        return res;
    }

    for(int i=0; i<nums.size()-2; i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int left = i+1, right = nums.size()-1;
        while(left < right){
            if(0 == nums[i] + nums[left] + nums[right]){
                res.push_back({nums[i], nums[left], nums[right]});
                
                // 去重
                while(left<right && nums[left+1]==nums[left]){
                    left++;
                }
                while(right>left && nums[right-1]==nums[right]){
                    right--;
                }
                
                // 符合时两边都收缩
                right--;
                left++;
            }
            else if(nums[i] + nums[left] + nums[right] > 0){
                right--;
            }
            else{
                left++;
            }
        }
    }
    return res;
#endif
}

/**
 * 【18. 四数之和】
 */
std::vector<std::vector<int>> Solution::fourSum(std::vector<int>& nums, int target){
    
}