#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define READ_END 0
#define WRITE_END 1

int main() {
  int ptocpipe[2];
  pipe(ptocpipe);
  if(0 == fork()) {
    close(ptocpipe[WRITE_END]); // make it half-duplex for POSIX compatibility
    char recv_msg[10];
    read(ptocpipe[READ_END], recv_msg, 8); // doesn't block. idk why
    printf("msg received: %s\n", recv_msg);
    close(ptocpipe[READ_END]);
    exit(0);
  }
  else {
    close(ptocpipe[READ_END]);
    char send_msg[10] = "abcde";
    write(ptocpipe[WRITE_END], send_msg, 4);
    close(ptocpipe[WRITE_END]);
  }
  wait(NULL);
  return 0;
}
