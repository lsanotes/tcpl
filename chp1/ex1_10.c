#include<stdio.h>

/* replace tabs and backspaces with visible characters */
main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') 
	        printf("\\t");
        else if (c == '\b')     // It doesn't work 
	        printf("\\b");
        else if (c == '\\') 
	        printf("\\\\");
	    else 
	        putchar(c);
   }
}
