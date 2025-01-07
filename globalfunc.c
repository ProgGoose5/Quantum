#include "librariesreq.h"
#ifndef GLOBALFUNC_C

//constants
#define PAIR1 1
#define PAIR2 2
//Int Variables
int NumDir, x, y;
//CharStrings 
char* directory[];
//Char Variables
char* cdcom= "cd";


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
  x = cols;
  y = lns;
}
}

void callsystem(){
  char SettedDir[256];
  for(int i= 0; i<NumDir; i++){
    snprintf(SettedDir, sizeof(SettedDir), "%s", directory[NumDir]);
    }

  char* error= ("bash: %s No such file or directory", SettedDir);
  char* truedir=  ("bash: %s Is a directory", SettedDir);


  FILE* IsDir = popen(SettedDir, "r");
  char result[256];
  fgets(result, sizeof(result), IsDir);
  if (strcmp(result, error) == 0){
  printw("%s",error);
  pclose(IsDir);
  }
 else if (strcmp(result, truedir) == 0){
 char command[512];
 snprintf(command, sizeof(command), "%s %s", cdcom, SettedDir);
 system(command);
 pclose(IsDir);
 }
}
#endif
