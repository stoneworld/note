#include <stdio.h>
#define MAXLINE 1000
// linux下Ctrl+d表示一个特殊的二进制值EOF
int getline_temp(char line[], int maxline);
//在ANSI C中，如果要声明空参数表，则必须使用关键字void进行显式声明 ex:void copy(void)
void copy(char to[], char from[]);
int main(void)
{
    int len;//局部变量只会在函数被调用的时候存在，在函数执行完毕退出时消失
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    max = 0;
    while ((len = getline_temp(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);// 保存最长行内容方便后续打印 line会被重新赋值
        }
    }
    if (max > 0) {
        printf("%s", longest);
    }
    return 0;
}
// 程序读入一组文本行，并把最长的文本行打印出来
/*
while (还有未处理的行)
    if(该行比已处理的最长的还要长)
        保存该行为最长行
        保存该行的长度
打印最长的行
*/
//读入一行到s 返回其长度
int getline_temp(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
