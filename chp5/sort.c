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

void swap(int *px, int *py) /* interchange *px and *py */
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
    int i, last;

    if (left >= right) /* do nothing if array contains fewer than */
	return;	       /* two elements*/
    swap(&v[left], &v[(left + right)/2]);
    last = left;			  /* to v[0] */
    for ( i = left+1; i <= right; i++)	/* patition */
	if (v[i] < v[left])
	    swap(&v[++last], &v[i]);
}
main()
{
   int unsorted[SIZE];
   int n;

   for (n = 0; n < SIZE && getint(&unsorted[n]) != EOF; n++)
       ;
   for (n = 0; n < SIZE; n++)
       printf("%d", unsorted[n]);
}
