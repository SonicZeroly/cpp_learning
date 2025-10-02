#include <iostream>
#include "chapter_2.h"

// 编写一个C++程序，它显示您的姓名和地址
void test_2_1(void){
    std::cout << "My name is Zero" << std::endl;
    std::cout << "I am from China" << std::endl;
}

// 编写一个C++程序，它要求用户输入一个以 long 为单位的距离， 然后将它转换为码（yard，一long 等于 220 码）
void test_2_2(void){
    int dis{0};
    std::cout << "Enter distance (/long)" << std::endl;
    std::cin >> dis;
    std::cout <<"Enter " << dis << " long, return " << dis*220 << " yard" << std::endl;
}

// 编写一个C++程序，它使用 3 个用户定义的函数（包括main()），并生成下面的输出：
void test_2_3a(void){
    std::cout << "Three blind mice" << std::endl;
}

void test_2_3b(void){
    std::cout << "See how they run" << std::endl;  
}

// 编写一个程序，其中的main( )调用一个用户定义的函数（以摄氏温度值为参数，并返回相应的华氏温度值）。
float celsiu_to_fahrenit(float celsius_val){
    return 1.8*celsius_val+32.0;
}

void test_2_5(void){
    float celsius_val{0.0f};
    std::cout << "Please enter a Celsius value: ";
    std::cin >> celsius_val;
    std::cout << std::endl;
    std::cout << celsius_val <<" degrees Celsius is " <<  celsiu_to_fahrenit(celsius_val) <<" degrees Fahrenheit." << std::endl;
}