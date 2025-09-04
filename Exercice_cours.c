#include <stdio.h>

#define N_ITER 4
#define AFFICHE(x) printf("Valeur : %d\n", x)

int main()
{
    int i=0;
    while(i<N_ITER)
    {
    printf("%d, ", i);
    i++;
    }
    printf("\n");
    AFFICHE(i);
}