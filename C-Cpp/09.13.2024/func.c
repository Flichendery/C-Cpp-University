#include <stdio.h>

int prchar(int c, int ndigit[], int nwords[]);
int results(int ndigit[], int nwords[]);

int main()
{
    int c;
    int nwords[26];    
    int ndigit[10];
    for (int i = 0; i < 10; ++i)
        ndigit[i] = 0;
    for (int i = 0; i < 26; ++i)
        nwords[i] = 0;

    while ((c = getchar()) != EOF) {
        prchar(c, ndigit, nwords);
    }

    results(ndigit, nwords);
}

int prchar(int c, int ndigit[], int nwords[])
{
    if (c >= '0' && c <= '9') {
        ++ndigit[c - '0'];
    } else if (c >= 'A' && c <= 'Z') {
        ++nwords[c - 'A'];
    } else if (c >= 'a' && c <= 'z') {
        ++nwords[c - 'a'];
    }
}

int results(int ndigit[], int nwords[])
{
    printf("numbers =");
    for (int i = 0; i < 10; ++i)
        printf(" %d - %d,", i, ndigit[i]);

    printf("\nletters = ");
    for (int i = 0; i < 26; ++i)
        printf(" %c - %d,", 'A' + i, nwords[i]);
}