#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20 //符号常量不需要出现在声明中 通常大写字母拼写 #define 指令行末尾没有分号


/**
 *当fahr = 0,20,....,300时，分别打印华氏温度与摄氏温度对应表
 * */
int main()
{
    float fahr, celsius; // 变量必须先声明，才能使用，声明包含类型名称和变量名称，基本类型有 float(浮点数),char(一个字符),short(短整型),long(长整型),double(双精度浮点型).
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower; // 为变量赋值
    while (fahr <= upper) { //循环语句
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius); // printf 通用的输出格式化函数
        fahr = fahr + step;
    }
    // for循环的一种实现方式
    for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
        printf("%3.0f\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }

}
