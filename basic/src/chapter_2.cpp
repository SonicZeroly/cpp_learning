#include <iostream>
#include "chapter_2.h"

// ��дһ��C++��������ʾ���������͵�ַ
void test_2_1(void){
    std::cout << "My name is Zero" << std::endl;
    std::cout << "I am from China" << std::endl;
}

// ��дһ��C++������Ҫ���û�����һ���� long Ϊ��λ�ľ��룬 Ȼ����ת��Ϊ�루yard��һlong ���� 220 �룩
void test_2_2(void){
    int dis{0};
    std::cout << "Enter distance (/long)" << std::endl;
    std::cin >> dis;
    std::cout <<"Enter " << dis << " long, return " << dis*220 << " yard" << std::endl;
}

// ��дһ��C++������ʹ�� 3 ���û�����ĺ���������main()��������������������
void test_2_3a(void){
    std::cout << "Three blind mice" << std::endl;
}

void test_2_3b(void){
    std::cout << "See how they run" << std::endl;  
}

// ��дһ���������е�main( )����һ���û�����ĺ������������¶�ֵΪ��������������Ӧ�Ļ����¶�ֵ����
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