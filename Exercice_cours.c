#include <stdio.h>

int n=5;

void fct(int p)
{
    printf("%d %d\n", n, p);
}

int main()
{
    int n=3;
    fct(n);
}