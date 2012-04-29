#include<stdio.h>

#define IN  1    /* inside a word */
#define OUT 0    /* outside a word */

main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;         
        }
    } 
    if (nc != 0) // this sector was added by Robert Liu to solve a bug
        ++nl;
    else 
	    nl = nl;
        printf("%d %d %d \n", nl, nw, nc);
}
