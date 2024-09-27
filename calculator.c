#include <stdio.h>

int main() {

    char arr[100];
    int count = 0;
    char c;
    double result = 0.0;
    double cur = 0.0;
    double part = 0.0;
    int flag = 0;
    int sign = 1;
    double div = 1.0;

    while (count < 100 && (c = getchar()) != '=' && c != EOF) {
        if ((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '.' || c == '=') {
            arr[count] = c;
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        if (arr[i] >= '0' && arr[i] <= '9') {
            if (flag) {
                div *= 10.0;
                part = part * 10 + (arr[i] - '0');
            } else {
                cur = cur * 10 + (arr[i] - '0');
            }
        } else if (arr[i] == '.') {
            flag = 1;
        } else if (arr[i] == '+' || arr[i] == '-') {
            cur += part / div;
            result += sign * cur; 

            cur = 0.0;
            part = 0.0;
            flag = 0;
            div = 1.0;

            if (arr[i] == '+') {
                sign = 1;
            } else {
                sign = -1;
            }
        }
    }

    cur += part / div;
    result += sign * cur;

    printf("%1f\n", result);
}