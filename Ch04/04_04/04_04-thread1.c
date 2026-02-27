#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
/*
 - Threads offer a more elegent way than forking to have a program complete multiple tasks.
 - Opreates independently
 - Can be manipulated from the main program
 - Data can be exchanged between threads
*/
void *thread_funct(void *a)
{
    const int loop=8;
    int x;

    for( x=0; x<loop; x++ )
    {
        printf("%s\n",(char *)a);
        sleep(1);
    }

    return(NULL);
}

int main()
{
    char buffer[BUFSIZ];
    char *string = "this string passed the to seconf thread";
    int tresult;
    pthread_t thd;

    /* spawn the new thread */
    tresult = pthread_create( &thd, NULL, thread_funct, string); // thread_func in a seperate thread
    if( tresult!=0 )
    {
        perror("Thread");
        exit(1);
    }

    /* prompt for your name */
    printf("What is your name? ");
    fgets(buffer,BUFSIZ,stdin);
    printf("Hello, %s",buffer);

    return(0);
}
