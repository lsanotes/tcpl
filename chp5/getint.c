#include <stdio.h>

#define SIZE 10
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;		/* next free position in buf */

int getch(void) /* get a (possible pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
	printf("ungetch: too many characters\n");
    else
	buf[bufp++] = c;
}

/* getint: get net integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))    /* skip white space */
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-')
        ungetch(c);    /* it's not a number */
        return 0;

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn +( c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

main ()
{
    int n, array[SIZE], getint(int *);

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
	;
    for (n = 0; n < SIZE; n++)
	printf("%d",array[n]);
}
