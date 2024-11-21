#include <stdio.h>

int main() {
    unsigned int a = 0, b = 0, c = 0, i = 0, a2 = 0, b2 = 0;

    scanf("%u %u", &a, &b);

    for (i = 8; i <= 32; i += 8) {
        a2 = (a >> i) & 255;
        b2 = (b >> i) & 255;

        if (a2 * b2 <= 255) c |= ((a2 * b2) << i);
        else c |= (255 << i);

     }

    printf("%u", c);
}