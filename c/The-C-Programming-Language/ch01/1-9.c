// 编写一个程序将输入复制到输出的程序，将其中的连续的多个空格用一个空格代替。
/**
 * 说明：当前字符和前一个字符都是空格的时候不输出(continue)。
 */
#include <stdio.h>
int main()
{
    int prev; // 前一个字符
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' && prev == ' ') continue;
        prev = c;
        putchar(c);
    }
    return 0;
}
