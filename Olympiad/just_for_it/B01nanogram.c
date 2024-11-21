#include <stdio.h>
#include <stdlib.h>

int find(char str[], int N) {
    int i = 0, lencount = 0, count = 1, cb = -1;

    if (N > 1) {
        for (i = 0; i < N - 1; ++i) {
            if (((str[i] == 'B' || (i + 2 >= N)) && str[i] != str[i + 1])) lencount += 1;
        }

        printf("%d", lencount);

        for (i = 0; i < N - 1; ++i) {
            if (str[i] == str[i + 1] && str[i] == 'B') count += 1;
            if (str[i] != str[i + 1]) count += 1;
        }
    }        
}

int main() {
    int N = 0, i = 0;
    
    scanf("%d", &N);

    char* str = (char*)malloc(N * sizeof(char));

    for (i = 0; i < N; ++i) {
        char x;
        scanf("%c", &x);
        str[i] = x;
    }

    find(str, N);
    free(str);
}
// Not done yet :p