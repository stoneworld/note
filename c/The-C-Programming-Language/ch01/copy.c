#include <stdio.h>

int main()
{
    int c;
    while (c = getchar() != EOF) {
        putchar(c);
    }
    printf("test\n");
    printf("The value of EOF is %d\n\n", EOF);
    return 0;
}