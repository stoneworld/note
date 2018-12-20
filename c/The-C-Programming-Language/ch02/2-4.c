/**
 * squeeze(s1, s2), 将字符串s1中任何与字符串s2中字符匹配的字符都删除
 */
#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        squeeze(argv[1], argv[2]);
        printf("%s\n", argv[1]);
    }
    else
    {
        printf("参数有问题");
    }
}

void squeeze(char s1[], char s2[])
{
    int i, j;
    int m;

    for (m = 0; s2[m] != '\0'; m++)
    {
        for (i = j = 0; s1[i] != '\0'; i++)
        {
            if (s1[i] != s2[m])
            {
                s1[j++] = s1[i];
            }
        }
    }
    s1[j] = '\0';
}
