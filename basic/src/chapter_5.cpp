#include "chapter_5.h"
#include <array>
#include <cstring>

/**
 * 编写一个要求用户输入数字的程序。每次输入后，程序都将报告到目前为止，所有输入的累计和。
 * 当用户输入 0 时，程序结束。
 */
void test_5_3(void){
    double sum{0};
    double data_in{0};

    while(1){
        std::cout << "Enter : __\b\b";
        std::cin >> data_in;
        if(data_in == 0){
            return ;
        }

        sum += data_in;
        std::cout << "Sum : " << sum << "\n";
    }
}

/**
 * 假设要销售《C++ For Fools》一书。请编写一个程序，输入全年中每个月的销售量（图书数量，而不是销售额）。
 * 程序通过循环，使用初始化为月份字符串的 char * 数组（或 string 对象数组）逐月进行提示，并将输入的数据储存在一个int数组中。
 * 然后，程序计算数组中各元素的总数，并报告这一年的销售情况。
 */
void test_5_5(void){
    std::string month[12] {"Jan", "Feb", "Mar", "Apr", 
                        "May", "Jun", "Jul", "Aug", 
                        "Sep", "Oct", "Nov", "Dec"};
    int count[12]{0};   // 全部元素初始化为0
    int sum{0};
    
    for(int i=0; i<12; i++){
        std::cout << "Enter the count in " << month[i] << " : __\b\b";
        std::cin >> count[i];
        sum += count[i];
    }
    std::cout << "The total count of this year is " << sum << "\n";
    return ;
}

/**
 * 完成编程练习5，但这一次使用一个二维数组来存储输入——3年中每个月的销售量。
 * 程序将报告每年销售量以及三年的总销售量。
 */

// 使用别名模板定义std::array的二维数组
template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

void test_5_6(void){
    std::string month[12] {"Jan", "Feb", "Mar", "Apr", 
                        "May", "Jun", "Jul", "Aug", 
                        "Sep", "Oct", "Nov", "Dec"};
    Array2d<double, 3, 12> count{};     // 空也是初始化为0，这边要用赋值的话需要{{}} 
    std::array<double, 3> sum{};

    for(int j=0; j<3; j++){
        for(int i=0; i<12; i++){
            std::cout << "Enter the count in " << month[i] << " : __\b\b";
            std::cin >> count[j][i];
            sum[j] += count[j][i];
        }
        std::cout << "The total count of this year is " << sum[j] << "\n";
    }

    std::cout << "The total count of the 3 years is " << sum[0]+sum[1]+sum[2] << "\n";
    return ;    
}

/**
 * 设计一个名为 car 的结构体，用它存储下述有关汽车的信息：
 * 生产商（存储在字符数组或 string 对象中的字符串）、生产年份（整数）。
 * 编写一个程序，向用户询问有多少辆汽车。随后，程序使用new来创建一个由相应数量的 car 结构体组成的动态数组。
 * 接下来，程序提示用户输入每辆车的生产商（可能由多个单词组成）和年份信息。请注意，这需要特别小心，因为它将交替读取数值和字符串（参见第4章）。
 * 最后，程序将显示每个结构的内容。该程序的运行情况如下:
 * 
 * How many cars do you wish to catalog? 2  
 * Car #1: Please enter the maker: Hudson Hornet 
 * Please enter the year made: 1952  
 * 
 * Car #2: Please enter the maker: Kaiser 
 * Please enter the year made: 1951 
 * Here is your collection: 1952 Hudson Hornet 1951 Kaiser
 */
typedef struct {
    std::string manufacturer;
    int year;
}Car;

void test_5_7(void){
    int car_num{};
    std::cout << "How many cars do you wish to catalog? __\b\b";
    std::cin >> car_num;

    // 动态创建数组
    Car* car_list{ new Car[car_num]{} };   // 动态分配数组就别用std::array，std::array的数目参数只能常量

    for(int i=0; i<car_num; i++){
        std::cout << "Please enter the maker: __\b\b";

        // std::cin >> car_list[i].manufacturer;           // 遇到非前导的空白字符就结束了，不能处理名字中间的空格
        std::cin.ignore(100, '\n');                        // 清空缓存中的100个字符, 或者直到一个 '\n' 被清除
        std::getline(std::cin, car_list[i].manufacturer);  // 读取整行，直到'\n'

        std::cout << "Please enter the year made: __\b\b";
        std::cin >> car_list[i].year;
    }

    std::cout << "Here is your collection: " 
            << car_list[0].year << " " << car_list[0].manufacturer + " " 
            << car_list[1].year << " " << car_list[1].manufacturer + "\n";

    delete[] car_list;
    car_list = nullptr;
}

/**
 * 编写一个程序，它使用一个 char数组和循环，每次读取一个单词，直到用户输入 done 为止。
 * 随后，该程序指出用户输入了多少个单词（不包括done在内）。下面是该程序的运行情况：
 * Enter words (type 'done' to stop): anteater birthday category dumpster envy finagle genometry done for sure
 * You entered a total of 7 words.
 */

void test_5_8(void){
    char word[200]{};
    int cnt{0};
    std::cout << "Enter words (type 'done' to stop): ";
    while(1){
        std::cin >> word;
        if(strcmp(word, "done") == 0){
            std::cout << "You entered a total of " << cnt << " words.\n";
            return ;
        }
        cnt++;
    }
}

/**
 * 编写一个满足前一个练习中描述的程序，但使用 string 对象而不是字符数组。
 * 请在程序中包含头文件 string，并使用关系运算符来进行 比较测试
 */
void test_5_9(void){
    std::string word{};
    int cnt{0};
    std::cout << "Enter words (type 'done' to stop): ";
    while(1){
        std::cin >> word;
        if(word == "done"){
            std::cout << "You entered a total of " << cnt << " words.\n";
            return ;
        }
        cnt++;
    }    
}
