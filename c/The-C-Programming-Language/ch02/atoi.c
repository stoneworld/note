#include <stdio.h>
int atoi(char s[]);
int main()
{
    int i;
    char s[10];
    for (i = 0;i < 9; i++) {
        s[i] = '1' + i;
    }
    s[9] = '\0';
    printf("%d\n", atoi(s));
}

int atoi(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] > '0' && s[i] <= '9'; ++i) {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}