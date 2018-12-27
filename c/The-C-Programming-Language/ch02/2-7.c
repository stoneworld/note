/* Write a function invert(x,p,n) 
that returns x with n bit starting at p inverted 
编写一个函数 invert(x, p ,n) 该函数返回对x执行下列操作后的结果值：
将x中从第p位开始的n个位求反，其余值保持不变。
00001000 ^
76543210

00000110

*/

#include<stdio.h>

unsigned invert(unsigned x,int p,int n);

int main(void)
{
    printf("%u",(unsigned)invert((unsigned)8,(int)3,(int)3));
}

unsigned invert(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n)) << (p + 1 -n);
}
