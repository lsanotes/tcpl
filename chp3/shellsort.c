#include <stdio.h>

/*shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
            {
                temp = v[j]; 
                v[j] = v[i];
                v[i] = temp;
            }
}

void main()
{
    int v[] = {1,2,3,33,0,5};
    shellsort(v,6) ; // the sorted array{0,1,33,2,3,5} is wrong, why?
    int i = 0;
    for(;i<6;i++)
        printf("%d\t", v[i]);
}
