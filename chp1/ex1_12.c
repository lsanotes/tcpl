#include<stdio.h>

#define IN  1
#define OUT 0

main()
{
    int c;
    int state = OUT;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            state = IN;
            putchar(c);
        }
        else if (state == IN) {
                state = OUT;
                putchar('\n');
             }
    }
}
