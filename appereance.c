#include "librariesreq.h"
#ifndef APPEREANCE_C
#include "globalfunc.c"


void genprint(){

    char* decoration1= "━";
    char* decoration2= "│";
    char* decoration3= "┯";
    char* decoration4= "┷";
    char* corner1= "┍";
    char* corner2= "┑";
    char* corner3= "┕";
    char* corner4= "┙";

    definitions();
    //Corners

        refresh();
    for(int i= 0; i<x; i++){
        mvprintw(0,i,"%s", decoration1);
        mvprintw(y,i,"%s",decoration1);

    }
    for(int i= 0; i<y; i++){
        mvprintw(i,0,"%s", decoration2);
        mvprintw(i,x/4,"%s", decoration2);
        mvprintw(i, x, "%s", decoration2);
    }
    mvprintw(0, x/4, "%s", decoration3);
    mvprintw(y, x/4, "%s", decoration4);

    mvprintw(0,0, "%s", corner1);
    mvprintw(0,x, "%s", corner2);
    mvprintw(y,0, "%s", corner3);
    mvprintw(y,x, "%s", corner4);
}


void FolderIcon(){
    
}
#endif 