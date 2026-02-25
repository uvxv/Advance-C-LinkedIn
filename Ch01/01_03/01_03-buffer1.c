#include <stdio.h>

int main()
{
    char buffer[BUFSIZ]; // set default in the lib
    setvbuf(stdout, buffer, _IOFBF, BUFSIZ); // change new line bufer to, block buffer, by def, stdout is line buffered
    puts("Hold it!");
    puts("Hold it!");
    puts("Go!");
    getchar();
    puts("Thank you.");

    return(0);
} 
