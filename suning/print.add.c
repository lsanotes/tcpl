#include<stdio.h>

main()
{
    int a = 10;
    int b = 0;
    int c = 0;
    int d = 0;
    
    b = a++;
    c = ++a;
    d = 10*a++;

    printf("b,c,d: %d,%d,%d\n",b,c,d);
    return 0; 
}
