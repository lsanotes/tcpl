#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length */

int mygetline (char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";	/* pattern to search for */

/* find all lines matching pattern */
main()
{
	char line[MAXLINE];
	int found = 0;
	int index = 0;

	while (mygetline(line, MAXLINE) > 0) {
		if ( (index = strrindex(line, pattern)) >= 0) {
			printf("%sIndex: %d", line,index);
			found++;
		}
	}
	return found;
}

/* mygetline:  get line into s, return length */
int mygetline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strrindex:  return rightmost index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
	int i, j, k,pos;

	pos = -1;	
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			pos = i;
	}
	return pos;
}
