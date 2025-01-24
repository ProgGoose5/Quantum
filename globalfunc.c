#include "librariesreq.h"

#ifndef GLOBALFUNC_C

//constants
#define PAIR1 1
#define PAIR2 2
#define PAIR3 3
//Int Variables
int x, y; //Screen position variables
int i, f=1, t=1, Q=0; //Used to operate with fors and other things
int quantity, page, actualpage=0, dbfilesperpage=0, filesperpage;
int dirbar=2; //The space that occupies the directory bar
int txright, filedivision=5,  filelayout=5; //Useful for the Boxes
int cou; 
int ygaps, gap;
int selectedfile=0, actualfile=0; //Both for selecting files, but idk why i have two.
int NumDir= 0;
int verification=0;
int invertedcordinates= 0;
int borderx, bordery, borderval, boxesdivisions, initboxes, realxubication, realyubication=0;
//CharStrings 
char* directory[]={"","/home/goose/examplefolder"};
//Char Variables
char* cdcom= "cd ";
char* options[1000] = {" "};
char *boxChar = " ";

bool g=FALSE;

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

//The definitions of various boxes
void boxesdef() {

txright= (x/4)*3;

if((round(txright/filedivision))<20 && filedivision>1){
  filedivision--;
}
if((txright/filedivision)>=26 && filedivision<5){
  filedivision++;
}

if((y/filelayout)<12 && filelayout>1){
  filelayout--;
}

if((y/filelayout)>12 && filelayout<5){

  filelayout++;
}
 boxesdivisions= 18;
initboxes= (x/4)+1;
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

//The functionality of the boxes (Not mistake with rep)
void boxesfunction(){
  
  borderval=1;
  borderx=((boxesdivisions-(borderval*2))-sizeof(options[i]));
  int files= i+1;

  switch (f)
  {
  case 1:
    realxubication= Fileubs1.xposition+(borderx/2);
    break;
  
  case 2:
    realxubication= Fileubs2.xposition+(borderx/2);
    break;

  case 3: 
    realxubication= Fileubs3.xposition+(borderx/2);
    break;

  case 4:
    realxubication= Fileubs4.xposition+(borderx/2);
    break;

  case 5:
    realxubication= Fileubs5.xposition+(borderx/2);
    break;
  }

  switch(t){

    case 5:
    realyubication= 46+cou; //5
    break;

    case 1:
    realyubication= 7+cou; //1
    break;

    case 2:
    realyubication= 17+cou; //2
    break;

    case 3:
    realyubication= 27+cou; //3
    break;

    case 4:
    realyubication= 37+cou; //4
    break;

    default: 
    g=true;

  }
  if((files%filedivision)==0){
  f=1; t++;
}

else{f++;}

//for(Q=0; Q<(quantity/filelayout); Q++){}

}

//Made for executing upon every box printed.
void verify(){

  mvprintw(1,1,"dbfiles %d", dbfilesperpage);
  mvprintw(2,1,"quantity %d", quantity);
  mvprintw(3,1,"fppage %d", filesperpage);
  mvprintw(4,1,"selectedfile %d", selectedfile);

  mvprintw(5,1, "Pages %d/%d",actualpage, page);
if(verification==selectedfile){
  attron(COLOR_PAIR(PAIR2));
  verification++;
}
else{
  attron(COLOR_PAIR(PAIR1));
  verification++;
}

}

//The printing of each box.
void Boxrep(){
  
  for(int G= 1; G<=5; G++){
  
  
    for(int L=Fileubs1.yposition; L<=Fileubs1.ylength; L++){
     
    
      for(int O=(Fileubs1.xposition); O<(Fileubs1.xlength); O++)
      { verification=0;
        verify();

        mvprintw(L, O, "%s", boxChar);
        if(filelayout>=2){
          verify();
          mvprintw(L+(Fileubs2.yposition),O, "%s", boxChar); }
        if(filelayout>=3){
          verify();
          mvprintw(L+(Fileubs3.yposition),O, "%s", boxChar); }
        if(filelayout>=4){
          verify();
          mvprintw(L+(Fileubs4.yposition),O, "%s", boxChar); }
        if(filelayout>=5){
          verify();
          mvprintw(L+(Fileubs5.yposition),O, "%s", boxChar); }

      } 
    if(filedivision>=2){
      for(int O=(Fileubs2.xposition); O<(Fileubs2.xlength); O++)
      { verification=filelayout;
        verify();

        mvprintw(L, O, "%s", boxChar);
        if(filelayout>=2 ){
          verify();
        mvprintw(L+(Fileubs2.yposition),O, "%s", boxChar); }
        if(filelayout>=3){
          verify();
          mvprintw(L+(Fileubs3.yposition),O, "%s", boxChar); }
        if(filelayout>=4 ){
          verify();
          mvprintw(L+(Fileubs4.yposition),O, "%s", boxChar); }
        if(filelayout>=5 ){
          verify();
          mvprintw(L+(Fileubs5.yposition),O, "%s", boxChar); }

      } }

    if(filedivision>=3){
      for(int O=(Fileubs3.xposition); O<(Fileubs3.xlength); O++)
      { verification=filelayout*2;
        verify();

        mvprintw(L, O, "%s", boxChar);
        if(filelayout>=2){
        verify();
        mvprintw(L+(Fileubs2.yposition),O, "%s", boxChar); }
        if(filelayout>=3 ){
        verify();
        mvprintw(L+(Fileubs3.yposition),O, "%s", boxChar); }
        if(filelayout>=4 ){
        verify();
        mvprintw(L+(Fileubs4.yposition),O, "%s", boxChar); }
        if(filelayout>=5 ){
        verify();
        mvprintw(L+(Fileubs5.yposition),O, "%s", boxChar); }

      } }

    if(filedivision>=4 ){
      for(int O=(Fileubs4.xposition); O<(Fileubs4.xlength); O++)
      { verification=filelayout*3;
        verify();

        mvprintw(L, O, "%s", boxChar);
        if(filelayout>=2){
        verify();
        mvprintw(L+(Fileubs2.yposition),O, "%s", boxChar); }
        if(filelayout>=3 ){
        verify();
        mvprintw(L+(Fileubs3.yposition),O, "%s", boxChar); }
        if(filelayout>=4 ){
        verify();
        mvprintw(L+(Fileubs4.yposition),O, "%s", boxChar); }
        if(filelayout>=5 ){
        verify();
        mvprintw(L+(Fileubs5.yposition),O, "%s", boxChar); }

      } }

  if(filedivision>=5){
      for(int O=(Fileubs5.xposition); O<(Fileubs5.xlength); O++)
      { verification=20;
        verify();

        mvprintw(L, O, "%s", boxChar);
        if(filelayout>=2){
        verify();
        mvprintw(L+(Fileubs2.yposition),O, "%s", boxChar); }
        if(filelayout>=3 ){
        verify();
        mvprintw(L+(Fileubs3.yposition),O, "%s", boxChar); }
        if(filelayout>=4 ){
        verify();
        mvprintw(L+(Fileubs4.yposition),O, "%s", boxChar); }
        if(filelayout>=5 ){
        verify();
        mvprintw(L+(Fileubs5.yposition),O, "%s", boxChar); }

      } }
      //When there's more fors... i must add an IF to
      //call the verification of filedivision
      
    }
  


} }

//System and apps representation function.
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

  filesperpage= (filedivision*filelayout)*actualpage;
  dbfilesperpage= (filedivision*filelayout)*(actualpage+1);

  if((dbfilesperpage-quantity)>0){dbfilesperpage-=(dbfilesperpage-quantity);}
    for(page=0; page<((index/(filedivision*filelayout))-1); page++){

  }

  actualfile=0;
  cou=1; 
      t=1;
      f=1; 
  for(i=(0+filesperpage); i < dbfilesperpage; i++){  
    quantity=index;   
    boxesfunction();
  
    //if (g=TRUE){i=0;}

  if(selectedfile==0){invertedcordinates=0;}

 if (i == (invertedcordinates+filesperpage))

    { attron(COLOR_PAIR(PAIR2));}
  else
    { attron(COLOR_PAIR(PAIR1));}
  

  if (sizeof(options[i])>16){
    
    char Printylonger[128];
    snprintf(Printylonger, sizeof(Printylonger), "%s", options[i]);
    for(int p= 0; Printylonger[p]!='\0'; p++){
    mvprintw(realyubication, realxubication, "%s", Printylonger[p]);
      if((p%16)==0){cou++;}
                }
                }

  else{
    char Printy[16];
    snprintf(Printy, sizeof(Printy), "%s", options[i]);
    for (int j = 0; Printy[j] != '\0'; j++) {
        if (isalpha(Printy[j])) {
            mvprintw(realyubication, realxubication + j, "%c", Printy[j]);
            
            }
        }
    }
    
  
  }

    //c+= gap;
    //mvprintw(cou, c, "%s", options[i]);
    //c+= strlen(options[i])+gap;
  


  attron(COLOR_PAIR(PAIR1));
  refresh();
  }

//Keyboard reading.
void KeyCommands(){
  int cius= getch();
  switch(cius){
    case KEY_RIGHT:

    if((invertedcordinates+1+filesperpage) < dbfilesperpage){
    if(selectedfile<((filelayout*filedivision)-filelayout))
    {selectedfile+=filelayout; invertedcordinates++;}}
    else if (actualpage<page){actualpage++; selectedfile=0; invertedcordinates=0;}

    break;

    case KEY_LEFT:
    if(selectedfile>=filelayout)
    {selectedfile-=filelayout; invertedcordinates--;}
    else if(actualpage>0){actualpage--; selectedfile=0; invertedcordinates=0;} 

    break;

    case KEY_UP:
      if(((selectedfile)%(filelayout))!= 0 || selectedfile==0){
      if(selectedfile>0)
      {selectedfile--; invertedcordinates-=(filedivision);}}

      else if(actualpage>0){actualpage--; selectedfile=0; invertedcordinates=0;}
      break;

    case KEY_DOWN:
    if(((invertedcordinates+1)+filedivision+filesperpage) <= dbfilesperpage && (invertedcordinates+filesperpage+1) <= dbfilesperpage){

    if(((selectedfile+1)%(filelayout))!= 0 || selectedfile==0){
    if(selectedfile<(filelayout*filedivision)-1){
    selectedfile++; invertedcordinates+=(filedivision);
    }}}

    else if(actualpage<page){actualpage++; selectedfile=0; invertedcordinates=0;}

    break;

    case KEY_F(1):
    if(actualpage>0) {actualpage--;}
    break;

    case KEY_F(2):
    if(actualpage<page) {actualpage++;}
    break;
  }




}

//Refresher of variable values.
void alwaysrefresh(){
filesperpage= (filedivision*filelayout)*actualpage;
dbfilesperpage= (filedivision*filelayout)*(actualpage+1);
page= (quantity/(filedivision*filelayout));

  if((dbfilesperpage-quantity)>0){dbfilesperpage-=(dbfilesperpage-quantity);}
}

#endif

