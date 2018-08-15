#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define READ_END 0
#define WRITE_END 1

int main() {
  int pipe1[2];
  pipe(pipe1);
  char send_msg[10] = "abcd";
  write(pipe1[WRITE_END], send_msg, strlen(send_msg));
  close(pipe1[WRITE_END]);
  char recv_msg[10];
  read(pipe1[READ_END], recv_msg, 1); // blocking if WRITE_END is not closed
  printf("%s\n", recv_msg);
//  close(pipe1[READ_END]);
  read(pipe1[READ_END], recv_msg, 2);
  printf("%s\n", recv_msg);
  return 0;
}
