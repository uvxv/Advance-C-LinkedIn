#include <stdio.h>
/*
 - Created enumarated set of integer constants
 - A series of constants numbered sequentially , (0,1,2)
 - Constants seperated by commas
*/
int main()
{
    enum {FALSE,TRUE};

    printf("FALSE is %d\n",FALSE);
    printf("TRUE is %d\n",TRUE);

    return(0);
}
