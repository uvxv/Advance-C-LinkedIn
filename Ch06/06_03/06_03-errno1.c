#include <stdio.h>
/*
 - When an error occured, the global errno constant is set to a specific value, 
   which is helps to identify the error more specifically
 - This appraoch is way better that a fuction just returns with -1
*/
int main()
{
    int r;

    r = rename("this.txt","that.txt");
    if( r == -1 )
    {
        fprintf(stderr,"File renaming error\n");
        return(1);
    }
    puts("File renamed");

    return(0);
}
