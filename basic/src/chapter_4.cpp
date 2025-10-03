#include "chapter_4.h"
#include <cstring>

/**
 * 编写一个程序，如下输出实例所示的请求并显示信息：
 * What is your first name? Betty Sue
 * Waht is your last name? Yewe
 * What letter grade do you deserve? B 
 * What is your age? 22
 * 
 * Name: Yewe, Betty Sue
 * Grade: C 
 * Age: 22
 */
void test_4_1(void){
    std::string first_name{};
    std::string last_name{};
    char grade{};
    int age{};

    std::cout << "What is your first name? __\b\b";
    std::cin >> first_name;
    std::cout << "Waht is your last name? __\b\b";
    std::cin >> last_name;
    std::cout << "What letter grade do you deserve? __\b\b";
    std::cin >> grade;
    std::cout << "What is your age? __\b\b";
    std::cin >> age;

    std::cout << "Name: " << last_name << ", " << first_name << "\n";
    std::cout << "Grade: " << static_cast<char>(grade+1) << "\n";   //这个题目要求向下取字母
    std::cout << "Age: " << age << "\n";

    return ;
}

/**
 * 编写一个程序，它要求用户首先输入其名，然后输入其姓；
 * 然后程序使用一个逗号和空格将姓和名组合起来，并存储和显示组合结果。
 * 请使用char数组和头文件cstring中的函数。下面是该程序运行时的情形：
 * 
 * Enter your first name: Flip
 * Enter your last name: Fleming
 * Here's the information in a single string: Fleming, Flip
 */
void test_4_3(void){
    std::string first_name{};
    std::string last_name{};

    std::cout << "Enter your first name: __\b\b";
    std::cin >> first_name;
    std::cout << "Enter your last name: __\b\b";
    std::cin >> last_name;

    // 组合名字
    char name[30]{};
    strcpy(name, last_name.c_str());
    strcat(name, " , ");
    strcat(name, first_name.c_str());

    std::cout << "Here's the information in a single string: " << name<< "\n";
}
