#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

void sighandler(int signum){
  if (signum == SIGINT){
    int fd = open("signals", O_CREAT | O_WRONLY, 0644);
    write(fd, "Program exited due to SIGINT\n", 30);
    close(fd);
    printf("Signal Caught %d\n", signum);
    exit(0);
  }
  if (signum == SIGUSR1){
    printf("PID of the parent process:%d\n", getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while (10){
    printf("Can't stop, won't stop, pid: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
