#include "librariesreq.h"

#ifndef GLOBALFUNC_C

//constants
#define PAIR1 1
#define PAIR2 2
#define PAIR3 3
//Int Variables
int x, y, i, quantity, gap, selectedfile=0, actualfile=0, filelayout, cou;
int NumDir= 0;
int c= 0;
//CharStrings 
char* directory[]={"","/home/goose"};
//Char Variables
char* cdcom= "cd ";
char* options[1000] = {" "};

struct Fileubs
{
  int xposition, yposition, xlength, ylength, actualy;
}Fileubs1,Fileubs2,Fileubs3,Fileubs4,Fileubs5;


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
void boxesdef() {

int txright= (x/4)*3;
int boxesdivisions= txright/5;
int initboxes= 29;
//definition of Fileubs1
Fileubs1.xposition= initboxes;
Fileubs1.yposition= 1;
Fileubs1.ylength= y/5;
Fileubs1.actualy= 0;
Fileubs1.xlength= boxesdivisions;

//definition of Fileubs2
Fileubs2.xposition= ((x/4)/5) + ((x/4)/5);
Fileubs2.yposition= y/5;
Fileubs2.actualy= 0;
Fileubs2.xlength= (int)strlen(options[Fileubs2.actualy]);

//definition of Fileubs3
Fileubs3.xposition= (Fileubs2.xposition) + ((x/4)/5);
Fileubs3.yposition= y/5;
Fileubs3.actualy= 0;
Fileubs3.xlength= (int)strlen(options[Fileubs3.actualy]);

//definition of Fileubs4
Fileubs4.xposition= (Fileubs3.xposition) + ((x/4)/5);
Fileubs4.yposition= y/5;
Fileubs4.actualy= 0;
Fileubs4.xlength= (int)strlen(options[Fileubs4.actualy]);

//definition of Fileubs5
Fileubs5.xposition= (Fileubs4.xposition) + ((x/4)/5);
Fileubs5.yposition= y/5;
Fileubs5.actualy= 0;
Fileubs5.xlength= (int)strlen(options[Fileubs5.actualy]);


}
void Boxrep(){
  for(int G= 0; G<5; G++){
    for(int L=Fileubs1.yposition; L<=Fileubs1.ylength; L++){
      if(actualfile==i){
        attron(COLOR_PAIR(PAIR2));
      }
      else{
        attron(COLOR_PAIR(PAIR1));
      }
      for(int O=(Fileubs1.xposition); O<(Fileubs1.xlength+29); O++)
      {
        mvprintw(L, O, " ");
      }  
      
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
  for(i=0; i < index; i++){
    
    if (i == selectedfile)
    { attron(COLOR_PAIR(PAIR2));}
    else
    { attron(COLOR_PAIR(PAIR1));}
   

    if((i%5)==0)
    { cou+=4; c=(x/4)+1;}
    gap=5;

    //c+= gap;
    mvprintw(cou, c, "%s", options[i]);
    c+= strlen(options[i])+gap;
  }


  attron(COLOR_PAIR(PAIR1));
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

}


#endif
