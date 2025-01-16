#include "librariesreq.h"

#ifndef GLOBALFUNC_C

//constants
#define PAIR1 1
#define PAIR2 2
#define PAIR3 3
//Int Variables
int x, y, quantity, gap, selectedfile=0, actualfile=0, filelayout, cou;
int NumDir= 0;
int c= 0;
//CharStrings 
char* directory[]={"","/home/goose"};
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

void Boxrep(){
    int x2= x/4+1;
    int appdiv= x2/5;

    for(int l=0; l<4; l++){
      move(l+cou+2,x2);
        for(int k= 0; k<appdiv; k++){
            
            printw("   ");
        }
    }
}

void callsystem(){
  directory[0]= cdcom;
  char combinedDir[256];
  snprintf(combinedDir, sizeof(combinedDir), "%s%s", directory[0], directory[1]);
    char lscom[256];
    snprintf(lscom, sizeof(lscom), "ls %s", directory[1]);
  //mvprintw(3,7, "%d", combinedDir);
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
    quantity=index;
  }

  pclose(Readings);
  actualfile=0;
  c=(x/4)+1;
  cou=2; 
  for(int i=0; i < index; i++){
    
    if (i == selectedfile)
    { attron(COLOR_PAIR(PAIR2));}
    else
    { attron(COLOR_PAIR(PAIR1));}
    
    Boxrep();


    if((i%5)==0)
    { cou+=4; c=(x/4)+1;}
    gap=(sizeof(options[i]))/4;

    
    c+= gap;
    mvprintw(cou, c, "%s", options[i]);
    c+= sizeof(options[i])+gap;
  }


  attron(COLOR_PAIR(PAIR1));
  //mvprintw(8,8,"%d", actualfile);
  refresh();
  }

void KeyCommands(){
  int cius= getch();
  switch(cius){
    case KEY_RIGHT:
    if(selectedfile<quantity-1)
    {selectedfile++;}
    break;

    case KEY_LEFT:
    if(selectedfile>0)
    {selectedfile--;}
    break;


  }

}


#endif
