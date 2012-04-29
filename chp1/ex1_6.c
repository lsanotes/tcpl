#include<stdio.h>

main()
/* copy input to output; 1st version */
{
    int c;

    c = getchar() != EOF;
    putchar(c);
    printf("%d",c);
}
