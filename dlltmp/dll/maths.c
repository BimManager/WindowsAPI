/*
 *  maths.c
 */

#include "maths.h"

#define __ABS(x) ((x) < 0 ? -(x) : (x))

__declspec(dllexport)
int     pow(int b, int p)
{
    if (b <= 0 && p <= 0)
        return (0);
    else if (b == 1 || p == 1)
        return (b);
    else
        return (b * pow(b, p - 1));
}

__declspec(dllexport)
double  sqrt(int n)
{
    double x;

    if (n <= 1)
        return (1);
    x = ~(0UL);
    return (x);
}