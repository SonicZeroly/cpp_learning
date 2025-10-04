#include "chapter_5.h"
#include <array>
#include <cstring>

/**
 * ��дһ��Ҫ���û��������ֵĳ���ÿ������󣬳��򶼽����浽ĿǰΪֹ������������ۼƺ͡�
 * ���û����� 0 ʱ�����������
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
 * ����Ҫ���ۡ�C++ For Fools��һ�顣���дһ����������ȫ����ÿ���µ���������ͼ�����������������۶��
 * ����ͨ��ѭ����ʹ�ó�ʼ��Ϊ�·��ַ����� char * ���飨�� string �������飩���½�����ʾ��������������ݴ�����һ��int�����С�
 * Ȼ�󣬳�����������и�Ԫ�ص���������������һ������������
 */
void test_5_5(void){
    std::string month[12] {"Jan", "Feb", "Mar", "Apr", 
                        "May", "Jun", "Jul", "Aug", 
                        "Sep", "Oct", "Nov", "Dec"};
    int count[12]{0};   // ȫ��Ԫ�س�ʼ��Ϊ0
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
 * ��ɱ����ϰ5������һ��ʹ��һ����ά�������洢���롪��3����ÿ���µ���������
 * ���򽫱���ÿ���������Լ����������������
 */

// ʹ�ñ���ģ�嶨��std::array�Ķ�ά����
template <typename T, std::size_t Row, std::size_t Col>
using Array2d = std::array<std::array<T, Col>, Row>;

void test_5_6(void){
    std::string month[12] {"Jan", "Feb", "Mar", "Apr", 
                        "May", "Jun", "Jul", "Aug", 
                        "Sep", "Oct", "Nov", "Dec"};
    Array2d<double, 3, 12> count{};     // ��Ҳ�ǳ�ʼ��Ϊ0�����Ҫ�ø�ֵ�Ļ���Ҫ{{}} 
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
 * ���һ����Ϊ car �Ľṹ�壬�����洢�����й���������Ϣ��
 * �����̣��洢���ַ������ string �����е��ַ�������������ݣ���������
 * ��дһ���������û�ѯ���ж�������������󣬳���ʹ��new������һ������Ӧ������ car �ṹ����ɵĶ�̬���顣
 * ��������������ʾ�û�����ÿ�����������̣������ɶ��������ɣ��������Ϣ����ע�⣬����Ҫ�ر�С�ģ���Ϊ���������ȡ��ֵ���ַ������μ���4�£���
 * ��󣬳�����ʾÿ���ṹ�����ݡ��ó���������������:
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

    // ��̬��������
    Car* car_list{ new Car[car_num]{} };   // ��̬��������ͱ���std::array��std::array����Ŀ����ֻ�ܳ���

    for(int i=0; i<car_num; i++){
        std::cout << "Please enter the maker: __\b\b";

        // std::cin >> car_list[i].manufacturer;           // ������ǰ���Ŀհ��ַ��ͽ����ˣ����ܴ��������м�Ŀո�
        std::cin.ignore(100, '\n');                        // ��ջ����е�100���ַ�, ����ֱ��һ�� '\n' �����
        std::getline(std::cin, car_list[i].manufacturer);  // ��ȡ���У�ֱ��'\n'

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
 * ��дһ��������ʹ��һ�� char�����ѭ����ÿ�ζ�ȡһ�����ʣ�ֱ���û����� done Ϊֹ��
 * ��󣬸ó���ָ���û������˶��ٸ����ʣ�������done���ڣ��������Ǹó�������������
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
 * ��дһ������ǰһ����ϰ�������ĳ��򣬵�ʹ�� string ����������ַ����顣
 * ���ڳ����а���ͷ�ļ� string����ʹ�ù�ϵ����������� �Ƚϲ���
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
