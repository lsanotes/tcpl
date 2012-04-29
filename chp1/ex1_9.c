#include<stdio.h>

#define NONEBLANK 'a'

/* replace string of blanks with one blank */
main()
{
     int c, lastc;

     lastc = NONEBLANK;
     while ((c = getchar()) != EOF) {
    	 if(c != ' ') 
		 putchar(c);
	 else if (lastc != ' ')
		 putchar(c);
	 lastc = c;
     }
}
