#include <stdio.h>

int main() {
    int a = 21;
    unsigned int b = 396;
    char ch = 'z';
    float f = 4.75f;
    double d = 312.436184;
    long int lh = 23456789;
    char str[] = "hello C";

    printf("Integer (%d): %d\n", a);
    printf("Unsigned (%u): %u\n", b);
    printf("Character (%c): %c\n", ch);
    printf("Float (%f): %f\n", f);
    printf("Double (%lf): %lf\n", d);
    printf("Hexa Int (%x): %x\n", a);
    printf("String (%s): %s\n", str);
    printf("Hex (%x): %x\n", a);
    printf("Octal (%o): %o\n", a);
    printf("Address (%p): %p\n", a);
    printf("Percent (%%): %%\n");

    return 0;
}
