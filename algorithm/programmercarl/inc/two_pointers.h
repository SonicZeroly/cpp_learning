#ifndef __TWO_POINTERS_H
#define __TWO_POINTERS_H

#include <iostream>
#include <vector>

namespace two_pointers{
    class Solution {
    public:
        int removeElement(std::vector<int>& nums, int val);
        void reverseString(std::vector<char>& s);
        void replaceNum(void);
        std::string reverseWords(std::string s);
    };
}

#endif