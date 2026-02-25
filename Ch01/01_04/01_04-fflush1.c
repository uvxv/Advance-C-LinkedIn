#include <stdio.h>

int main()
{
    const char normal[] = "stdout";
    const char error[] = "stderr ";

    fprintf(stdout,normal);
    fflush(stdout); // flush(force tranfer immediately), when para in null then flush all opened buffer
    // exit() does the same
    fprintf(stderr,error); // no buffer for stderr
    fprintf(stdout,normal); // line buffered or full buffered (output when program quits)
    fprintf(stderr,error);
    fprintf(stdout,normal);
    fprintf(stderr,error);
	putchar('\n');

    return(0);
}
