#include "librariesreq.h"
#ifndef ACTIONS_C
#include "globalfunc.c"


char *commands[10]={"mkdir ", "touch ", "cp ", "mv ", "cp ", "mv ", "./", "wine ", "cmake ", "make "};
char copyfrom[256];
char cd[8]= "cd ";
char cding[256];
char joint[500];

bool ccopy= FALSE;
bool ccut= FALSE;

void CdCommand(){

char ampersons[8]= " && ";

memset(joint,0, sizeof(joint));
strcat(joint, cd);
strcat(joint, combinedDir);
strcat(joint, ampersons);

}

void Createdir(){
    char makeadir[256] = "";
    char newdir[10]= "/";
    char cndir[256];
    memset(makeadir, 0, sizeof(makeadir));
    strcat(makeadir, commands[0]);
    strcat(makeadir, combinedDir);
    mvprintw(1, (x/4+1), "New Directory Name: ");
    echo();
    getstr(cndir);
    noecho();
    refresh();
    strcat(makeadir, newdir);
    strcat(makeadir, cndir);
    system(makeadir);
    }

void CreateFile(){
    char makeafile[256]= "";
    char newdir[10]= "/";
    char newfile[256]="";
    strcat(makeafile, commands[1]);
    strcat(makeafile, combinedDir);
    strcat(makeafile, newdir);
    mvprintw(1, (x/4+1), "New File Name: ");
    echo();
    getstr(newfile);
    noecho();
    strcat(makeafile, newfile);
    system(makeafile);
}

void Copy(){
ccopy=TRUE;
ccut=FALSE;
char newdir[10]= "/";

memset(copyfrom, 0, sizeof(copyfrom));
 char *newline = strchr(copyfrom, '\n');
    if (newline) *newline = '\0';
strcat(copyfrom, combinedDir);
strcat(copyfrom, newdir);
strcat(copyfrom, options[invertedcordinates]);

}

void Cut(){
ccopy=FALSE;
ccut=TRUE;
char newdir[10]= "/";

memset(copyfrom, 0, sizeof(copyfrom));
 char *newline = strchr(copyfrom, '\n');
    if (newline) *newline = '\0';
strcat(copyfrom, combinedDir);
strcat(copyfrom, newdir);
strcat(copyfrom, options[invertedcordinates]);
}

void Paste(){
if(ccopy==TRUE){
char copying[256]="";
char space[8]= " ";

 char *newline = strchr(copying, '\n');
    if (newline) *newline = '\0';
strcat(copying, commands[2]);
strcat(copying, copyfrom);
strcat(copying, space);
strcat(copying, combinedDir);

system(copying);

memset(copying, 0, sizeof(copying));

}

if(ccut==TRUE){
char copying[256];
char space[8]= " ";

strcat(copying, commands[3]);
strcat(copying, copyfrom);
strcat(copying, space);
strcat(copying, combinedDir);
system(copying);
memset(copying, 0, sizeof(copying));
}


}

void Rename(){


char renaming[256]= "";
char rename[256];
char space[8]= " ";

char ampersons[8]= " && ";
memset(renaming, 0, sizeof(renaming));
memset(joint, 0, sizeof(joint));
memset(cding, 0, sizeof(cding));
 char *newline = strchr(renaming, '\n');
    if (newline) *newline = '\0';
strcat(renaming, commands[5]);
strcat(cding, cd);
strcat(cding, combinedDir);
strcat(renaming, options[invertedcordinates]);
 mvprintw(1, (x/4+1), "Rename To: ");
echo();
getstr(rename);
noecho();
strcat(renaming, space);
strcat(renaming, rename);
strcat(joint, cding);
strcat(joint, ampersons);
strcat(joint, renaming);
system(joint);
}

void Execute(){
char exec[256]= "";
char ampersons[8]= " && ";

memset(cding, 0, sizeof(cding));
memset(exec, 0, sizeof(exec));
memset(joint, 0, sizeof(joint));

strcat(cding, cd);
strcat(cding, combinedDir);

strcat(exec, commands[6]);
strcat(exec, options[invertedcordinates]);

strcat(joint, cding);
strcat(joint, ampersons);
strcat(joint, exec);

system(joint);
}

void Wine(){

char wine[256]= "";

memset(cding, 0, sizeof(cding));
strcat(cding, cd);
strcat(cding, combinedDir);

strcat(wine, commands[7]);
strcat(wine, options[invertedcordinates]);

system(wine);
}

void Cmake(){
    char ampersons[8]= " && ";

memset(joint, 0, sizeof(joint));

strcat(joint, cd);
strcat(joint, combinedDir);
strcat(joint, ampersons);
strcat(joint, commands[8]);
strcat(joint, combinedDir);

system(joint);
}

void Make(){
   char ampersons[8]= " && ";

memset(joint,0, sizeof(joint));

strcat(joint, cd);
strcat(joint, combinedDir);
strcat(joint, ampersons);
strcat(joint, commands[9]);
strcat(joint, combinedDir);

system(joint);
}

void MicroTerminal(){
char Comands[564];

memset(Comands,0,sizeof(Comands));
CdCommand();
 mvprintw(1, (x/4+1), "$ ");
echo();
getstr(Comands);
noecho();

strcat(joint, Comands);

system(joint);
}

void Actioncall(){
if(commandcall==TRUE){
    switch(actualaction){
        case 0:
        Createdir();
        break;

        case 1:
        CreateFile();
        break;

        case 2: 
        Copy();
        break;

        case 3: 
        Cut();
        break;

        case 4:
        Paste();
        break;
        
        case 5:
        Rename();
        break;
 
        case 6:
        Execute();
        break;

         case 7:
        Wine();
        break;


         case 8:
        Cmake();
        break;


         case 9:
        Make();
        break;

        case 10:
        MicroTerminal();
        break;

    }

    commandcall=FALSE;
    clear();
}
}

#endif // !ACTIONSC
