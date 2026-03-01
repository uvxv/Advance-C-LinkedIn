#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FD_READ 0
#define FD_WRITE 1

// writing thread
void *w_thread (void *ptr)
{
    int fd;
    char *message = "hello people\n";
    
    fd = *(int *)ptr; // cast the ptr

    write(fd, message, strlen(message)+1);

  return NULL;
}

// reading thread
void *r_thread (void *ptr)
{
  int fd;
  char buffer[BUFSIZ];

  fd = *(int *)ptr;
  read(fd,buffer, BUFSIZ); // read the file, dont try to type cast further.
  printf("Read thread read: %s\n", buffer);

  return NULL;
}

int main()
{
  int fd[2];
  pthread_t ptd;
  int p_result, t1_result, t2_result;

  p_result = pipe(fd);

  if(p_result != 0)
  {
    perror("Pipe");
    exit(1);
  }

  t1_result = pthread_create(&ptd, 0, w_thread, (void *)&fd[FD_WRITE]);
  t2_result = pthread_create(&ptd, 0, r_thread, (void *)&fd[FD_READ]);

  if(t1_result != 0 || t2_result != 0)
  {
    perror("Thread");
    exit(1);
  }

  /* wait here */
  getchar();

  return (0);
}