#include <stdio.h>

int main()
{
    // 1.6 验证表达式 getchar() != EOF 的值是0还是1
    printf("getchar != eof is %d\n\n", getchar() != EOF);
    // linux下Ctrl+d表示一个特殊的二进制值EOF enter 和 ctrl+d结果分别是1、0
    // 1.7 编写一个打印EOF值得程序
    printf("EOF is %d \n", EOF); // -1
}