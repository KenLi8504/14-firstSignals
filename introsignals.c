#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>


static void sighandler(int signo){
  if (signo == SIGINT){
    int file = open("file.data",O_CREAT|O_WRONLY|O_APPEND,0644);
    if (file == -1){
      printf("Error: %s\n",strerror(errno));
    }
    char output[] = "Program exited due to SIGINT\n";
    int status = write(file,output,sizeof(output));
    exit(0);
    if (status == -1){
      printf("Error: %s\n",strerror(errno));
    }
  }
  if (signo == SIGUSR1){
    int parentPid = getppid();
    printf("%d\n",parentPid);
  }
}

int main(){
  while (1){
    signal(SIGINT,sighandler);
    signal(SIGUSR1,sighandler);
    int pid = getpid();
    printf("%d\n",pid);
    sleep(1);
  }
  return 0;
}
