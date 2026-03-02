#include <stdio.h>
#include <stdlib.h>

void all_done(void){
	puts("The program ended...!");
}

int main()
{
	atexit(all_done); // one time config
	// typically this can be usefull in the context of cleanups

	puts("I enjoy being a program");
	puts("And now I'm done");

	return 0;
}
