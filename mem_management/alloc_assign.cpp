/*
Memory allocated with malloc or calloc is not subject to the familiar rules
 of variables in their respective scopes. This means that they exist
 independently of block limits until they are released again or the program
 is terminated. However, **the pointers which refer to such heap-allocated memory
 are created on the stack and thus only exist within a limited scope**.
 As soon as the scope is left, the pointer variable will be lost - but not the
 heap memory it refers to.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int*)malloc(3 * sizeof(int));

    // allocated memory can be used as arrays are
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    printf("address=%p, value=%d\n", p[0], p[0]);
    printf("address=%p, value=%d\n", p[1], p[1]);
    printf("address=%p, value=%d\n", p[2], p[2]);

    struct MyStruct {
      int i;
      double d;
      char a[5];
    };

    MyStruct *q = (MyStruct*)calloc(4,sizeof(MyStruct));
    q[0].i = 1;
    q[0].d = 3.14159;
    q[0].a[0] = 'a';

    q[1].i = 2;
    q[1].d = 3.14159;
    q[1].a[0] = 'b';

    free(p);
    free(q);

    return 0;
}
