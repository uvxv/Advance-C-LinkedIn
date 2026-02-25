#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 - storage location in memeory
 - The OS used the environment to store variables and values
 - Set the system parameter and provide other information
 - Other vital information
 */
int main()
{
    extern char **environ;

    while( *environ )
    {
        printf("%s\n",*environ);
        environ++;
    }

    return 0;
} 
