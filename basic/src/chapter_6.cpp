#include <iostream>
#include <array>

/**
 * 编写一个程序，最多将10个 donation 值读入到一个 double 数组中（如果您愿意，也可使用模板类 array ）。
 * 程序遇到非数字输入时将结束输入，并报告这些数字的平均值以及数组中有多少个数字大于平均值。
 */
void test_6_2(void){
    constexpr int size{10};
    std::array<double, size> donation{};

    int n=0;
    double avr = 0;
    std::cout << "Enter 10 double value or type non-digital value to exit\n";

    while(n<size){
        std::cout << "Enter : __\b\b";
        if(std::cin>>donation.at(n)){  // 当输入的类型与接收方类型不同时会返回错误
        avr+=donation.at(n);
        n++;
        }
        else{
        break;
        }
    }

    if(n != 0){
        avr /= n;
    }

    int cnt{0};
    for(int i=0; i<n; i++){
        if(donation.at(i) > avr){
            cnt++;
        }
    }

    std::cout << "The average value is: " << avr
        << ", there are " << cnt
        << " larger than average value." << std::endl;   
}

/**
 * 该程序创建一个有上述结构体组成的小型数组，并将其初始化为适当的值。另外，该程序使用一个循环，让用户在下面的选项中进行选择：
 * a. display by name     b. display by title
 * c. display by bopname  d. display by preference
 * q. quit
 * 注意，display by preference 并不意味着显示成员的偏好，而是意味着根据成员的偏好来列出成员。
 * 例如，如果偏好号为 1，则选择 d 将显示成员的头衔。
 */
constexpr int strsize{80};

struct bop {
    char fullname[strsize]; // real name
    char title[strsize];    // job title
    char bopname[strsize];  // secret BOP name
    int preference;         // 0 = fullname, 1 = title, 2 = bopname
};

void test_6_4(void){
    std::array<struct bop, 5> bop_list{{
        {"Wimp Macho", "bbb", "c", 0},
        {"Raki Rhodes", "2XXXX", "3XXXXX", 1},
        {"Celia Laiter", "2AAAA", "3AAAAA", 2},
        {"Hoppy Hipman", "2BBBB", "3BBBBB", 0},
        {"Pat Hand", "4CCCC", "3CCCCC", 1}
    }};

    std::cout << "Benevolent order of Programmers report.\n";
    std::cout << "a. display by name     b. display by title\nc. display by bopname  d. display by preference\nq. quit\n";

    int temp{0};
    char choice{};
    while(1){
        if(temp == 0){
            std::cout << "Enter your choice: __\b\b";
            temp++;
        }else{
            std::cout << "Next choice: __\b\b";
        }

        std::cin >> choice;

        switch (choice)
        {
        case 'a':
            for(int i=0; i<5; i++){
                std::cout << bop_list.at(i).fullname << '\n';
            }
            break;
        case 'b':
            for(int i=0; i<5; i++){
                std::cout << bop_list.at(i).title << '\n';
            }
            break;
        case 'c':
            for(int i=0; i<5; i++){
                std::cout << bop_list.at(i).bopname << '\n';
            }
            break;
        case 'd':
            for(int i=0; i<5; i++){   
                if(0==bop_list.at(i).preference)        std::cout << bop_list.at(i).fullname << '\n';
                else if(1==bop_list.at(i).preference)   std::cout << bop_list.at(i).title << '\n';
                else if(2==bop_list.at(i).preference)   std::cout << bop_list.at(i).bopname << '\n';
            }
            break;
        case 'q':
            std::cout << "Bye!\n";
            return ;
            break;
        
        default:
            break;
        }
    }
}

/**
 * 编写一个程序，记录捐助给 “维护合法权利团体” 的资金。该程序要求用户输入捐献者数目，然后要求用户输入每一个捐献者的姓名和款项。
 * 这些信息被储存在一个动态分配的结构体数组中。每个结构体有两个成员：
 * 用来储存姓名的字符数组（或 string对象）和用来存储款项的 double成员。
 * 读取所有的数据后，程序将显示所有捐款超过 10000 的捐款者的姓名及其捐款数额。
 * 该列表前应包含一个标题，指出下面的捐款者是重要捐款人 Grand Patrons。
 * 然后，程序将列出其他的捐款者，该列表要以 Patrons 开头。如果某种类别没有捐款者，则程序将打印单词 none。该程序只显示这两种类别，而不进行排序。
 */
typedef struct{
    std::string name;
    double count;
}Donator_Info;

void test_6_6(void){
    int donator_num{};
    std::cout << "Enter the num of donator : __\b\b";
    std::cin >> donator_num;

    Donator_Info* donator_list {new Donator_Info[donator_num]{}};   // 需要加{}初始化，否则警告

    for(int i=0; i<donator_num; i++){
        std::cout << "Enter the name of donator "<< i <<" : __\b\b";
        std::cin.ignore(100, '\n');
        std::getline(std::cin, donator_list[i].name);
        std::cout << "Enter the donation count of donator "<< i <<" : __\b\b";
        std::cin >> donator_list[i].count;
    }

    std::cout << "Here is the Patrons List:\n";
    for(int i=0; i<donator_num; i++){
        std::cout << donator_list[i].name+" " << donator_list[i].count << '\n';
    }    

    std::cout << "Here is the Grand Patrons List:\n";
    int temp{0};
    for(int i=0; i<donator_num; i++){
        if(donator_list[i].count > 10000){
            temp++;
            std::cout << donator_list[i].name+" " << donator_list[i].count << '\n';
        }
    }
    if(0==temp){
        std::cout << "None\n";
    }
}

/**
 * 编写一个程序，它打开一个文件文件，逐个字符地读取该文件，直到到达文件末尾，然后指出该文件中包含多少个字符。
 */
#include <fstream>

void test_6_8(void){

    std::ofstream outf{"Test.txt"};     //创建/打开文件

    if(!outf){
        std::cout << "Create or open Error\n";
    }
    else{
        outf << "This is first line \n";
        outf << "This is second line \n";
        outf << "This is third line \n";
    }
    outf.close();

    std::ifstream inf{"Test.txt"};
    if(!inf){
        std::cout << "Open Error\n";
    }
    else{
        std::string content{};
        char temp{};
        int cnt{0};
#if 0
        while(std::getline(inf, content)){
            std::cout << content <<'\n';
        }
#else        
        while(inf >> temp){  // 返回不包括空白字符
        // while(inf.get() != EOF){ //返回所有字符
            cnt++;
        }
#endif
        std::cout << cnt <<'\n';
    }
}

/**
 * 完成编程练习6，但从文件中读取所需的信息。该文件的第一项 应为捐款人数，余下的内容应为成对的行。
 * 在每一对中，第一行为捐款人姓名，第二行为捐款数额。即该文件类似于下面：
 * 4 Sam Stone
 * 2000
 * Freida Flass
 * 100500
 * Tammy Tubbs
 * 5000
 * Rich Raptor
 * 55000
 */
void test_6_9(void){
    std::ifstream inf{"Donation Infomation.txt"};
    int donator_num{};

    if(!inf){
        std::cout << "Open file error\n";
    }
    else{
        inf >> donator_num;
        Donator_Info* donator_list{new Donator_Info[donator_num]{}};

        inf.get();  //读掉前面的空白
        for(int i=0; i<donator_num; i++){
            std::getline(inf, donator_list[i].name);
            inf >> donator_list[i].count;
            inf.get();  //读掉结尾的回车
        }

        std::cout << "Here is the Patrons List:\n";
        for(int i=0; i<donator_num; i++){
            std::cout << donator_list[i].name+" " << donator_list[i].count << '\n';
        }   
    }
}
