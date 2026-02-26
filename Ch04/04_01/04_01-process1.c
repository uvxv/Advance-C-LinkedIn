#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
    pid_t process;
    pid_t parent;

    process = getpid(); // current process id
    parent = getppid();

    kill(process, SIGHUP); // the process will be killed 
    // but because no handler is designed to catch the return from kill, the kernel excutes teh default handler
    // and the program hangs up

    printf("This program's process ID is %d\n",process);
    printf("The parent process of %d is %d ", process, parent);
    return 0;
}
