#include <stdio.h>

/**
 * 1-8 编写一个统计空格、制表符与换行符的程序
 */ 
int main()
{
    int blanks = 0, tabs = 0, newlines = 0;

    int c;

    while ((c = getchar()) != EOF) {
        if(c == '\t') {
            ++tabs;        }
        if (c == ' ') {
            ++blanks;
        }
        if (c == '\n') {
            ++newlines;
        }
    }
    printf("Blanks: %d\nTabs: %d\nLines: %d\n", blanks, tabs, newlines);
    return 0;
}