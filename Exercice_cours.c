#include <stdio.h>

int fct(int t[], int len)
{
    int s=0, i;
    for(i=0; i<len; i++)
    {
        s += t[i];
        printf("%d %d\n",s,i);
    }
    return s;
}
int main()
{
    int t1[]={1,2,3}, t2[5]={0};
    int s1=fct(t1,3);
    printf("%d, %d, %d\n", s1, fct(t1,2), fct(t2,5));
}