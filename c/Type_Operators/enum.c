#include<stdio.h>
enum DAY {MON=1, TUE, WED, THU, FRI, SAT, SUN};
void main()
{
    int x, y, z;
    x = 10;
    y = 20;
    z = 30;
    enum DAY yesterday, today, tomorrow;
    yesterday = MON;
    today = TUE;
    tomorrow = WED;
    printf("%d %d %d \n", yesterday, today, tomorrow);
}
