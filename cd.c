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

extern void cd(char* inpp)
{
    if(rd(inpp))
    {
        for(int i=0;i<=strlen(ndir);i++)
        {
            adir[i]=ndir[i];
        }
    }
}

extern int rd(char* inpp)
{
    /*
     *ALLOWED:
     cd ~/sehgal/shivaan
     cd ./xyz/abc
     cd ..
     cd ../../../shivaan
     *NOT ALLOWED
     cd ./../cs
     cd ~/shivaan/../shivaan
     */
    if(inpp[0]=='~')
    {
        for(int i=0;i<strlen(odir);i++)
        {
            ndir[i]=odir[i];
        }
        for(int i=strlen(odir),j=1;j<=  strlen(inpp);i++,j++)
        {
            ndir[i]=inpp[j];
        }
        return checkdir();
    }
    else if(inpp[0]=='.')
    {
        if(inpp[1]=='/')
        {
            for(int i=0;i<strlen(adir);i++)
            {
                ndir[i]=adir[i];
            }
            for(int i=strlen(adir),j=1;j<=strlen(inpp);i++,j++)
            {
                ndir[i]=inpp[j];
            }
            return checkdir();
        }
        else if(inpp[1]=='.')
        {
            for(int i=0;i<=strlen(adir);i++)
            {
                ndir[i]=adir[i];
            }
            int c=0,p=0,l;
            for(p=0;inpp[p]=='.'||inpp[p+1]=='.';p++)
            {
                if(inpp[p]=='.')
                {
                    c++;
                }
            }
            c/=2;
            for(l=strlen(ndir)-1;c>0&&l>=0;l--)
            {
                if(ndir[l]=='/')
                {
                    c--;
                }
            }
            for(int i=l+1;p<=strlen(inpp);p++,i++)
            {
                ndir[i]=inpp[p];
            }
            return checkdir();
        }
    }
}

int checkdir()
{
    struct dirent *de;
    DIR *dr = opendir(ndir);
    if (dr == NULL)
    {
        perror("Error: ");
        return 0;
    }
    else
    {
        return 1;
    }
}
