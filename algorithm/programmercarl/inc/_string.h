#ifndef __STRING_H
#define __STRING_H

#include <iostream>
#include <vector>

namespace _string{
    class Solution {
    public:
        void reverseString(std::vector<char>& s);
        std::string reverseStr(std::string s, int k);
        void replaceNum(void);
        std::string reverseWords(std::string s);
        void rightReverse(void);
        int strStr(std::string haystack, std::string needle);
    };
}

#endif