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

extern void ls(int comc)
{
    if(comc==1)//ls
    {
        struct dirent *de;
        DIR *dr = opendir(adir);
        if (dr == NULL)  // opendir returns NULL if couldn't open directory
        {
            perror("Error: ");
            return;
        }
        else
        {
            while ((de = readdir(dr)) != NULL)
            {
                if((de->d_name)[0]!='.')
                {
                    printf("%s\n", de->d_name);
                }
            }
        }
    }

    else if(comand[1][0]=='-')
    {
        if(strcmp(comand[1],"-a")==0)//ls -a
        {
            struct dirent *de;
            DIR *dr = opendir(adir);
            if (dr == NULL)  // opendir returns NULL if couldn't open directory
            {
                perror("Error: ");
                return;
            }
            else
            {
                while ((de = readdir(dr)) != NULL)
                {
                    printf("%s\n", de->d_name);
                }
            }

        }
        else
        {
            struct dirent *de;
            DIR *dr = opendir(adir);
            if (dr == NULL)  // opendir returns NULL if couldn't open directory
            {
                perror("Error: ");
                return;
            }
            else
            {
                int filecount=0;
                while ((de = readdir(dr)) != NULL)
                {
                    strcpy(list[filecount],de->d_name);
                    filecount++;
                }
                char path[1000];
                for(int i=0;i<filecount;i++)
                {
                    strcpy(path,adir);
                    strcat(path,"/");
                    strcat(path,list[i]);
                    if(strcmp(comand[1],"-l")==0)
                    {
                        if(list[i][0]!='.')
                        {
                            printinfo(path,list[i]);

                        }
                    }
                    else
                    {
                        printinfo(path,list[i]);
                    }
                }

            }
        }
    }

    else if(comc==2)// ls<dirname>
    {
        if(rd(comand[1]))
        {
            struct dirent *de;
            DIR *dr = opendir(ndir);
            if (dr == NULL)  // opendir returns NULL if couldn't open directory
            {
                perror("Error: ");
                return;
            }
            else
            {
                while ((de = readdir(dr)) != NULL)
                {
                    if((de->d_name)[0]!='.')
                    {
                        printf("%s\n", de->d_name);
                    }
                }
            }
        }
    }
}

void printinfo(char* path,char* list)
{
    struct stat buf;
    stat(path, &buf);
    if (S_ISREG(buf.st_mode))
    {
        printf("-");
    }
    else if (S_ISDIR(buf.st_mode))
    {
        printf("d");
    }

    if (S_IRUSR & buf.st_mode)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if (S_IWUSR & buf.st_mode)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if (S_IXUSR & buf.st_mode)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }
    if (S_IRGRP & buf.st_mode)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if (S_IWGRP & buf.st_mode)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if (S_IXGRP & buf.st_mode)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }
    if (S_IROTH & buf.st_mode)
    {
        printf("r");
    }
    else
    {
        printf("-");
    }
    if (S_IWOTH & buf.st_mode)
    {
        printf("w");
    }
    else
    {
        printf("-");
    }
    if (S_IXOTH & buf.st_mode)
    {
        printf("x");
    }
    else
    {
        printf("-");
    }
    printf("  ");
    printf("%d", buf.st_nlink);
    printf(" ");
    printf("%d", buf.st_uid);
    printf(" ");
    printf("%d", buf.st_gid);

    printf("%13d ", buf.st_size);

    printf("%s", ctime(&(buf.st_mtime))+4);
    printf(" %s\n",list );
}
