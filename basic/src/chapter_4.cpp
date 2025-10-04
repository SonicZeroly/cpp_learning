#include "chapter_4.h"
#include <cstring>
#include <string_view>
#include <array>

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
    #if 0
    char name[30]{};
    strcpy(name, last_name.c_str());
    strcat(name, ", ");
    strcat(name, first_name.c_str());
    #else   //假如不限定char，C++的std::string是可以直接相加的
    std::string name{last_name + ", " + first_name};

    #endif

    std::cout << "Here's the information in a single string: " << name<< "\n";
}

/**结构体 CandyBar 包含3个成员。
 * 第一个成员存储了糖块的品牌；
 * 第二个成员存储糖块的重量（可以有小数）；
 * 第三个成员存储了糖块的卡路里含量（整数）。
 * 编写一个程序，声明这个结构体，创建一个名为 snack 的 CandyBar 变量，并将其成员分别初始化为 "Mocha Munch"、2.3 和 350。
 * 初始化应在声明 snack 时进行。
 * 最后，程序显示 snack 变量的内容。
 */

void test_4_5(void){
    CandyBar snack{"Mocha Munch", 2.3, 350};
    std::cout << snack.branch << ", " << snack.weight << ", " << snack.calories <<"\n";
}

/**
 * 结构体 CandyBar 包含3个成员，如 编程练习5所示。
 * 请编写一个程序，创建一个包含 3 个元素的 CandyBar 数组，并将它们初始化为所选择的值，
 * 然后显示每个结构体的内容。
 */

 void test_4_6(void){
    std::array<CandyBar, 3> candybar_list{{     //第一层{}初始化 std::array 对象本身，第二层 {}初始化 std::array 内部的数组成员
        {"Mocha Munch", 2.3, 350},
        {"Big Rabbit", 5, 300},
        {"Joy Boy", 4.1, 430}
    }};

    #if 1   // 使用基于范围的for循环
    for(CandyBar snack : candybar_list){
        std::cout << snack.branch << ", " << snack.weight << ", " << snack.calories <<"\n"; 
    }
    #else   // 使用传统for循环
    for(int i=0; i<3; i++){
        std::cout << candybar_list.at(i).branch << ", " 
                  << candybar_list.at(i).weight << ", " 
                  << candybar_list.at(i).calories <<"\n"; 
    }

    #endif
 }

 /**
  * William Wingate从事比萨饼分析服务。对于每个披萨饼，他都需要记录下列信息：
  * 披萨饼公司的名称，可以有多个单词组成；
  * 披萨饼的直径；
  * 披萨饼的重量。
  * 请设计一个能够存储这些信息的结构体，并编写一个使用这种结构体变量的程序。
  * 程序将请求用户输入上述信息，然后显示这些信息。请使用 cin（或其它的方法）和cout。
  */
typedef struct{
    std::string name;      // string_view 对不可变字符串的引用（字面量在静态存储区）
    double diameter;
    double weight;
}Pizza;

void test_4_7(void){
    Pizza pizza_info{};
    std::cout << "Please enter name of the pizza company : __\b\b";
    std::cin >> pizza_info.name;
    std::cout << "Please enter diameter of the pizza : __\b\b";
    std::cin >> pizza_info.diameter;
    std::cout << "Please enter weight of the pizza : __\b\b";
    std::cin >> pizza_info.weight;

    std::cout << pizza_info.name << ", " << pizza_info.diameter << ", " << pizza_info.weight <<"\n";
}

/**
 * 完成编程练习7，但使用 new 来为结构体分配内存，而不是声明一个结构体变量。
 * 另外，让程序在请求输入比萨饼公司名称之前输入比萨饼的直径。
 */
void test_4_8(void){
    Pizza* p_pizza {new(Pizza){}};  // 其中的{}是初始化
    std::cout << "Please enter name of the pizza company : __\b\b";
    std::cin >> p_pizza->name;
    std::cout << "Please enter diameter of the pizza : __\b\b";
    std::cin >> p_pizza->diameter;
    std::cout << "Please enter weight of the pizza : __\b\b";
    std::cin >> p_pizza->weight;

    std::cout << p_pizza->name << ", " << p_pizza->diameter << ", " << p_pizza->weight <<"\n";    

    delete p_pizza;
    p_pizza = nullptr;

}

/**
 * 完成编程练习6，但使用 new 来动态分配数组，而不是声明一个包含 3 个元素的 CandyBar 数组。
 */
void test_4_9(void){
    CandyBar* candybar_list{new CandyBar[3]{
        {"Mocha Munch", 2.3, 350},
        {"Big Rabbit", 5, 300},
        {"Joy Boy", 4.1, 430}
        }
    };

    //此处不可以使用范围for，范围for需要直到数组的起始信息，而数组头指针以及数组退化后的指针都不具有尾部信息
    for(int i=0; i<3; i++){ 
        std::cout << candybar_list[i].branch << ", " 
                  << candybar_list[i].weight << ", " 
                  << candybar_list[i].calories <<"\n"; 
    }

    delete[] candybar_list;
    candybar_list = nullptr;
}

/**
 * 编写一个程序，让用户输入三次 40 码跑的成绩（如果您愿意，也可让用户输入40米跑的成绩），
 * 并显示次数和平均成绩。请使用一个 array对象来存储数据（如果编译器不支持 array 类，请使用数组）。 
 */
void test_4_10(void){
    std::array<double, 3> score{};
    for(int i=0; i<3; i++){
        std::cout << "Enter one score of 40 meiters running: __\b\b";
        std::cin >> score.at(i);
    }

    double avr_score = (score.at(0)+score.at(1)+score.at(2))/3;
    std::cout << "Three scores are: " << score.at(0) << ", " << score.at(1) << ", " << score.at(2) <<"\n"; 
    std::cout << "The average score is " << avr_score << "\n";
}
