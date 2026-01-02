#include "two_pointers.h"

using namespace two_pointers;

/**
 * 【27. 移除元素】
 */
int Solution::removeElement(std::vector<int>& nums, int val){
    int k = nums.size();
    int fast_p = 0, slow_p = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == val){
            k--;
            fast_p++;
            continue;
        }
        nums[slow_p++] = nums[fast_p++];
    }
    return k;
}

/**
 * 【344.反转字符串】
 */
void Solution::reverseString(std::vector<char>& s){
    int left_p = 0, right_p = s.size()-1;
    while(left_p < right_p){
        char temp = s[left_p];
        s[left_p] = s[right_p];
        s[right_p] = temp;
        left_p++;
        right_p--;
    }
}

/**
 * 【替换数字】
 */
void Solution::replaceNum(void){
    int count = 0;
    // std::vector<char> s;     // std::cin 和 std::vector<char> 之间没有直接的重载操作符 >>
    std::string s;
    while(std::cin >> s){
        for(int i=0; i<s.size(); i++){
            if(s[i]>='0' && s[i]<='9'){
                count++;
            }
        }

        int left_p = s.size()-1;
        s.resize(s.size() + count*6 - count);
        int right_p = s.size()-1;
        while(left_p >= 0){
            if(s[left_p]>='0' && s[left_p]<='9'){
                s[right_p--] = 'r';
                s[right_p--] = 'e';
                s[right_p--] = 'b';
                s[right_p--] = 'm';
                s[right_p--] = 'u';
                s[right_p--] = 'n';
            }
            else{
                s[right_p--] = s[left_p];
            }
            left_p--;
        }
        std::cout << s << std::endl;
    }
}

/**
 * 【151. 反转字符串中的单词】
 */
std::string Solution::reverseWords(std::string s){
    int left_p=0, right_p=s.size()-1;
    while(left_p < right_p){
        char temp = s[left_p];
        s[left_p] = s[right_p];
        s[right_p] = temp;
        left_p++;
        right_p--;
    }

    left_p = 0, right_p = 0;
    for(int i=0; i<s.size(); i++){
        if((i>0 && s[i-1] == ' ' && s[i] != ' ')){
            left_p = i;
        }
        else if(i>0 && s[i-1] != ' ' && s[i] == ' '){
            right_p = i-1;
        }
        else if(i == s.size()-1 && s[i] != ' '){
            right_p = i;
        }

        while(left_p < right_p){
            char temp = s[left_p];
            s[left_p] = s[right_p];
            s[right_p] = temp;
            left_p++;
            right_p--;
        }
    }

    left_p = 0, right_p = 0;
    while(right_p < s.size()){
        if(s[right_p] != ' '){
            s[left_p++] = s[right_p++];
        }
        else if(right_p > 0 && s[right_p-1]!=' ' && s[right_p]==' '){
            s[left_p++] = s[right_p++];
        }
        else if(s[right_p] == ' '){
            right_p++;
        }
    }

    int new_size = left_p;
    if(s[left_p-1] == ' '){
        // s[left_p-1] = '\0';     // std::string可以包含'\0'，因此不可直接修改
        new_size--;
    }
    s.resize(new_size);

    return s;
}

/**
 * 【206.反转链表】
 */

