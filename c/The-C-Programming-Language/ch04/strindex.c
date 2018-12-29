// 编写一个程序 将输入中包含特定模式或字符串的各行打印出来
#include <stdio.h>
#define MAXLINE 1000
int getline_(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould";

int main(void)
{
    char line[MAXLINE];
    int found = 0;
    while (getline_(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s\n", line);
            found++;
        }
    }
    return found;
}
/**
 * get line into s, return length
 */
int getline_(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }

    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}