#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern struct utsname buffer;//for user name
extern char input[1000],inp[100][1000],comand[100][1000],adir[1000],ndir[1000],odir[1000],list[500][1000],faltu[1000];
extern char pidint[100];

void printline();
void echo();
void pwd();
void cd(char* inpp);
int checkdir();
void ls(int comc);
int rd();
void printinfo(char* path,char* list);
void pinfo(int comc);
void strrevpid();
void bakisab(int comc);
void back(int comc);
void sig_handler(int signum)
{
  int pid = waitpid(-1, NULL, WNOHANG);
  if(pid > 0){
    int lulu=0;
  }
}

extern void bakisab(int comc)
{
    char *args[1000];
    for(int i=0;i<comc;i++)
    {
        args[i]=comand[i];
    }
    args[comc]=NULL;
    pid_t pid;
    if ((pid = fork()) < 0)
    {
            printf("*** ERROR: forking child process failed\n");
            exit(1);
    }
    else if (pid == 0)
    {
          if (execvp(args[0], args) < 0)
          {
                printf("*** ERROR: exec failed\n");
                exit(1);
            }
          //  printf("pid=%d",pid);
        }
      else
        {
          wait(NULL);
        }


}

extern void back(int comc)
{
  char *args[1000];
  for(int i=0;i<comc;i++)
  {
      args[i]=comand[i];
  }
  args[comc]=NULL;
  pid_t cid = fork();
    if(cid==0)
    {
          setpgid(0,0);
          execvp(args[0],args);
    }
    else
    {
          printf("pid=%d\n",cid );
          signal(SIGCHLD, sig_handler);
    }

}
