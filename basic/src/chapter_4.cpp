#include "chapter_4.h"
#include <cstring>
#include <string_view>
#include <array>

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
    #if 0
    char name[30]{};
    strcpy(name, last_name.c_str());
    strcat(name, ", ");
    strcat(name, first_name.c_str());
    #else   //���粻�޶�char��C++��std::string�ǿ���ֱ����ӵ�
    std::string name{last_name + ", " + first_name};

    #endif

    std::cout << "Here's the information in a single string: " << name<< "\n";
}

/**�ṹ�� CandyBar ����3����Ա��
 * ��һ����Ա�洢���ǿ��Ʒ�ƣ�
 * �ڶ�����Ա�洢�ǿ��������������С������
 * ��������Ա�洢���ǿ�Ŀ�·�ﺬ������������
 * ��дһ��������������ṹ�壬����һ����Ϊ snack �� CandyBar �������������Ա�ֱ��ʼ��Ϊ "Mocha Munch"��2.3 �� 350��
 * ��ʼ��Ӧ������ snack ʱ���С�
 * ��󣬳�����ʾ snack ���������ݡ�
 */

void test_4_5(void){
    CandyBar snack{"Mocha Munch", 2.3, 350};
    std::cout << snack.branch << ", " << snack.weight << ", " << snack.calories <<"\n";
}

/**
 * �ṹ�� CandyBar ����3����Ա���� �����ϰ5��ʾ��
 * ���дһ�����򣬴���һ������ 3 ��Ԫ�ص� CandyBar ���飬�������ǳ�ʼ��Ϊ��ѡ���ֵ��
 * Ȼ����ʾÿ���ṹ������ݡ�
 */

 void test_4_6(void){
    std::array<CandyBar, 3> candybar_list{{     //��һ��{}��ʼ�� std::array �������ڶ��� {}��ʼ�� std::array �ڲ��������Ա
        {"Mocha Munch", 2.3, 350},
        {"Big Rabbit", 5, 300},
        {"Joy Boy", 4.1, 430}
    }};

    #if 1   // ʹ�û��ڷ�Χ��forѭ��
    for(CandyBar snack : candybar_list){
        std::cout << snack.branch << ", " << snack.weight << ", " << snack.calories <<"\n"; 
    }
    #else   // ʹ�ô�ͳforѭ��
    for(int i=0; i<3; i++){
        std::cout << candybar_list.at(i).branch << ", " 
                  << candybar_list.at(i).weight << ", " 
                  << candybar_list.at(i).calories <<"\n"; 
    }

    #endif
 }

 /**
  * William Wingate���±������������񡣶���ÿ����������������Ҫ��¼������Ϣ��
  * ��������˾�����ƣ������ж��������ɣ�
  * ��������ֱ����
  * ��������������
  * �����һ���ܹ��洢��Щ��Ϣ�Ľṹ�壬����дһ��ʹ�����ֽṹ������ĳ���
  * ���������û�����������Ϣ��Ȼ����ʾ��Щ��Ϣ����ʹ�� cin���������ķ�������cout��
  */
typedef struct{
    std::string name;      // string_view �Բ��ɱ��ַ��������ã��������ھ�̬�洢����
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
 * ��ɱ����ϰ7����ʹ�� new ��Ϊ�ṹ������ڴ棬����������һ���ṹ�������
 * ���⣬�ó��������������������˾����֮ǰ�����������ֱ����
 */
void test_4_8(void){
    Pizza* p_pizza {new(Pizza){}};  // ���е�{}�ǳ�ʼ��
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
 * ��ɱ����ϰ6����ʹ�� new ����̬�������飬����������һ������ 3 ��Ԫ�ص� CandyBar ���顣
 */
void test_4_9(void){
    CandyBar* candybar_list{new CandyBar[3]{
        {"Mocha Munch", 2.3, 350},
        {"Big Rabbit", 5, 300},
        {"Joy Boy", 4.1, 430}
        }
    };

    //�˴�������ʹ�÷�Χfor����Χfor��Ҫֱ���������ʼ��Ϣ��������ͷָ���Լ������˻����ָ�붼������β����Ϣ
    for(int i=0; i<3; i++){ 
        std::cout << candybar_list[i].branch << ", " 
                  << candybar_list[i].weight << ", " 
                  << candybar_list[i].calories <<"\n"; 
    }

    delete[] candybar_list;
    candybar_list = nullptr;
}

/**
 * ��дһ���������û��������� 40 ���ܵĳɼ��������Ը�⣬Ҳ�����û�����40���ܵĳɼ�����
 * ����ʾ������ƽ���ɼ�����ʹ��һ�� array�������洢���ݣ������������֧�� array �࣬��ʹ�����飩�� 
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
