/*
Realloc behaviour:
Depending on the compiler, the reserved memory area is either (a) expanded
 or reduced internally (if there is still enough free heap after the previously
 reserved memory area) or (b) a new memory area is reserved in the desired
 size and the old memory area is released afterwards.

The data from the old memory area is retained, i.e. if the new memory area is
 larger, the data will be available within new memory area as well. If the new
 memory area is smaller, the data from the old area will be available only up
 until the site of the new area - the rest is lost.

realloc will not erase memory but merely mark it as "available" for future
 allocations. If trying to be accessed it may incur in SEGFAULT because of
 dangling pointers.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // reserve memory for two integers
    int *p = (int*)malloc(2*sizeof(int));
    p[0] = 1; p[1] = 2;

    // resize memory to hold four integers
    p = (int*)realloc(p,4*sizeof(int));
    p[2] = 3; p[3] = 4;

    // resize memory again to hold two integers
    p = (int*)realloc(p,2*sizeof(int));

    printf("address=%p, value=%d\n", p+0, *(p+0)); // valid
    printf("address=%p, value=%d\n", p+1, *(p+1)); // valid

    // !!! UNDEFINED BEHAVIOUR !!!
    printf("address=%p, value=%d\n", p+2, *(p+2)); // INVALID
    printf("address=%p, value=%d\n", p+3, *(p+3)); // INVALID

    return 0;
}
