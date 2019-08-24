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

struct utsname buffer;//for user name
char input[1000],inp[100][1000],comand[100][1000],adir[1000],ndir[1000],odir[1000],list[500][1000],faltu[1000];
char pidint[100];

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

extern void printline()
{
    printf("<");
    printf("\033[1;31m");
    printf("%s",buffer.nodename);
    printf("\033[0m");
    printf("@");
    printf("\033[1;31m");
    printf("%s",buffer.sysname);
    printf("\033[0m");
    printf(":");
    printf("\033[1;34m");
    int fl=0;
    for(int i=0;i<strlen(odir);i++)
    {
        if(adir[i]!=odir[i])
        {
            fl=1;
            break;
        }
    }
    if(fl==0)
    {
        printf("~");
        for(int i=strlen(odir);i<strlen(adir);i++)
        {
            printf("%c",adir[i]);
        }
    }
    else
    {
        printf("%s",adir);
    }
    printf("\033[0m");
    printf("> ");
}
