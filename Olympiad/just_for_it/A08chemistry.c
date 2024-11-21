#include <stdio.h>
#define SIZE 101

int find(char str[], int N) {
    int i = 0, c = 1;
    char fm[SIZE];

    if (N > 1) {
        for (i = 0; i < N - 1; ++i) {
            if (str[i] == str[i + 1]) c += 1;
            if (str[i] != str[i + 1] && i + 2 >= N && c == 1) printf("%c%c", str[i], str[i + 1]);
            if (str[i] != str[i + 1] && i + 2 < N && c == 1) printf("%c", str[i]);
            if (str[i] != str[i + 1] && i + 2 >= N && c > 1) printf("%c%d%c", str[i], c, str[i + 1]), c = 1;
            if (str[i] != str[i + 1] && i + 2 < N && c > 1) printf("%c%d", str[i], c), c = 1;
            if (str[i] == str[i + 1] && i + 2 >= N && c > 1) printf("%c%d", str[i], c), c = 1;
        }
    }

    else printf("%c", str[0]);
}

int main() {
    char str[SIZE];
    int i = 0;

    while (i < SIZE - 1) {
        int x = getchar();
        if (x == EOF || x == '\n') break;
        str[i++] = x;
    }
    str[i] = '\0';

    find(str, i);
}