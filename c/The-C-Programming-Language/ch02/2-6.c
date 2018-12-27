/* Write a function setbits(x,p,n,y) 
that returns x with the n bits that begin at positionp 
set to the rightmost n bits of y,
leaving the other bits unchanged.
编写一个函数 setbits(x, p, n, y) 该函数返回队x执行下列操作后的结果值：
将x中从第p位开始的n个位设置为y中最右边的n位的值，x得其余各位保持不变
*/

#include<stdio.h>

unsigned setbits(unsigned x,int p,int n,unsigned y);

int main(void)
{
    printf("%u", 7 << 1);
    //printf("%u",setbits((unsigned)12,3,2,(unsigned)57));
}

unsigned setbits(unsigned x,int p,int n,unsigned y)
{
    return (x & ~(~(~0 << n) << (p+1-n))) | ( y & ~(~0<<n)) << (p+1-n);
}