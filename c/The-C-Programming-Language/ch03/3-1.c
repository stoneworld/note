/**
 * 二分查找函数两个版本
 */
#include <stdio.h>

int binsearch1(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main(void)
{
    int arr[] = {2, 4, 6, 7, 9, 29, 45, 46, 49, 50, 51, 57};
    printf("%d", binsearch1(45, arr, 12));
    printf("%d", binsearch2(4, arr, 12));
}

int binsearch1(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int binsearch2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    mid = (low + high) / 2;

    while (low < high && x != v[mid])
    {
        if (x > v[mid])
            low = mid + 1;
        else
            high = mid - 1;

        mid = (low + high) / 2;
    }

    if (x == v[mid])
        return mid;
    else
        return -1;
    return -1;
}
