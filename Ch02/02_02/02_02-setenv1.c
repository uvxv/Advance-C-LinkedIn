#include <stdio.h>
#include <stdlib.h>

/*
 - Modifying the environment in a program dosent affect the terminal's environment
 - Each program carries its own copy of the environment
*/
int main()
{
    const char newvar[] = "language";
    const char value[] = "C";

    printf("Setting variable '%s' to '%s'\n",
            newvar,
            value
          );
    setenv(newvar,value,0);

    printf("The '%s' variable equals '%s'\n",newvar,getenv(newvar) );

    return 0;
}  
