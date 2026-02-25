#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  char *term;
	FILE *tout;

		// remember everithing is a file
    term = ttyname(STDOUT_FILENO); // get the file path for STD_OUT
    printf("This is terminal %s\n",term);

	/* open the terminal as a file */ 
	tout = fopen(term,"w"); // Open that file
	if( tout==NULL )
	{
		fprintf(stderr,"Unable to open %s\n",term);
		exit(1);
	}

	/* output text */
	fprintf(tout,"Hello to terminal %s\n",term); // fprintf to that OUTPUT

	/* close-up */
	fclose(tout);
    return(0);
}
 