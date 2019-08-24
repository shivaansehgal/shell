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
char hist[22][1000];
int histindx=0,totk=0;

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
void history(int comc);

int main()
{
    getcwd(adir,1000);
    getcwd(odir,1000);
    uname(&buffer);
    while(1)
    {
        printline();
        scanf("%[^\n]s",input);
        strcpy(faltu,input);
        char* tok;
        const char del[4]=";";
        tok = strtok(input,del);
        int comandCount=0;
        while(tok != 0)
        {
            //printf(" %s\n", tok);
            strcpy(inp[comandCount],tok);
            comandCount++;
            tok = strtok(0,del);
        }
        for(int i=0;i<comandCount;i++)
        {
            char* bre;
            int  status;
            const char sp[4]=" ";
            strcpy(hist[histindx],inp[i]);
            histindx++;
            histindx%=20;
            totk=0;
            bre = strtok(inp[i],sp);
            int comc=0;
            while(bre != 0)
            {
                strcpy(comand[comc],bre);
                comc++;
                bre = strtok(0,sp);
            }

            if(strcmp(comand[0],"echo")==0)
            {
                for(int i=1;i<comc;i++)
                {
                    printf("%s ",comand[i]);
                }
                printf("\n");
            }
            else if(strcmp(comand[0],"pwd")==0)
            {
                pwd();
            }
            else if(strcmp(comand[0],"cd")==0)
            {
                if(comc==1)
                {
                    strcpy(adir,odir);
                }
                else
                {
                    cd(comand[1]);
                }
            }
            else if(strcmp(comand[0],"ls")==0)
            {
                ls(comc);
            }
            else if(strcmp(comand[0],"pinfo")==0)
            {
                pinfo(comc);
            }
            else if (strcmp(comand[0],"history")==0)
            {
                history(comc);
            }
            else if (strcmp(comand[comc-1],"&")!=0)
            {
                bakisab(comc);
            }
            else
            {
                back(comc);
            }
        }
        getchar();
    }
}

void history(int comc)
{
    if(comc==1)
    {
        for(int i=histindx;i>histindx+10;i++)
        {
          printf("%s\n",hist[i%20]);
        }
    }
}
