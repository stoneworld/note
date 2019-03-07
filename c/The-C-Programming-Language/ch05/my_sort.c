//
// Created by wangshuai on 2019-03-07.
// 该程序按照字母顺序对由文本组成的集合进行排序。
//
// 输入函数必须收集和保存每个文本行的字符，并建立一个指向这些文本行的指针的数组，它同时
// 还必须统计输入的行数，因为在排序和打印的时候需要用到该信息。由于输入函数只能处理有限数目的输入行，
// 所以在输入行数过多而超过限定的最大行数的时候，返回某个表示非法行数的数值 -1。
//
// 输入函数只需要按照指针数组中的次序依次打印这些文本行即可。

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

int readLines(char *lineptr[], int nlines);

void writeLines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main() {
    int nlines; // number of input lines read

    if ((nlines = readLines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writeLines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int mgetline(char line[], int);

char *alloc(int);


#define ALLOCSIZE 10000 /* size of available space */
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) { /* return pointer to n characters */
    // allocbuf + ALLOCSIZE 是 allocbuf 之后 ALLOCSIZE 个元素的地址
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n; // next free position  allocp ~ (allocp + n) 之间被占用
        return allocp - n;
    } else { // not enough room
        return 0;
    }
}


int readLines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLINES];
    nlines = 0;
    while ((len = mgetline(line, MAXLINES)) > 0) {
        if (nlines >= MAXLINES || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

// write output lines
void writeLines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
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

void swap(char *v[], int i, int j);

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


// 快速排序: 对于一个给定的数组，从中选择一个元素，以该元素为界将其余元素划分为两个子集，
// 一个子集中的所有元素都小于该元素，另一个子集中的元素都大于或等于该元素。
// 对这样两个子集递归执行这一过程，当某个子集中的元素数小于2时，这个子集就不需要再次排序，终止递归。
// 396579868  796539868 769539868 765939868 765399868 365799868
void qsort(char *v[], int left, int right) {
    int i, last;
    if (left >= right) { // do nothing if array contains fewer than two elements
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);

}






