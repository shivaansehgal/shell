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

extern void pwd()
{
    printf("%s\n",adir);
}
