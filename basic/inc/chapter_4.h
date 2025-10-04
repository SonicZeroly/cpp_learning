#ifndef __CHAPTER_4_H
#define __CHAPTER_4_H

/* 复合类型练习 */

#include <iostream>

typedef struct {
    // std::string branch{};    //错误，聚合条件包括 没有默认成员初始化器 
    std::string branch;
    double weight;
    int calories;
}CandyBar;

void test_4_1(void);
void test_4_3(void);
void test_4_5(void);
void test_4_6(void);
void test_4_7(void);
void test_4_8(void);
void test_4_9(void);
void test_4_10(void);

#endif