#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 2048

int main()
{
	const char filename[] = "sonnet18.txt";
	int fdest,x;
	char buffer[SIZE];
	size_t r;

	/* low-level open the file, read-only */
	fdest = open(filename,O_RDONLY);
	if( fdest==-1 )
	{
		fprintf(stderr,"Unable to open %s\n",filename);
		return(1);
	}

	/* output file details */
	printf("File descriptor for %s is %d\n",filename,fdest);
	puts("File contents:\n");
	r = read( fdest,buffer,SIZE); // read from file, store in buffer, the number of byte to read, return the no. of bytes read
	for( x=0; x<r; x++ )
		putchar( buffer[x] );

	/* close-up */
	close(fdest);
	return 0;
} 
