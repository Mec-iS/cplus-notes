/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // this is missing the pointer cast type
    // compiler cannot know the size of void
    void *p = malloc(sizeof(int));

    printf("address=%p, value=%d\n", p, *p);

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // this is missing the pointer cast type
    int* p = (int*)malloc(sizeof(int));

    printf("address=%p, value=%d\n", p, *p);

    return 0;
}
