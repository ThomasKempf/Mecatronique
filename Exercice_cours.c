#include <stdio.h>

long incr();

int main(int argc, char *argv[]) {
    printf("%ld, ", incr());
    printf("%ld, ", incr());
    printf("%ld, ", incr());
    printf("%ld\n", incr());

    return 0;
}
 
long incr() {
    static long nombre = 0;

    nombre++;
    return nombre;
}