#include <stdio.h>
#define SIZE 100

int find(int str[], int i) {
    int k = 0;
    int cw = 0, cb = 0;
    if (i >= 2) {
        for (k = 0; k < i - 1; ++k) {
            if (str[k] != str[k + 1] && str[k] != 1) cw += 1;
            if (k + 1 >= i - 1 && str[k] == str[k + 1] && str[k] != 1) cw += 1;
            if (str[k] != str[k + 1] && str[k] == 1) cb += 1;
            if (k + 1 >= i - 1 && str[k] == str[k + 1] && str[k] == 1) cb += 1;
            if (k + 1 >= i - 1 && str[k] != str[k + 1] && str[k] == 0) cb += 1;
            if (k + 1 >= i - 1 && str[k] != str[k + 1] && str[k] == 1) cw += 1;
        }
        printf("%d %d", cb, cw);
    }
    
    else {
        if (i == 1 && str[0] != 1) cw += 1;
        if (i == 1 && str[0] == 1) cb += 1;
        printf("%d %d", cb, cw);
    }
}


int main() {
    int str[SIZE];
    int i = 0;

    while (1) {
        int x = getchar();
        if (x == '\n') break;
        if (x == ' ' || x == '\t') continue;
        if (x >= '0' && x <= '9') {
            str[i++] = x - '0';
        }
    }

    find(str, i);
}