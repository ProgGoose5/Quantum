#include "librariesreq.h"

#ifndef GLOBALFUNC_C

//constants
#define PAIR1 1
#define PAIR2 2
#define PAIR3 3
//Int Variables
int x, y, quantity, actualfile, filelayout, cou;
int NumDir= 0;
//CharStrings 
char* directory[]={"","/home"};
//Char Variables
char* cdcom= "cd ";
char* options[1000] = {NULL};


void definitions()
{
  setlocale(LC_ALL, "");
  initscr();
  start_color();
  keypad(stdscr,TRUE);
  noecho();

  actualfile=0;
  filelayout= 5;

  init_pair(PAIR1, COLOR_WHITE, COLOR_BLACK);
  init_pair(PAIR2, COLOR_BLACK, COLOR_WHITE);
  init_pair(PAIR3, COLOR_WHITE, COLOR_YELLOW);
}

void blackout()
{
 for(int i=-2; i<=y; i++){
   for(int j=-2; j<=x+2; j++){
      PAIR1;
      mvprintw(i, j, " ");
        }
    }
}

void Resizing(){
  //BASH COMMANDS
  char lines[12]= "tput lines"; 
  char columns[12]="tput cols"; 
  //Defining variables to copy the result of the commands
  int lns, cols;
  FILE* lines_fp = popen(lines, "r"); //Calls the command into Bash and Reads the results.
  FILE* columns_fp = popen(columns, "r"); //Same.

// Get the number of lines and columns
if(lns != LINES || cols != COLS){
  lns = LINES;
  cols = COLS;
  x = cols-2;
  y = lns-1;
}
}

void callsystem(){
  directory[0]= cdcom;
  char combinedDir[256];
  snprintf(combinedDir, sizeof(combinedDir), "%s%s", directory[0], directory[1]);
    char lscom[256];
    snprintf(lscom, sizeof(lscom), "ls %s", directory[1]);
  //mvprintw(3,7, "%s", combinedDir);
  system(combinedDir);
  FILE* Readings = popen(lscom, "r");
  if (Readings == NULL) {
    mvprintw(4, 7, "Failed to run command");
    return;
  }

  char buffer[256];
  int index = 0;
  while (fgets(buffer, sizeof(buffer), Readings) != NULL && index < 1000) {
    options[index] = strdup(buffer);
    index++;
  }

  pclose(Readings);
move(3, 13);
  for(int i=0; i < index; i++){
    
    printw("%s  ", options[i]);
  }
  }


void normalappeareance(){
  for(int i= 0; i<x; i++){
    attron(COLOR_PAIR(PAIR3));
    mvprintw(0,i,"-");
  }
  attron(COLOR_PAIR(PAIR1));
  refresh();
  }

void KeyCommands(){

  int getinput = getch(); //Getch gets the input from the keyboard.
  char command[100];
  switch (getinput) { //Cases for different Keys
  case KEY_LEFT:

  if (actualfile > 0) {
    actualfile--;
  }
  break;

  case KEY_RIGHT:
    if (actualfile < quantity - 1) {
      actualfile++;
      }
  break;


  case KEY_UP:
    if (actualfile>= filelayout){
      actualfile-=filelayout;
      }
    break;

  case KEY_DOWN:
    if (actualfile < quantity - filelayout){
      actualfile+=filelayout;
      }
    break;
  }
}

void selection(){


}

#endif
