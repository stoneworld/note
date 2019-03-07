//
// alloc(n) 返回一个指向n个连续字符存储单元的指针
// afree(p) 释放已分配的存储空间，以便以后重用
//
#include <stdio.h>

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

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}

int main() {
    char amessage[] = "now is the time";
    char *pmessage = "now is the time";
    char *sme;
    sme = amessage;
    sme = "12323df";
    printf("%p\n", sme);
    printf("%s\n", sme);

    printf("%s\n", amessage); // now is the time
    printf("%p\n", amessage); //0x7ffee0fd8920
    amessage[2] = 'e';
    printf("%s\n", amessage); //noe is the time
    printf("%p\n", amessage); //0x7ffee0fd8920

    printf("%s\n", pmessage); //now is the time
    printf("%p\n", pmessage); //0x10ec27f90

    pmessage = "is time";

    printf("%s\n", pmessage); //is time
    printf("%p\n", pmessage); // 0x10ec27fa8
    return 0;
}