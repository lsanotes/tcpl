#include <stdio.h>
#include <ctype.h>

main() /* lower: convert input to upper case */
{
    int c;

    while ((c = getchar()) != EOF)
	putchar(toupper(c));
    return 0;
}
