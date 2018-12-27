/* In twos complement number systems, x &= (x-1) deletes the rightmost 1 bit in x.
 * Explain why? Use this to right a faster version of bitcount. Bitcount program counts
 * the number of 1 bits in the integer 
 *  我们取 x-1 对其加上1得到x x-1 最右端值为0的位在结果x中变成1 x&(x - 1) 将清楚x最右端值为1的位
 * */

#include<stdio.h>

int bitcount(unsigned x);

int main(void)
{
    printf("%d",bitcount((unsigned)12));
}

int bitcount(unsigned x)
{
    int b;

    for(b=0; x!=0; x &= x-1)
        ++b;

    return b;
}