#include<stdio.h>

#define IN  1    /* inside a word */
#define OUT 0    /* outside a word */

/* count lines, word, and characters in input */
main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
         if (c == ' ' || c == '\n' || c == '\t') {
              if (state == IN) {
                   putchar('\n');         /* finish the word */
                   state = OUT;
              }
          } else if (state == OUT) {
               state = IN;                /* begining of word */
               putchar(c);
          } else                          /* inside a word */
               putchar(c);
         }
   } 
}
