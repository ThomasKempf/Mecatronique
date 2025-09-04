#include <stdio.h>

void fct1(int *pvar)
{
    (*pvar)++;
}

void fct2(int var)
{
    var+=2;
}

int main()
{
    int n=3;
    printf("%d, ", n);

    fct1(&n);
    printf("%d, ", n);

    fct2(n);
    printf("%d, ", n);

    fct1(&n);
    printf("%d, ", n);

    int *p=&n;
    fct1(p);
    printf("%d, ", n);
    
    fct2(*p);
    printf("%d\n", n);
}