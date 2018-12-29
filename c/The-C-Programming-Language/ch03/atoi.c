#include <ctype.h>
#include <stdio.h>
int atoi(char s[]);
int main(void)
{
    char s[6];
    s[0] = '1';
    s[1] = '2';
    s[2] = '3';
    s[3] = '2';
    s[4] = '3';
    s[5] = '\0';
    printf("%d", atoi(s));
}

int atoi(char s[])
{
    int i, n, sign;
    for (i = 0; isspace(s[i]); i++) // skip white space
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (n = 0; isdigit(s[i]); i++) {
        printf("%d\n", s[i] - '0');
        n = 10 * n + (s[i] - '0');
    }
    return sign * n;
}