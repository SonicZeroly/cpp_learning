#include "chapter_4.h"
#include <cstring>

/**
 * ��дһ�������������ʵ����ʾ��������ʾ��Ϣ��
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
    std::cout << "Grade: " << static_cast<char>(grade+1) << "\n";   //�����ĿҪ������ȡ��ĸ
    std::cout << "Age: " << age << "\n";

    return ;
}

/**
 * ��дһ��������Ҫ���û���������������Ȼ���������գ�
 * Ȼ�����ʹ��һ�����źͿո��պ���������������洢����ʾ��Ͻ����
 * ��ʹ��char�����ͷ�ļ�cstring�еĺ����������Ǹó�������ʱ�����Σ�
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

    // �������
    char name[30]{};
    strcpy(name, last_name.c_str());
    strcat(name, " , ");
    strcat(name, first_name.c_str());

    std::cout << "Here's the information in a single string: " << name<< "\n";
}
