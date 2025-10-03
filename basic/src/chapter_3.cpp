#include "chapter_3.h"

/**
 * ��дһ��С����Ҫ���û�ʹ��һ������ָ���Լ�����ߣ���λΪӢ�磩��Ȼ�����ת��ΪӢ�ߺ�Ӣ�硣
 * �ó���ʹ���»����ַ���ָʾ����λ�á����⣬ʹ��һ��const���ų�������ʾת�����ӡ�
 */

void test_3_1(void){
    int height{};
    const int foot2inch{12};
    std::cout << "Please enter your height in inch: __\b\b";    //����\b���˸����������������
    std::cin >> height;

    int height_foot = height/foot2inch; // Ӣ��
    int height_inch = height%foot2inch; // Ӣ��

    std::cout << "Your height foot is " << height_foot << "\n";
    std::cout << "Your height inch is " << height_inch << "\n";

    return ;
}

/**
 * ��дһ��С����Ҫ���Լ�Ӣ�߼�Ӣ��ķ�ʽ��������ߣ����԰�Ϊ��λ���������ء���ʹ��3���������洢��Щ��Ϣ����
 * �ó��򱨸���BMI��Body Mass Index������ָ������
 * Ϊ�˼���BMI���ó�����Ӣ��ķ�ʽָ���û�����ߣ�1Ӣ��Ϊ12Ӣ�磩��������Ӣ��Ϊ��λ���� ��ת��Ϊ����Ϊ��λ����ߣ�1Ӣ��=0.0254�ף���
 * Ȼ�󣬽��԰�Ϊ��λ ������ת��Ϊ��ǧ��Ϊ��λ�����أ�1ǧ��=2.2������
 * ��󣬼�����Ӧ��BMI�����أ�ǧ�ˣ�������ߣ��ף���ƽ�����÷��ų�����ʾ����ת�����ӡ�
 */
void test_3_2(void){
    double height_foot{};
    double height_inch{};
    double weight_pound{};

    constexpr double inch2meter_val{0.0254};
    constexpr double kg2pound{2.2};

    std::cout << "Next you should enter your height in foot and inch\n";
    std::cout << "Please enter the foot of your height : __\b\b";
    std::cin >> height_foot;
    std::cout << "Please enter the inch of your height: __\b\b";
    std::cin >> height_inch;
    std::cout << "Now please enter your weight in pound: __\b\b";
    std::cin >> weight_pound;

    height_inch += height_foot*12;
    double height_meter = height_inch*inch2meter_val;
    double weight_kg = weight_pound/kg2pound;

    double bmi_res = weight_kg/(height_meter*height_meter);
    std::cout << "Your BMI is " << bmi_res << "\n";

}

/**
 * ��дһ������Ҫ���û��Զȡ��֡���ķ�ʽ����һ��γ�ȣ�Ȼ���Զ�Ϊ��λ��ʾ��γ�ȡ�
 * 1��Ϊ60�֣�1�ֵ���60�룬���Է��ų����ķ�ʽ��ʾ��Щֵ������ÿ������ֵ��Ӧʹ��һ�������ı����洢���� 
 * �����Ǹó�������ʱ�������
 */
void test_3_3(void){
    double degree{}, minute{}, second{};
    std::cout << "Enter Enter a latitude in degree, minutes, and seconds:\n";
    std::cout << "First, enter the degree: __\b\b";
    std::cin >> degree;
    std::cout << "Next, enter the minutes of arc: __\b\b";
    std::cin >> minute;
    std::cout << "Finally, enter the seconds of arc: __\b\b";
    std::cin >> second;

    std::cout << degree << " degrees, " << minute << " minutes, " << second << " seconds = " 
    << (degree + minute/60 + second/(60*60)) << " degrees.\n";
}

