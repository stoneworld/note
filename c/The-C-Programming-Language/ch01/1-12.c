#include <stdio.h>
// 编写一个程序，以每行一个单词的形式打印其输入
int main()
{
    int c;
    int inspace = 0;
    // first
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (inspace == 1) {
                inspace = 0;
                printf("\n");
            }
        } else if (inspace == 0) {
            inspace = 1;
            putchar(c);
        } else {
            putchar(c);
        }
    }
    // second 
    while ((c = getchar()) != EOF) {
        if (inspace == 1) {
            if (c == ' ' || c == '\t' || c == '\n') {
                inspace = 0;
                printf("\n");
            } else {
                inspace = 1;
                putchar(c);
            }
        } else {
            if (c == ' ' || c == '\t' || c == '\n') {
            } else {
                putchar(c);
                inspace = 1;
            }
        }
    }
 
}