#include "librariesreq.h"

#ifndef GLOBALFUNC_C

//constants
#define PAIR1 1
#define PAIR2 2
#define PAIR3 3
//Int Variables
int x, y, i, quantity, dirbar=2,txright, filedivision=5, ygaps, gap, selectedfile=0, actualfile=0, filelayout, cou;
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

txright= (x/4)*3;

if((round(txright/filedivision))<35 && filedivision>1){
  filedivision--;
}
if((txright/filedivision)>=40){
  filedivision++;
}

if((y/filelayout)<12 && filelayout>1){
  filelayout--;
}
if((y/filelayout)>14){
  filelayout++;
}

int boxesdivisions= 18;
int initboxes= (x/4)+1;
ygaps= round((y/5));

//definition of Fileubs1
Fileubs1.xposition= initboxes;
Fileubs1.yposition= 1+dirbar;
Fileubs1.ylength= 10;
Fileubs1.actualy= 0;
Fileubs1.xlength= boxesdivisions+initboxes;

//definition of Fileubs2
Fileubs2.xposition= Fileubs1.xlength+2;
Fileubs2.yposition= Fileubs1.ylength;
Fileubs2.actualy= 0;
Fileubs2.xlength= boxesdivisions+Fileubs2.xposition;
//definition of Fileubs3
Fileubs3.xposition= Fileubs2.xlength+2;
Fileubs3.yposition= Fileubs2.yposition*2;
Fileubs3.actualy= 0;
Fileubs3.xlength= boxesdivisions+Fileubs3.xposition;

//definition of Fileubs4
Fileubs4.xposition= Fileubs3.xlength + 2;
Fileubs4.yposition= Fileubs2.yposition*3;
Fileubs4.actualy= 0;
Fileubs4.xlength= boxesdivisions+Fileubs4.xposition;

//definition of Fileubs5
Fileubs5.xposition= Fileubs4.xlength + 2;
Fileubs5.yposition= Fileubs2.yposition*4;
Fileubs5.actualy= 0;
Fileubs5.xlength= boxesdivisions+Fileubs5.xposition;


}
void Boxrep(){
  
  for(int G= 1; G<=5; G++){

  
    for(int L=Fileubs1.yposition; L<=Fileubs1.ylength; L++){
     
    
      for(int O=(Fileubs1.xposition); O<(Fileubs1.xlength); O++)
      {
        mvprintw(L, O, "1");
        if(filelayout>=2){
        mvprintw(L+(Fileubs2.yposition),O, "2"); }
        if(filelayout>=3){
        mvprintw(L+(Fileubs3.yposition),O, "3"); }
        if(filelayout>=4){
        mvprintw(L+(Fileubs4.yposition),O, "4"); }
        if(filelayout>=5){
        mvprintw(L+(Fileubs5.yposition),O, "5"); }
      } 
    if(filedivision>=2){
      for(int O=(Fileubs2.xposition); O<(Fileubs2.xlength); O++)
      {
        mvprintw(L, O, "6");
        if(filelayout>=2){
        mvprintw(L+(Fileubs2.yposition),O, "7"); }
        if(filelayout>=3){
        mvprintw(L+(Fileubs3.yposition),O, "8"); }
        if(filelayout>=4){
        mvprintw(L+(Fileubs4.yposition),O, "9"); }
        if(filelayout>=5){
        mvprintw(L+(Fileubs5.yposition),O, "a"); }
      } }

          if(filedivision>=3){
      for(int O=(Fileubs3.xposition); O<(Fileubs3.xlength); O++)
      {
        mvprintw(L, O, "b");
        if(filelayout>=2){
        mvprintw(L+(Fileubs2.yposition),O, "c"); }
        if(filelayout>=3){
        mvprintw(L+(Fileubs3.yposition),O, "d"); }
        if(filelayout>=4){
        mvprintw(L+(Fileubs4.yposition),O, "e"); }
        if(filelayout>=5){
        mvprintw(L+(Fileubs5.yposition),O, "f"); }
      } }

                if(filedivision>=4){
      for(int O=(Fileubs4.xposition); O<(Fileubs4.xlength); O++)
      {
        mvprintw(L, O, "b");
        if(filelayout>=2){
        mvprintw(L+(Fileubs2.yposition),O, "g"); }
        if(filelayout>=3){
        mvprintw(L+(Fileubs3.yposition),O, "h"); }
        if(filelayout>=4){
        mvprintw(L+(Fileubs4.yposition),O, "i"); }
        if(filelayout>=5){
        mvprintw(L+(Fileubs5.yposition),O, "o"); }
      } }

if(filedivision>=5){
      for(int O=(Fileubs5.xposition); O<(Fileubs5.xlength); O++)
      {
        mvprintw(L, O, "p");
        if(filelayout>=2){
        mvprintw(L+(Fileubs2.yposition),O, "q"); }
        if(filelayout>=3){
        mvprintw(L+(Fileubs3.yposition),O, "r"); }
        if(filelayout>=4){
        mvprintw(L+(Fileubs4.yposition),O, "s"); }
        if(filelayout>=5){
        mvprintw(L+(Fileubs5.yposition),O, "t"); }
      } }
      //When there's more fors... i must add an IF to
      //call the verification of filedivision
      
    }
  


} }

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
   Boxrep();

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
