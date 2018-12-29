#include <string.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
    char s[] = "123456789";
    printf("%lu\n", strlen(s));  
    return 0;
}

void reverse(char s[])
{
    // strlen 计算长度不包含 结尾符号\0
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}