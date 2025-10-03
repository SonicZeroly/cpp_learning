#include "chapter_3.h"

/**
 * 编写一个小程序，要求用户使用一个整数指出自己的身高（单位为英寸），然后将身高转换为英尺和英寸。
 * 该程序使用下划线字符来指示输入位置。另外，使用一个const符号常量来表示转换因子。
 */

void test_3_1(void){
    int height{};
    const int foot2inch{12};
    std::cout << "Please enter your height in inch: __\b\b";    //两个\b（退格符）将光标回退两格
    std::cin >> height;

    int height_foot = height/foot2inch; // 英尺
    int height_inch = height%foot2inch; // 英寸

    std::cout << "Your height foot is " << height_foot << "\n";
    std::cout << "Your height inch is " << height_inch << "\n";

    return ;
}

/**
 * 编写一个小程序，要求以几英尺几英寸的方式输入其身高，并以磅为单位输入其体重。（使用3个变量来存储这些信息。）
 * 该程序报告其BMI（Body Mass Index，体重指数）。
 * 为了计算BMI，该程序以英寸的方式指出用户的身高（1英尺为12英寸），并将以英寸为单位的身 高转换为以米为单位的身高（1英寸=0.0254米）。
 * 然后，将以磅为单位 的体重转换为以千克为单位的体重（1千克=2.2磅）。
 * 最后，计算相应的BMI—体重（千克）除以身高（米）的平方。用符号常量表示各种转换因子。
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
 * 编写一个程序，要求用户以度、分、秒的方式输入一个纬度，然后以度为单位显示该纬度。
 * 1度为60分，1分等于60秒，请以符号常量的方式表示这些值。对于每个输入值，应使用一个独立的变量存储它。 
 * 下面是该程序运行时的情况：
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

