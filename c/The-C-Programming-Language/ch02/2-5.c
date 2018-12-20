/**
 */

#include <stdio.h>

void strcat_(char s[], char t[]);

int any(char s1[], char s2[]);

// 将字符串t连接到字符串s的尾部
void strcat_(char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (s[i] != '\0') { // find end of s
        i++;
    }
    while ((s[i++] = t[j++]) != '\0')
        ;
}

int main(int argc, char *argv[])
{
    int index;
    if (argc == 3)
    {
        index = any(argv[1], argv[2]);
        printf("%d\n", index);
    }
    else
    {
        printf("参数有问题");
    }
    return 0;
}


// 编写函数any 
// 将字符串s2中的任一字符在字符串s1中第一次出现的位置作为结果返回。
// 如果s1中不包含s2中字符 返回-1
int any(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s2[j] == s1[i]) return i;
        }
    }
    return -1;
}
