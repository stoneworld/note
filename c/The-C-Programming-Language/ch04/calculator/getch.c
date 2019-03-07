//
// Created by wangshuai on 2019-03-05.
//
#include "calc.h"
#include <stdio.h>

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0; // nex free position in buf

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}