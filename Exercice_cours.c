#include <stdio.h>
#include <stdint.h> // pour la definition de uint8_t

int main()
{
    uint8_t a=0b00100110;
    uint8_t b=0b01001011;
    printf("a=%d, b=%d\n", a, b);
    printf("%d, ", a>>1);
    printf("%d, ", a>>2);
    printf("%d, ", a&b);
    printf("%d, ", a&0x0F);
    printf("%d\n", (b&0x0F)<<1);
}