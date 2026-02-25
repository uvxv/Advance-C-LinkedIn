#include <stdio.h>

int main()
{
	// in c everyting is dataflow go through a a some sort of file streams

	printf("'stdin' file number is %d\n",fileno(stdin)); // get the file number for standard input
	printf("'stdout' file number is %d\n", fileno(stdout)); // get the file number for standard output
	printf("'stderr' file number is %d\n", fileno(stderr));
	return(0);
}
