#include "librariesreq.h"
#ifndef ACTIONS_C


#include "globalfunc.c"

char *commands[10]={"mkdir ", "touch ", "cp ", "mv ", "cp ", "rename", "exec", "wine", "cmake ", "make "};

void Createdir(){
    char makeadir[256] = "";
    char newdir[10]= "/";
    char cndir[256];
    strcat(makeadir, commands[0]);
    strcat(makeadir, combinedDir);
    mvprintw(1, (x/4+1), "New Directory Name:");
    getstr(cndir);
    refresh();
    strcat(makeadir, newdir);
    strcat(makeadir, cndir);
    system(makeadir);
    }

void CreateFile(){
    char makeafile[256];
    char newfile[256];
    strcat(makeafile, commands[1]);
    strcat(makeafile, combinedDir);
    scanw("/%s", &newfile);
    strcat(makeafile, newfile);
    system(makeafile);
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
    }
    commandcall=FALSE;
}
}
#endif // !ACTIONSC
