#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	/* template must end in six Xs */
	char template[] = "acXXXXXX";
	/* ten 9-char buffers */
	char* name[9];
	int fd,x;

	for(x=0; x<10; x++ )
	{
		/* copy the template */
		strcpy(name,template); 
		// the above is beacause each time the mkstemp is called ite replaces the template with name of file created
		// so next time when creatign it result in duplicate.
		fd = mkstemp(name);		/* returns file descriptor */
		if( fd==-1 )
		{
			perror("msktemp()");
			return 1;
		}
		printf("Temporary file %s created\n",name);
	}

	/* clean-up */
	close(fd);
	return 0;
}
