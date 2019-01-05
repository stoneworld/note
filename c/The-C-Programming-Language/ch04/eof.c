#include <stdio.h>

int main(void)
{
    int i = -1;
    signed char sc = 0xff;
    unsigned char usc = 0xff;

    printf("转成16进制后i是 %x, sc是 %x 是 %d\n", i, sc, sc);
    if (i == sc)
    {
        puts("i == sc");
    }
    else
    {
        puts("i != sc");
    }
    putchar('\n');
    printf("转成16进制后i是 %x, usc是 %x 是 %d\n", i, usc, usc);
    if (i == usc)
    {
        puts("i == usc");
    }
    else
    {
        puts("i != usc");
    }
    return 0;
}