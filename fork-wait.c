#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  pid_t child_pid = fork();
  if(child_pid < 0) {
    perror("fork() error");
    exit(-1);
  }
  else if (child_pid == 0) { // child_pid is 0 in child process
    printf("Child process - %i\n", getpid()); 
    printf("Parent process - %i\n", getppid()); 
    execl("usr/bin/vim", "vim", "fork-wait312.c", NULL); // execl replaces current process
    perror("execl failed"); // printed only if execl fails
  }
  else {
    printf("Main process - %i\n", getpid()); 
    printf("parent of Main process - %i\n", getppid()); 
    wait(NULL);
    printf("child process exited\n");; 
  }
  return 0;
}
