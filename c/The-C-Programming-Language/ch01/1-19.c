// 编写一个函数 将字符串s中的字符顺序颠倒过来。
#include <stdio.h>
int getline_temp(char line[], int maxline);
int reverse_(char s[]);
#define MAXLINE 1000

int main()
{
    char line[MAXLINE];
    while (getline_temp(line, MAXLINE) > 0) {
        reverse_(line);
        printf("%s\n", line);
    }
}

int reverse_(char s[])
{
    int i = 0, j; //记得初始化值 不然会出问题。
    char ch; // 临时变量
    while (s[i] != '\0') {
        ++i; // 获取s的长度
    }
    --i;
    for(j = 0; j < i; j++)
    {
        ch = s[j];
        s[j] = s[i];
        s[i] = ch;
        --i;
    }
    return i;

}

int getline_temp(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = '\0'; // 字符串数组最后一个值是 \0
        ++i;
    }
    return i;
}