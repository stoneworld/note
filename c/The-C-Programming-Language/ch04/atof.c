#include <ctype.h>
#include <stdio.h>
float atof(char s[]);
int main(void)
{
    char line[] = "123.43t";

    printf("%f", atof(line));
}

float atof(char s[])
{
    int i, sign;
    double val, power;
    for (i = 0; isspace(s[i]); i++) // skip white space
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') // 小数点处理
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}