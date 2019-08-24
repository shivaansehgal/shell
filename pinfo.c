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

extern void pinfo(int comc)
{
    int pid;
    char pi[100]="/proc/";
    if(comc==1)
    {
        pid=getpid();
    int temp=pid;
    int ptr=0;
    while(temp)
    {
        pidint[ptr]=48+temp%10;
        temp/=10;
        ptr++;
    }
    pidint[ptr]='\0';
    strrevpid();
    printf("%s\n",pidint );
    strcat(pi,pidint);
  }
  else
  {
    printf("PID-- %s\n",comand[1] );
    strcat(pi,comand[1]);
  }
    char pidpath[100];
    char dusara[100];
    strcpy(dusara,pi);
    strcat(pi,"/maps");
    strcat(dusara,"/stat");
    FILE *fptr;
    fptr = fopen(pi, "r");
    // printf("%s\n",pi  );
    if (fptr == NULL)
    {
        printf("No such process \n");
        return;
    }
    char fl[1000];
    char ag[100][200];
    fscanf(fptr,"%[^\n]", fl);
    char* bre;
    const char sp[4]=" ";
    bre = strtok(fl,sp);
    int comcc=0;
    while(bre != 0)
    {
        strcpy(ag[comcc],bre);
        comcc++;
        bre = strtok(0,sp);
    }
    printf("Path--%s\n",ag[5] );
    fptr=fopen(dusara,"r");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
    }
    fscanf(fptr,"%[^\n]", fl);
    bre = strtok(fl,sp);
    comcc=0;
    while(bre != 0)
    {
        strcpy(ag[comcc],bre);
        comcc++;
        bre = strtok(0,sp);
    }
    printf("Process Status -- %s\n",ag[2]);
    printf("memory ​ --%s\n",ag[22] );
}


void strrevpid()
{
    int nn=strlen(pidint);
    for(int i=0;i<nn/2;i++)
    {
        char lul=pidint[i];
        pidint[i]=pidint[nn-1-i];
        pidint[nn-1-i]=lul;
    }
}
