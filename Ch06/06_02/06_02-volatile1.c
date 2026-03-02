#include <stdio.h>
/*
 - volatile forces teh cpu to fethch data form the memory in each access to a particular var
 - It prevent compiler to optimize a particular defined variable 
*/
void memzero(void *b, int len)
{
    volatile int x;
    char *a;

    a = (char *)b;
    for( x=0; x<len; x++)
        *(a+x) = 0;
}

int main()
{
    struct human {
        char name[32];
        int age;
        float weight;
    } my;

    memzero(&my,sizeof(struct human));

    return(0);
}
