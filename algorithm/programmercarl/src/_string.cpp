#include "_string.h"

using namespace _string;

/**
 * 【344.反转字符串】
 */
void Solution::reverseString(std::vector<char>& s){
    int left = 0, right = s.size()-1;
    while(left < right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

/**
 * 【541. 反转字符串II】
 */
std::string reverseStr(std::string s, int k){
    int start = 0;
    int remain = s.size();

    while(remain>0){
        if(remain < k){
            // 直接反转
            int left = start, right = start+remain-1;
            while(left < right){
                int temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
            return s;
        }
        else if(remain>=k && remain<2*k){
            // 翻转前k个
            int left = start, right = start+k-1;
            while(left < right){
                int temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
            return s;
        }
        else{
            // 翻转当前2k的前k个
            int left = start, right = start+k-1;
            while(left < right){
                int temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            } 
            remain -= 2*k;
            start += 2*k;
        }
    }
    return s;
}

/**
 * 【54. 替换数字】
 */
void Solution::replaceNum(void){
    // 输入
    std::string s;
    while(std::cin >> s){
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='0' && s[i]<='9'){
                count++;
            }
        }

        int old_index = s.size()-1;
        s.resize(s.size() - count + 6*count);
        int new_index = s.size()-1;

        // 从后往前替换
        while(old_index >= 0){
            if(s[old_index]>='0' && s[old_index]<='9'){
                s[new_index--] = 'r';
                s[new_index--] = 'e';
                s[new_index--] = 'b';
                s[new_index--] = 'm';
                s[new_index--] = 'u';
                s[new_index--] = 'n';
            }
            else{
                s[new_index--] = s[old_index];
            }
            old_index--;
        }
        // 输出
        std::cout << s;
    }
}

/**
 * 【151.翻转字符串里的单词】
 */
std::string reverseWords(std::string s){
    // 整个字符串反转
    int left = 0, right = s.size()-1;
    while(left < right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    // 每个单词反转
    for(int i=0; i<s.size(); ){
        if(s[i] == ' '){
            i++;
            continue;
        }

        left = i, right = i;
        while(right+1<s.size() && s[right+1] != ' '){
            right++;
        }
        i = right+1;
        
        while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }

    // 去除多余空格
    int count = 0;
    int slow_index = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] != ' ' || (i>0 && s[i]==' ' && s[i-1]!=' ')){
            s[slow_index++] = s[i];
            count++;
        }
    }

    // resize
    if(s[count-1] == ' '){
        count -= 1;
    }
    s.resize(count);
    return s;
}

/**
 * 【右旋字符串】
 */
void Solution::rightReverse(void){
    int k = 0;
    std::string s;
    std::cin >> k >> s;

    // 倒序
    int left = 0, right = s.size()-1;
    while(left < right){
        int temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    // 前k个倒序
    left = 0, right = k-1;
    while(left < right){
        int temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    // 后k个倒序
    left = k, right = s.size()-1;
    while(left < right){
        int temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    std::cout << s << std::endl;
}

/**
 * 【28. 实现 strStr()】
 */
int Solution::strStr(std::string haystack, std::string needle){
    if(needle.size() == 0){
        return 0;
    }

    std::vector<int> next(needle.size(), 0);
    // 构建前缀表
    int j = 0;
    next[0] = j;
    for(int i=1; i<needle.size(); i++){
        while(j > 0 && needle[i] != needle[j]){
            j = next[j-1];
        }
        if(needle[i] == needle[j]){
            j++;
        }
        next[i] = j;
    }

    // 在前缀表的帮助下，文字串直接线性遍历
    int needle_index = 0;
    for(int i=0; i<haystack.size(); i++){
        if(haystack[i] == needle[needle_index]){
            if(needle_index == needle.size()-1){
                return i-needle_index;
            }
            needle_index++;
        }
        else{
            while(needle_index > 0 && needle[needle_index]!=haystack[i]){
                // 回退到上一个字符对应的前缀表数值
                needle_index = next[needle_index-1];
            }
            if(haystack[i] == needle[needle_index]){
                if(needle_index == needle.size()-1){
                    return i-needle_index;
                }
                needle_index++;
            }
        }
    }
    return -1;
}

/**
 * 【459.重复的子字符串】
 */
