/*
 *  main.c
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

__declspec(dllimport) int       pow(int b, int p);
__declspec(dllimport) double    sqrt(int n);

int main(int argc, char **argv)
{
    if (argc == 4 && strcmp(argv[1], "pow") == 0)
        printf("pow(%s, %s) = %d\n",
            argv[2], argv[3], 
            pow(atoi(argv[2]), atoi(argv[3])));
    else if (argc == 3 && strcmp(argv[1], "sqrt") == 0)
        printf("sqrt(%s) = %f\n", 
            argv[2], sqrt(atoi(argv[2])));
    else
        printf("Other operations are under development.");
    return (0);
}