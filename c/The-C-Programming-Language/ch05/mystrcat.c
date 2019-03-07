void my_strcat(char *, char *);

int my_strend(char *, char *);

int my_strlen(char *);

int mgetline(char line[], int maxline);

#include<stdio.h>

#define MAXLINE 1000

// 将 t 指向的字符串复制到 s 指向的字符串的尾部。
void my_strcat(char *s, char *t) {
    while (*s != '\0')
        s++;
    s--;
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

// 如果字符串 t 出现在字符串 s 的尾部，该函数返回1 否则返回0；
int my_strend(char *s, char *t) {
    int len;
    len = my_strlen(t);
    while (*s != '\0')
        ++s;
    --s;

    while (*t != '\0')
        ++t;

    --t;
    while (len > 0) {
        if (*t == *s) {
            --t;
            --s;
            --len;
        } else
            return 0;
    }
    if (len == 0)
        return 1;
    return 0;
}


int my_strlen(char *t) {
    char *p;
    p = t;
    while (*p != '\0')
        p++;
    return p - t;
}


int main(void) {
    int len;
    char s[MAXLINE], t[MAXLINE];

    putchar('s');
    putchar(':');
    mgetline(s, MAXLINE);

    putchar('t');
    putchar(':');
    mgetline(t, MAXLINE);
    int ret;
    ret = my_strend(s, t);
    printf("%d", ret);

    my_strcat(s, t);

    printf("%s", s);

    return 0;
}

int mgetline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}