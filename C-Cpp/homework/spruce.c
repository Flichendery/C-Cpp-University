#include <stdio.h>

int main() {
  int h, i, j, k;

  scanf ("%d", &h);

  for (i = 1; i <= h; i++) {
    for (j = 1; j <= (h + i); j++) {
      if (j <= (h - i + 1))
        putchar(' ');
      else
        putchar('#');
    }
    putchar('\n');
  }

  for (k = 1; k <= (h + 1); k++) {
      if (k <= (h))
        putchar(' ');
      else
        putchar('#');    
  }

  return 0;    
}