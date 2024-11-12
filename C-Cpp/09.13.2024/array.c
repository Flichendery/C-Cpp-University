#include <stdio.h>

int main()
{
    int c, i, nwhite, nother;
    int nwords[26];    
    int ndigit[10];
    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    for (i = 0; i < 26; ++i)
        nwords[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if ((c >= 'A' && c <= 'Z'))
            ++nwords[c - 'A'];
        else if ((c >= 'a' && c <= 'z'))
            ++nwords[c - 'a'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }

    printf("numbers =");
    for (i = 0; i < 10; ++i)
        printf(" %d - %d,", i, ndigit[i]);

    printf("\nletters = ");
    for (i = 0; i < 26; ++i)
        printf(" %c - %d,", 'A' + i, nwords[i]);

    printf("\nrazd = %d, other = %d\n", nwhite, nother);
}