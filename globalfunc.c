#include "librariesreq.h"
#ifndef GLOBALFUNC_C

//Int Variables

//CharStrings 
char* directory[];

//Char Variables
char cdcom= "cd";


void definitions()
{
 setlocale(LC_ALL, "");
 initscr();
 start_color();
 keypad(stdscr,TRUE);

 init_pair(PAIR1, COLOR_WHITE, COLOR_BLACK);
 init_pair(PAIR2, COLOR_BLACK, COLOR_WHITE);
}

void blackout()
{
 for(int i=-2; i<=y; i++){
   for(int j=-2; j<=x2+2; j++){
      PAIR1;
      mvprintw(i, j, " ");
        }
    }
}

void callsystem(char, char*){
 
char error= ("bash: %s No such file or directory", char*);
char truedir=  ("bash: %s Is a directory", char*)

 FILE* IsDir = popen(char*, "r");
 if (Isdir==error){
 printw("%s",error);
 break;
 }
 else if (Isdir==truedir){
 system((char)&&(char*));
 }
}
#endif